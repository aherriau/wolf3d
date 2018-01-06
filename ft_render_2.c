/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:13:12 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 02:31:12 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_render_3_1_1(t_env *e)
{
	e->raycast.door_timer = e->map.data[e->raycast.map_x]
		[e->raycast.map_y].door_timer;
	if (e->raycast.side == 0)
	{
		if (e->player.pos.x < e->raycast.map_x)
			e->raycast.door_dist = 0.5;
		else
			e->raycast.door_dist = -0.5;
	}
	else
	{
		if (e->player.pos.y < e->raycast.map_y)
			e->raycast.door_dist = 0.5;
		else
			e->raycast.door_dist = -0.5;
	}
}

void	ft_render_3_1_2(t_env *e)
{
	if (e->raycast.side == 0)
		e->raycast.perp_wall_dist = (e->raycast.map_x + e->raycast.door_dist -
				e->raycast.ray_pos.x + (1 - e->raycast.step_x) / 2) /
			e->raycast.ray_dir.x;
	else
		e->raycast.perp_wall_dist = (e->raycast.map_y + e->raycast.door_dist -
				e->raycast.ray_pos.y + (1 - e->raycast.step_y) / 2) /
			e->raycast.ray_dir.y;
	if (e->raycast.side == 0)
		e->raycast.wall_x = e->raycast.ray_pos.y + e->raycast.perp_wall_dist *
			e->raycast.ray_dir.y;
	else
		e->raycast.wall_x = e->raycast.ray_pos.x + e->raycast.perp_wall_dist *
			e->raycast.ray_dir.x;
	e->raycast.wall_x -= floor((e->raycast.wall_x));
}

void	ft_render_3_1_3(t_env *e)
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

void	ft_render_3_1_4_1(t_env *e)
{
	if (e->raycast.side_dist.x < e->raycast.side_dist.y)
	{
		e->raycast.map_x_2 = e->raycast.map_x + e->raycast.step_x;
		e->raycast.side_2 = 0;
	}
	else
	{
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

void	ft_render_3_1_4_2(t_env *e)
{
	if (e->player.pos.y < e->raycast.map_y_2)
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
