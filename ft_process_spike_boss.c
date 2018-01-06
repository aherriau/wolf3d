/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spike_boss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:10:00 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 22:08:32 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_spike_boss_attack(t_env *e, t_enemy *this)
{
	if (this->sprite->fast_index == 0)
	{
		if (this->sprite->state == MOVE || this->sprite->state == HURT)
		{
			this->sprite->state = ATTACK;
			this->sprite->animation_index = 4;
		}
		else if (this->sprite->animation_index == 5)
		{
			this->sprite->animation_index = 6;
			ft_play_sound(e, 17);
			ft_hurt_player(e, this);
		}
		else
			this->sprite->animation_index = 5;
	}
	this->sprite->fast_index = (this->sprite->fast_index + 1) % 2;
	return (0);
}

void	ft_process_movement_boss_spike(t_env *e, t_enemy *this)
{
	if (this->sprite->state == ATTACK)
		this->sprite->animation_index = 0;
	if (e->map.data[(int)((this->sprite->pos.x +
			(this->side * 0.5) + (this->side * 0.05)))]
			[(int)this->sprite->pos.y].wall == 0)
		this->sprite->pos.x += this->side * 0.05;
	else
		this->side = -this->side;
	if (++this->sprite->fast_index % 5 == 0)
	{
		this->sprite->animation_index = (this->sprite->animation_index + 1) % 4;
	}
}

int		ft_process_boss_spike_1(t_env *e, t_enemy *this)
{
	ft_look_toward_player(e, this);
	if (this->dead && this->sprite->animation_index == 10)
		return (1);
	if (!this->dead && this->health <= 0)
	{
		this->dead = 1;
		this->sprite->state = DIE;
		this->sprite->animation_index = 5;
	}
	return (0);
}

void	ft_process_boss_spike_2(t_env *e, t_enemy *this)
{
	if (!this->dead && ft_can_see_player(e, this))
	{
		if (!this->triggered)
		{
			ft_play_sound(e, this->index_halt);
			this->triggered = 1;
		}
		this->attack(e, this);
	}
	else
	{
		if (!this->dead)
		{
			ft_process_movement_boss_spike(e, this);
			this->sprite->state = MOVE;
		}
	}
}

int		ft_process_boss_spike(t_env *e, t_enemy *this)
{
	if (ft_process_boss_spike_1(e, this))
		return (0);
	ft_process_boss_spike_2(e, this);
	if (this->sprite->state == DIE && this->sprite->animation_index < 10)
	{
		this->sprite->fast_index = (this->sprite->fast_index + 1) % 2;
		if (this->sprite->fast_index == 0)
		{
			if (++this->sprite->animation_index == 10)
				ft_drop_item(e, this);
		}
	}
	return (1);
}
