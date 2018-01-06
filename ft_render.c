/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:21:09 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 02:19:16 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_vline(t_env *e)
{
	int		y;

	e->raycast.y1 = ft_clamp(e->raycast.y1, 0, H - 1);
	e->raycast.y2 = ft_clamp(e->raycast.y2, 0, H - 1);
	if (e->raycast.y2 > e->raycast.y1)
	{
		y = e->raycast.y1 + 1;
		while (y < e->raycast.y2)
		{
			e->raycast.pix[y * W + e->raycast.x] = e->raycast.color;
			y++;
		}
	}
}

void	ft_render_1(t_env *e)
{
	e->raycast.ray_pos.x = e->player.pos.x;
	e->raycast.ray_pos.y = e->player.pos.y;
	e->raycast.ray_dir.x = e->player.dir.x +
		e->player.plane.x * e->raycast.camera_x;
	e->raycast.ray_dir.y = e->player.dir.y +
		e->player.plane.y * e->raycast.camera_x;
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

void	ft_render_2(t_env *e)
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
		e->raycast.side_dist.x = (e->raycast.map_x + 1.0 -
			e->raycast.ray_pos.x) * e->raycast.delta_dist.x;
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
		e->raycast.side_dist.y = (e->raycast.map_y + 1.0 -
			e->raycast.ray_pos.y) * e->raycast.delta_dist.y;
	}
}

void	ft_render(t_env *e)
{
	int		x;

	x = 0;
	while (x < W)
	{
		e->raycast.camera_x = 2 * x / (double)W - 1;
		ft_render_1(e);
		ft_render_2(e);
		while (e->raycast.hit == 0)
			ft_render_3(e);
		ft_render_4(e, x);
		ft_render_5(e);
		ft_render_6(e, x);
		x++;
	}
}
