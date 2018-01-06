/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_enemy_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:18:05 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 02:28:29 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_can_see_player_1(t_env *e, t_enemy *this)
{
	e->raycast.ray_pos.x = this->sprite->pos.x;
	e->raycast.ray_pos.y = this->sprite->pos.y;
	e->raycast.ray_dir.x = this->sprite->dir.x + this->sprite->plane.x *
		e->raycast.camera_x;
	e->raycast.ray_dir.y = this->sprite->dir.y + this->sprite->plane.y *
		e->raycast.camera_x;
	e->raycast.map_x = (int)(e->raycast.ray_pos.x);
	e->raycast.map_y = (int)(e->raycast.ray_pos.y);
	e->raycast.delta_dist.x = sqrt(1 + (e->raycast.ray_dir.y *
		e->raycast.ray_dir.y) / (e->raycast.ray_dir.x * e->raycast.ray_dir.x));
	e->raycast.delta_dist.y = sqrt(1 + (e->raycast.ray_dir.x *
		e->raycast.ray_dir.x) / (e->raycast.ray_dir.y * e->raycast.ray_dir.y));
	e->raycast.hit = 0;
	e->raycast.door = 0;
	e->raycast.door_timer = 0;
	e->raycast.door_dist = 0;
	e->raycast.secret_door = 0;
}

void	ft_can_see_player_2(t_env *e)
{
	if (e->raycast.ray_dir.x < 0)
	{
		e->raycast.step_x = -1;
		e->raycast.side_dist.x = (e->raycast.ray_pos.x - e->raycast.map_x) *
			e->raycast.delta_dist.x;
	}
	else
	{
		e->raycast.step_x = 1;
		e->raycast.side_dist.x = (e->raycast.map_x + 1.0 - e->raycast.ray_pos.x)
			* e->raycast.delta_dist.x;
	}
	if (e->raycast.ray_dir.y < 0)
	{
		e->raycast.step_y = -1;
		e->raycast.side_dist.y = (e->raycast.ray_pos.y - e->raycast.map_y) *
			e->raycast.delta_dist.y;
	}
	else
	{
		e->raycast.step_y = 1;
		e->raycast.side_dist.y = (e->raycast.map_y + 1.0 - e->raycast.ray_pos.y)
			* e->raycast.delta_dist.y;
	}
}

void	ft_can_see_player_3_1_1(t_env *e, t_enemy *this)
{
	e->raycast.door_timer = e->map.data[e->raycast.map_x]
		[e->raycast.map_y].door_timer;
	if (e->raycast.side == 0)
	{
		if (this->sprite->pos.x < e->raycast.map_x)
			e->raycast.door_dist = 0.5;
		else
			e->raycast.door_dist = -0.5;
	}
	else
	{
		if (this->sprite->pos.y < e->raycast.map_y)
			e->raycast.door_dist = 0.5;
		else
			e->raycast.door_dist = -0.5;
	}
	if (e->raycast.side == 0)
		e->raycast.perp_wall_dist = (e->raycast.map_x + e->raycast.door_dist -
				e->raycast.ray_pos.x + (1 - e->raycast.step_x) / 2) /
			e->raycast.ray_dir.x;
	else
		e->raycast.perp_wall_dist = (e->raycast.map_y + e->raycast.door_dist -
				e->raycast.ray_pos.y + (1 - e->raycast.step_y) / 2) /
			e->raycast.ray_dir.y;
}

void	ft_can_see_player_3_1_2(t_env *e)
{
	int		map_x;
	int		map_y;
	int		side;

	map_x = e->raycast.map_x;
	map_y = e->raycast.map_y;
	if (e->raycast.side_dist.x < e->raycast.side_dist.y)
	{
		map_x = e->raycast.map_x + e->raycast.step_x;
		side = 0;
	}
	else
	{
		map_y = e->raycast.map_y + e->raycast.step_y;
		side = 1;
	}
	if (e->map.data[map_x][map_y].wall != 0)
	{
		e->raycast.map_x = map_x;
		e->raycast.map_y = map_y;
		e->raycast.side = side;
		e->raycast.door = 1;
		e->raycast.hit = 1;
	}
}

void	ft_process_ss_process_2(t_env *e, t_enemy *this)
{
	if (this->dead && this->sprite->animation_index < this->index_die +
			this->die_count)
	{
		this->sprite->fast_index = (this->sprite->fast_index + 1) % (6 -
				this->die_count);
		if (this->sprite->fast_index == 0)
		{
			if (++this->sprite->animation_index == this->index_die +
					this->die_count)
				ft_drop_item(e, this);
		}
	}
	if (this->health <= 0 && !this->dead)
	{
		this->dead = 1;
		this->sprite->state = DIE;
		if (rand() % 2 == 0)
			ft_play_sound(e, this->index_death1);
		else
			ft_play_sound(e, this->index_death2);
		this->sprite->animation_index = this->index_die;
	}
	if (this->sprite->state == HURT)
		ft_get_hurt(e, this);
}
