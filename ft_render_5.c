/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:15:37 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 02:19:43 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_render_5_1(t_env *e)
{
	if ((e->player.floor == 1 && e->raycast.map_x == (int)e->map.end.x &&
		e->raycast.map_y == ((int)e->map.end.y - 1)) || (e->player.floor == 2 &&
		e->raycast.map_x == ((int)e->map.end.x - 1) &&
		e->raycast.map_y == (int)e->map.end.y))
		ft_render_5_1_1(e);
	else
		ft_render_5_1_2(e);
	if (e->player.floor == 3 && e->raycast.map_x == 2 && e->raycast.map_y == 48)
	{
		e->raycast.tex_num = 52 * 2;
		if (e->raycast.side == 0)
		{
			if (e->player.pos.x < e->raycast.map_x)
				e->raycast.tex_num = 70 * 2;
		}
		else
		{
			if (e->player.pos.y > e->raycast.map_y)
				e->raycast.tex_num = 70 * 2;
		}
	}
}

void	ft_render_5_2(t_env *e)
{
	if (e->raycast.side == 0)
		e->raycast.wall_x = e->raycast.ray_pos.y + e->raycast.perp_wall_dist *
			e->raycast.ray_dir.y;
	else
		e->raycast.wall_x = e->raycast.ray_pos.x + e->raycast.perp_wall_dist *
			e->raycast.ray_dir.x;
	e->raycast.wall_x -= floor((e->raycast.wall_x));
}

void	ft_render_5(t_env *e)
{
	e->raycast.tex_num = (e->map.data[e->raycast.map_x]
			[e->raycast.map_y].wall - 1) * 2;
	if (e->map.data[(int)e->player.pos.x][(int)e->player.pos.y].wall == -1)
	{
		if (e->raycast.side == 1)
		{
			if (abs(e->raycast.map_y - (int)e->player.pos.y) == 1 &&
					abs(e->raycast.map_x - (int)e->player.pos.x) == 0)
				e->raycast.door = 1;
		}
		else
		{
			if (abs(e->raycast.map_x - (int)e->player.pos.x) == 1 &&
					abs(e->raycast.map_y - (int)e->player.pos.y) == 0)
				e->raycast.door = 1;
		}
	}
	if (e->raycast.door)
		e->raycast.tex_num = 50 * 2;
	if (e->map.data[e->raycast.map_x][e->raycast.map_y].wall == 50)
		ft_render_5_1(e);
	ft_render_5_2(e);
}

void	ft_render_6_1(t_env *e, int x)
{
	int		y;

	y = e->raycast.y1;
	while (y < e->raycast.y2)
	{
		e->raycast.d = y * 256 - H * 128 + e->raycast.line_height * 128;
		e->raycast.tex_y = ((e->raycast.d * 64) / e->raycast.line_height) / 256;
		if (e->raycast.side == 0)
			e->raycast.pix2 = (int *)(e->stex.wall[e->raycast.tex_num +
					1]->pixels);
		else
			e->raycast.pix2 = (int *)(e->stex.wall[e->raycast.tex_num]->pixels);
		e->raycast.color = e->raycast.pix2[64 * e->raycast.tex_y +
			e->raycast.tex_x];
		e->raycast.pix[y * W + x] = e->raycast.color;
		y++;
	}
}

void	ft_render_6(t_env *e, int x)
{
	if (e->raycast.tex_num == 49 * 2 || e->raycast.tex_num == 67 * 2 ||
			e->raycast.tex_num == 51 * 2 || e->raycast.tex_num == 68 * 2 ||
			e->raycast.tex_num == 52 * 2 || e->raycast.tex_num == 70 * 2)
		e->raycast.tex_x = (int)((e->raycast.wall_x - e->raycast.door_timer) *
				(double)64);
	else
		e->raycast.tex_x = (int)(e->raycast.wall_x * (double)64);
	if (e->raycast.side == 0 && e->raycast.ray_dir.x > 0)
		e->raycast.tex_x = 64 - e->raycast.tex_x - 1;
	if (e->raycast.side == 1 && e->raycast.ray_dir.y < 0)
		e->raycast.tex_x = 64 - e->raycast.tex_x - 1;
	e->raycast.pix = (int *)(e->sdl.surface->pixels);
	e->raycast.y1 = ft_clamp(e->raycast.draw_start, 0, H - 1);
	e->raycast.y2 = ft_clamp(e->raycast.draw_end, 0, H - 1);
	if (e->raycast.y2 > e->raycast.y1)
		ft_render_6_1(e, x);
	e->raycast.x = x;
	e->raycast.y1 = 0;
	e->raycast.y2 = e->raycast.draw_start;
	e->raycast.color = 0x383838;
	ft_vline(e);
	e->raycast.y1 = e->raycast.draw_end;
	e->raycast.y2 = H;
	e->raycast.color = 0x707070;
	ft_vline(e);
}
