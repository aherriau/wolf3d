/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:14:57 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 02:31:58 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_render_3_4(t_env *e)
{
	double	timer;

	if (e->raycast.map_x == 15 && e->raycast.map_y == 28)
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

void	ft_render_3(t_env *e)
{
	if (e->raycast.side_dist.x < e->raycast.side_dist.y)
	{
		e->raycast.side_dist.x += e->raycast.delta_dist.x;
		e->raycast.map_x += e->raycast.step_x;
		e->raycast.side = 0;
	}
	else
	{
		e->raycast.side_dist.y += e->raycast.delta_dist.y;
		e->raycast.map_y += e->raycast.step_y;
		e->raycast.side = 1;
	}
	if (e->map.data[e->raycast.map_x][e->raycast.map_y].wall != 0)
	{
		if (e->map.data[e->raycast.map_x][e->raycast.map_y].wall == 50)
			ft_render_3_1(e);
		else if (e->map.data[e->raycast.map_x][e->raycast.map_y].wall == -1)
			ft_render_3_2(e);
		else if (e->map.secret_door == 1)
			ft_render_3_3(e);
		else if (e->map.secret_door == 2)
			ft_render_3_4(e);
		else
			e->raycast.hit = 1;
	}
}

void	ft_render_4(t_env *e, int x)
{
	if (e->map.data[e->raycast.map_x][e->raycast.map_y].wall != 50)
		e->raycast.door_dist = 0;
	if (e->raycast.secret_door == 1)
		e->raycast.door_dist = -e->map.secret_door_timer;
	if (e->raycast.side == 0)
		e->raycast.perp_wall_dist = (e->raycast.map_x + e->raycast.door_dist -
				e->raycast.ray_pos.x + (1 - e->raycast.step_x) / 2) /
			e->raycast.ray_dir.x;
	else
		e->raycast.perp_wall_dist = (e->raycast.map_y + e->raycast.door_dist -
				e->raycast.ray_pos.y + (1 - e->raycast.step_y) / 2) /
			e->raycast.ray_dir.y;
	e->raycast.z_buff[x] = e->raycast.perp_wall_dist;
	e->raycast.line_height = (int)(H / e->raycast.perp_wall_dist);
	e->raycast.draw_start = -(e->raycast.line_height / 2) + H / 2;
	e->raycast.draw_end = (e->raycast.line_height / 2) + H / 2;
	if (e->raycast.draw_start < 0)
		e->raycast.draw_start = 0;
	if (e->raycast.draw_end >= H)
		e->raycast.draw_end = H - 1;
}

void	ft_render_5_1_1(t_env *e)
{
	e->raycast.tex_num = 51 * 2;
	if (e->raycast.side == 0)
	{
		if (e->player.pos.x < e->raycast.map_x)
			e->raycast.tex_num = 68 * 2;
	}
	else
	{
		if (e->player.pos.y > e->raycast.map_y)
			e->raycast.tex_num = 68 * 2;
	}
}

void	ft_render_5_1_2(t_env *e)
{
	if (e->raycast.side == 0)
	{
		if (e->player.pos.x < e->raycast.map_x)
			e->raycast.tex_num = 67 * 2;
	}
	else
	{
		if (e->player.pos.y > e->raycast.map_y)
			e->raycast.tex_num = 67 * 2;
	}
}
