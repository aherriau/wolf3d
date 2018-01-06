/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_hitler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 20:28:11 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 20:17:25 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_hitler_attack_1(t_env *e, t_enemy *this)
{
	if (this->sprite->fast_index_2 == 0)
	{
		if (this->sprite->state == MOVE)
		{
			this->sprite->state = ATTACK;
			this->sprite->animation_index = 4 + 10 * (this->phase - 1);
		}
		else
		{
			if (this->sprite->animation_index == 6 + 10 * (this->phase - 1))
			{
				this->sprite->animation_index = 4 + 10 * (this->phase - 1);
				ft_play_sound(e, 17);
				ft_hurt_player(e, this);
			}
			else
				this->sprite->animation_index++;
		}
	}
	this->sprite->fast_index_2 = (this->sprite->fast_index_2 + 1) % (2);
}

int		ft_hitler_attack(t_env *e, t_enemy *this)
{
	if (dist_player(*this, e) < this->range * 1.5
			&& ft_can_see_player(e, this))
		ft_hitler_attack_1(e, this);
	else
	{
		this->sprite->animation_index = 10 * (this->phase - 1);
		this->sprite->state = MOVE;
	}
	return (0);
}

int		ft_process_hitler_1(t_env *e, t_enemy *this)
{
	ft_look_toward_player(e, this);
	if (this->dead && this->sprite->animation_index ==
			this->index_die + this->die_count)
		return (1);
	if (!this->dead && this->health <= 0)
	{
		this->dead = 1;
		this->sprite->state = DIE;
		this->sprite->animation_index = this->index_die;
		ft_play_sound(e, this->index_death1);
	}
	if (ft_can_see_player(e, this) && !this->triggered)
	{
		this->triggered = 1;
		ft_play_sound(e, 34);
	}
	if (this->phase != 2 && this->health <= P2_HEALTH &&
			this->sprite->state != TRANSFORM)
	{
		this->sprite->state = TRANSFORM;
		this->sprite->animation_index = 7;
		ft_play_sound(e, 37);
	}
	return (0);
}

void	ft_process_hitler_2(t_env *e, t_enemy *this)
{
	if (!this->dead && this->sprite->state == MOVE)
		ft_process_movement_hitler(e, this);
	if (!this->dead && this->sprite->state == ATTACK)
		this->attack(e, this);
	if (this->sprite->state == TRANSFORM &&
			this->sprite->animation_index < 10)
	{
		if (this->sprite->fast_index == 0)
		{
			if (++this->sprite->animation_index == 10)
			{
				this->sprite->state = MOVE;
				this->phase = 2;
				this->speed_walk = 0.6;
			}
		}
		this->sprite->fast_index = (this->sprite->fast_index + 1) % 5;
	}
}

int		ft_process_hitler(t_env *e, t_enemy *this)
{
	if (ft_process_hitler_1(e, this))
		return (0);
	ft_process_hitler_2(e, this);
	if (this->sprite->state == DIE && this->sprite->animation_index
			< this->index_die + this->die_count)
	{
		this->sprite->fast_index = (this->sprite->fast_index + 1) % 3;
		if (this->sprite->fast_index == 0)
		{
			if (++this->sprite->animation_index ==
					this->index_die + this->die_count)
			{
				e->player.win = 1;
				ft_drop_item(e, this);
			}
		}
	}
	return (1);
}
