/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_vodoo_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:32:07 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 20:32:08 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_process_can_see_vodoo(t_env *e, t_enemy *this, t_movement *m)
{
	m->new_x = this->sprite->pos.x + e->player.s_width *
		(this->sprite->dir.x > 0 ? 1 : -1) +
			this->sprite->dir.x * this->speed_walk;
	if (e->map.data[m->map_x = (int)m->new_x][(int)(this->sprite->pos.y)].
			wall <= 0 && e->map.data[m->map_x][(int)(this->sprite->pos.y)].
				item <= BLOCK_SPRITE_INDEX)
	{
		if (ft_no_enemy_beside(e, this, m->new_x, this->sprite->pos.y))
		{
			this->sprite->pos.x += this->sprite->dir.x * this->speed_walk;
			m->move = 1;
		}
	}
}

void	ft_process_can_see_player_vodoo(t_env *e, t_enemy *this)
{
	t_movement m;

	if (dist_player(*this, e) > this->range && ft_can_see_player(e, this))
	{
		ft_process_can_see_vodoo(e, this, &m);
		m.new_y = this->sprite->pos.y + e->player.s_width *
			(this->sprite->dir.y > 0 ? 1 : -1) +
				this->sprite->dir.y * this->speed_walk;
		if (e->map.data[(int)(this->sprite->pos.x)][m.map_y = (int)m.new_y].
			wall <= 0 && e->map.data[(int)(this->sprite->pos.x)][m.map_y].
				item <= BLOCK_SPRITE_INDEX)
		{
			if (ft_no_enemy_beside(e, this, this->sprite->pos.x, m.new_y))
			{
				this->sprite->pos.y += this->sprite->dir.y * this->speed_walk;
				m.move = 1;
			}
		}
	}
	else
		this->sprite->state = ATTACK;
}

void	ft_process_movement_vodoo(t_env *e, t_enemy *this)
{
	ft_process_can_see_player_vodoo(e, this);
	if (this->sprite->fast_index % 5 == 0)
	{
		this->sprite->animation_index =
			(this->sprite->animation_index + 1) % 4;
	}
	this->sprite->fast_index = (this->sprite->fast_index + 1) % 5;
}
