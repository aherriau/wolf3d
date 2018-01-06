/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_sergent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:03:47 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 21:34:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_process_sergent_2(t_env *e, t_enemy *this)
{
	if ((fabs(this->sprite->pos.x - e->player.pos.x) > this->range ||
				fabs(this->sprite->pos.y - e->player.pos.y) > this->range) &&
			this->sprite->state == ATTACK)
		this->sprite->state = MOVE;
	if (!this->dead && this->sprite->state == MOVE)
		ft_process_movement_sergent(e, this);
	if (this->dead && this->sprite->animation_index <
			this->index_die + this->die_count)
	{
		this->sprite->fast_index =
			(this->sprite->fast_index + 1) % (6 - this->die_count);
		if (this->sprite->fast_index == 0)
		{
			if (++this->sprite->animation_index ==
					this->index_die + this->die_count)
				ft_drop_item(e, this);
		}
	}
}

int		ft_process_sergent(t_env *e, t_enemy *this)
{
	if (ft_process_sergent_1(e, this))
		return (0);
	ft_process_sergent_2(e, this);
	if (this->health <= 0 && !this->dead)
	{
		this->dead = 1;
		this->sprite->state = DIE;
		ft_play_sound(e, this->index_death1);
		this->sprite->animation_index = this->index_die;
	}
	if (this->sprite->state == ATTACK)
		ft_sergent_attack(e, this);
	return (0);
}
