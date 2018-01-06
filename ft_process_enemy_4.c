/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_enemy_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:19:15 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 02:29:17 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_can_see_player_3_1_3_1(t_env *e)
{
	if (e->raycast.side_dist.x < e->raycast.side_dist.y)
	{
		e->raycast.side_dist.x += e->raycast.delta_dist.x;
		e->raycast.map_x_2 = e->raycast.map_x + e->raycast.step_x;
		e->raycast.side_2 = 0;
	}
	else
	{
		e->raycast.side_dist.y += e->raycast.delta_dist.y;
		e->raycast.map_y_2 = e->raycast.map_y + e->raycast.step_y;
		e->raycast.side_2 = 1;
	}
	if (e->raycast.side_2 == 0)
		e->raycast.perp_wall_dist_2 = (e->raycast.map_x_2 - e->raycast.ray_pos.x
				+ (1 - e->raycast.step_x) / 2) / e->raycast.ray_dir.x;
	else
		e->raycast.perp_wall_dist_2 = (e->raycast.map_y_2 - e->raycast.ray_pos.y
				+ (1 - e->raycast.step_y) / 2) / e->raycast.ray_dir.y;
	if (e->raycast.side_2 == 0)
		e->raycast.wall_x_2 = e->raycast.ray_pos.y + e->raycast.perp_wall_dist_2
			* e->raycast.ray_dir.y;
	else
		e->raycast.wall_x_2 = e->raycast.ray_pos.x + e->raycast.perp_wall_dist_2
			* e->raycast.ray_dir.x;
	e->raycast.wall_x_2 -= floor((e->raycast.wall_x_2));
}

void	ft_can_see_player_3_1_3_2(t_env *e, t_enemy *this)
{
	if (this->sprite->pos.y < e->raycast.map_y_2)
	{
		if (e->raycast.wall_x_2 < 0.5)
		{
			e->raycast.map_x = e->raycast.map_x_2;
			e->raycast.map_y = e->raycast.map_y_2;
			e->raycast.side = e->raycast.side_2;
			e->raycast.door = 1;
		}
	}
	else
	{
		if (e->raycast.wall_x_2 > 0.5)
		{
			e->raycast.map_x = e->raycast.map_x_2;
			e->raycast.map_y = e->raycast.map_y_2;
			e->raycast.side = e->raycast.side_2;
			e->raycast.door = 1;
		}
	}
}

void	ft_can_see_player_3_1_3_3(t_env *e, t_enemy *this)
{
	if (this->sprite->pos.x < e->raycast.map_x_2)
	{
		if (e->raycast.wall_x_2 < 0.5)
		{
			e->raycast.map_x = e->raycast.map_x_2;
			e->raycast.map_y = e->raycast.map_y_2;
			e->raycast.side = e->raycast.side_2;
			e->raycast.door = 1;
		}
	}
	else
	{
		if (e->raycast.wall_x_2 > 0.5)
		{
			e->raycast.map_x = e->raycast.map_x_2;
			e->raycast.map_y = e->raycast.map_y_2;
			e->raycast.side = e->raycast.side_2;
			e->raycast.door = 1;
		}
	}
}

void	ft_can_see_player_3_1_3(t_env *e, t_enemy *this)
{
	e->raycast.map_x_2 = e->raycast.map_x;
	e->raycast.map_y_2 = e->raycast.map_y;
	ft_can_see_player_3_1_3_1(e);
	if (e->map.data[e->raycast.map_x_2][e->raycast.map_y_2].wall == 0)
		e->raycast.hit = 1;
	else
	{
		if (e->raycast.side_2 == 0)
			ft_can_see_player_3_1_3_2(e, this);
		else
			ft_can_see_player_3_1_3_3(e, this);
		e->raycast.hit = 1;
	}
}

void	ft_can_see_player_3_1(t_env *e, t_enemy *this)
{
	ft_can_see_player_3_1_1(e, this);
	if (e->raycast.side == 0)
		e->raycast.wall_x = e->raycast.ray_pos.y + e->raycast.perp_wall_dist *
			e->raycast.ray_dir.y;
	else
		e->raycast.wall_x = e->raycast.ray_pos.x + e->raycast.perp_wall_dist *
			e->raycast.ray_dir.x;
	e->raycast.wall_x -= floor((e->raycast.wall_x));
	if (e->raycast.wall_x < e->raycast.door_timer)
		ft_can_see_player_3_1_2(e);
	else
		ft_can_see_player_3_1_3(e, this);
}
