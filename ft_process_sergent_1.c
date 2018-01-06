/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_sergent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:03:47 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 23:34:41 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_process_can_see_sergent_1(t_env *e, t_enemy *this, t_movement *m)
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

void	ft_process_can_see_sergent_2(t_env *e, t_enemy *this, t_movement *m)
{
	ft_process_can_see_sergent_1(e, this, m);
	m->new_y = this->sprite->pos.y + e->player.s_width *
		(this->sprite->dir.y > 0 ? 1 : -1) +
		this->sprite->dir.y * this->speed_walk;
	if (e->map.data[(int)(this->sprite->pos.x)][m->map_y = (int)m->new_y].
			wall <= 0 && e->map.data[(int)(this->sprite->pos.x)][m->map_y].
			item <= BLOCK_SPRITE_INDEX)
	{
		if (ft_no_enemy_beside(e, this, this->sprite->pos.x, m->new_y))
		{
			this->sprite->pos.y += this->sprite->dir.y * this->speed_walk;
			m->move = 1;
		}
	}
	if (!m->move || this->sprite->animation_index == 4)
		this->sprite->animation_index = 0;
}

void	ft_process_can_see_player_sergent(t_env *e, t_enemy *this)
{
	t_movement m;

	if (this->sprite->fast_index == 0)
	{
		if (fabs(this->sprite->pos.x - e->player.pos.x) > this->range ||
				fabs(this->sprite->pos.y - e->player.pos.y) > this->range)
		{
			ft_process_can_see_sergent_2(e, this, &m);
			if (m.move)
			{
				this->sprite->animation_index =
					(this->sprite->animation_index + 1) % this->move_frames;
				if (!(m.tmp = ft_lstnew_ptr((void *)
			(new_xy(this->sprite->pos.x, this->sprite->pos.y)), sizeof(t_xy))))
					ft_error("malloc error");
				ft_lstadd(&(this->pos_stack), m.tmp);
			}
		}
		else
		{
			this->sprite->animation_index = 0;
			this->sprite->state = ATTACK;
		}
	}
	this->sprite->fast_index = (this->sprite->fast_index + 1) % 7;
}

void	ft_look_ser_1_1(t_env *e, t_enemy *this, t_movement *m)
{
	m->new_x = this->sprite->pos.x + e->player.s_width *
		(this->sprite->dir.x > 0 ? 1 : -1) +
		this->sprite->dir.x * this->speed_walk;
	if (e->map.data[m->map_x = (int)m->new_x]
			[(int)(this->sprite->pos.y)].wall <= 0)
	{
		if (e->map.data[m->map_x][(int)(this->sprite->pos.y)]
				.item <= BLOCK_SPRITE_INDEX)
		{
			if (ft_no_enemy_beside(e, this, m->new_x, this->sprite->pos.y))
			{
				this->sprite->pos.x +=
					this->sprite->dir.x * this->speed_walk;
				m->move = 1;
			}
		}
	}
}

void	ft_look_ser_1_2(t_env *e, t_enemy *this, t_movement *m)
{
	m->new_y = this->sprite->pos.y + e->player.s_width *
		(this->sprite->dir.y > 0 ? 1 : -1) +
			this->sprite->dir.y * this->speed_walk;
	if (e->map.data[(int)(this->sprite->pos.x)][m->map_y = (int)m->new_y].
		wall <= 0)
	{
		if (e->map.data[(int)(this->sprite->pos.x)][m->map_y].
			item <= BLOCK_SPRITE_INDEX)
		{
			if (ft_no_enemy_beside(e, this, this->sprite->pos.x, m->new_y))
			{
				this->sprite->pos.y += this->sprite->dir.y * this->speed_walk;
				m->move = 1;
			}
		}
	}
}
