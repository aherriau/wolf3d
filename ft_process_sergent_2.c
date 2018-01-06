/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_sergent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:03:47 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 23:34:23 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_look_for_player_sergent_1_3(t_env *e, t_enemy *this, t_movement *m)
{
	if ((e->map.data[m->map_x = (int)m->new_x]
				[(int)(this->sprite->pos.y)].wall == 50 ||
				e->map.data[(int)(this->sprite->pos.x)]
				[m->map_y = (int)m->new_y].wall == 50))
	{
		if (e->map.data[m->map_x = (int)m->new_x]
				[(int)(this->sprite->pos.y)].door_state == 0)
			e->map.data[m->map_x]
					[(int)(this->sprite->pos.y)].door_state = 1;
		if (e->map.data[(int)(this->sprite->pos.x)]
				[m->map_y = (int)m->new_y].door_state == 0)
			e->map.data[(int)(this->sprite->pos.x)]
					[m->map_y = (int)m->new_y].door_state = 1;
	}
	if (!m->move || this->sprite->animation_index == 4)
		this->sprite->animation_index = 0;
}

void	ft_look_for_player_sergent_1(t_env *e, t_enemy *this, t_movement *m)
{
	ft_look_ser_1_1(e, this, m);
	ft_look_ser_1_2(e, this, m);
	ft_look_for_player_sergent_1_3(e, this, m);
	if (m->move)
	{
		this->sprite->animation_index =
			(this->sprite->animation_index + 1) % this->move_frames;
		if (!(m->tmp = ft_lstnew_ptr((void *)
			(new_xy(this->sprite->pos.x, this->sprite->pos.y)), sizeof(t_xy))))
			ft_error("malloc error");
		ft_lstadd(&(this->pos_stack), m->tmp);
	}
}

void	ft_look_for_player_sergent(t_env *e, t_enemy *this)
{
	t_movement m;

	this->sprite->dir.x = this->sprite->last_pos_seen.x - this->sprite->pos.x;
	this->sprite->dir.y = this->sprite->last_pos_seen.y - this->sprite->pos.y;
	m.norme = sqrt(pow(this->sprite->dir.x, 2) + pow(this->sprite->dir.y, 2));
	if (m.norme != 0)
	{
		this->sprite->dir.x /= m.norme;
		this->sprite->dir.y /= m.norme;
	}
	this->sprite->plane.x = -this->sprite->dir.y;
	this->sprite->plane.y = this->sprite->dir.x;
	if (fabs(this->sprite->pos.x - this->sprite->last_pos_seen.x)
			< this->speed_walk && fabs(this->sprite->pos.y -
				this->sprite->last_pos_seen.y) < this->speed_walk)
	{
		this->sprite->last_pos_seen.x = -1;
		this->sprite->last_pos_seen.y = -1;
		this->sprite->state = GOBACK;
	}
	else if (this->sprite->fast_index == 0)
		ft_look_for_player_sergent_1(e, this, &m);
	this->sprite->fast_index = (this->sprite->fast_index + 1) % 7;
}

void	ft_process_movement_sergent(t_env *e, t_enemy *this)
{
	if (ft_can_see_player(e, this))
		ft_process_can_see_player_sergent(e, this);
	else if (this->sprite->last_pos_seen.x != -1
			&& this->sprite->last_pos_seen.y != -1)
		ft_look_for_player_sergent(e, this);
	else if (dist_player(*this, e) < this->ear_length)
		ft_look_toward_player(e, this);
}

void	ft_go_back_sergent_1(t_env *e, t_xy next_pos)
{
	if (e->map.data[(int)next_pos.x]
			[(int)next_pos.y].door_state == 0)
		e->map.data[(int)next_pos.x]
				[(int)next_pos.y].door_state = 1;
}
