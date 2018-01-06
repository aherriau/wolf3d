/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_hitler_vodoo.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:22:50 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 20:32:29 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	add_proj_vodoo(t_env *e, t_enemy *this)
{
	t_projectile	*proj;
	t_list			*tmp;

	proj = new_ball(e, this);
	if (!(tmp = ft_lstnew_ptr((void *)proj, sizeof(t_projectile))))
		ft_error("malloc error");
	ft_lstadd(&(e->map.projectiles), tmp);
}

void	ft_vodoo_attack_1(t_env *e, t_enemy *this)
{
	if (this->sprite->fast_index_2 == 0)
	{
		if (this->sprite->state == MOVE)
		{
			this->sprite->state = ATTACK;
			this->sprite->animation_index = 0;
		}
		else
		{
			if (this->sprite->animation_index == 0)
			{
				this->sprite->animation_index = 4;
				ft_play_sound(e, 33);
				add_proj_vodoo(e, this);
			}
			else
				this->sprite->animation_index = 0;
		}
	}
	this->sprite->fast_index_2 = (this->sprite->fast_index_2 + 1) % (2);
}

int		ft_vodoo_attack(t_env *e, t_enemy *this)
{
	if (dist_player(*this, e) < this->range && ft_can_see_player(e, this))
		ft_vodoo_attack_1(e, this);
	else
	{
		this->sprite->animation_index = 0;
		this->sprite->state = MOVE;
	}
	return (0);
}

int		ft_process_vodoo_1(t_env *e, t_enemy *this)
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
	if (!this->dead && this->sprite->state == MOVE)
		ft_process_movement_vodoo(e, this);
	return (0);
}

int		ft_process_vodoo(t_env *e, t_enemy *this)
{
	if (ft_process_vodoo_1(e, this))
		return (0);
	if (!this->dead && this->sprite->state == ATTACK)
		this->attack(e, this);
	if (this->sprite->state == DIE && this->sprite->animation_index <
		this->index_die + this->die_count)
	{
		this->sprite->fast_index = (this->sprite->fast_index + 1) % 2;
		if (this->sprite->fast_index == 0)
		{
			if (++this->sprite->animation_index ==
					this->index_die + this->die_count)
			{
				ft_drop_item(e, this);
				e->player.kill_vodoo = 1;
			}
		}
	}
	return (1);
}
