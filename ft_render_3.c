/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:14:19 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 02:31:30 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_render_3_1_4_3(t_env *e)
{
	if (e->player.pos.x < e->raycast.map_x_2)
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

void	ft_render_3_1_4(t_env *e)
{
	e->raycast.map_x_2 = e->raycast.map_x;
	e->raycast.map_y_2 = e->raycast.map_y;
	ft_render_3_1_4_1(e);
	if (e->map.data[e->raycast.map_x_2][e->raycast.map_y_2].wall == 0)
		e->raycast.hit = 1;
	else
	{
		if (e->raycast.side_2 == 0)
			ft_render_3_1_4_2(e);
		else
			ft_render_3_1_4_3(e);
		e->raycast.hit = 1;
	}
}

void	ft_render_3_1(t_env *e)
{
	ft_render_3_1_1(e);
	ft_render_3_1_2(e);
	if (e->raycast.wall_x < e->raycast.door_timer)
		ft_render_3_1_3(e);
	else
		ft_render_3_1_4(e);
}

void	ft_render_3_2(t_env *e)
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

void	ft_render_3_3(t_env *e)
{
	double	timer;

	if (e->raycast.map_x == 15 && e->raycast.map_y == 29)
	{
		timer = -e->map.secret_door_timer;
		e->raycast.perp_wall_dist = (e->raycast.map_y + timer -
			e->raycast.ray_pos.y + (1 - e->raycast.step_y) / 2) /
			e->raycast.ray_dir.y;
		e->raycast.wall_x = e->raycast.ray_pos.x + e->raycast.perp_wall_dist *
			e->raycast.ray_dir.x;
		if (e->raycast.wall_x >= 15 && e->raycast.wall_x <= 16)
		{
			e->raycast.secret_door = 1;
			e->raycast.hit = 1;
		}
	}
	else
		e->raycast.hit = 1;
}
