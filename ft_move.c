/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 06:39:07 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 02:23:12 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_move_rotate_right(t_env *e)
{
	e->player.old_dir_x = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(-(e->player.speed_rotation)) -
		e->player.dir.y * sin(-(e->player.speed_rotation));
	e->player.dir.y = e->player.old_dir_x * sin(-(e->player.speed_rotation)) +
		e->player.dir.y * cos(-(e->player.speed_rotation));
	e->player.old_plane_x = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(-(e->player.speed_rotation))
		- e->player.plane.y * sin(-(e->player.speed_rotation));
	e->player.plane.y = e->player.old_plane_x *
		sin(-(e->player.speed_rotation)) + e->player.plane.y *
		cos(-(e->player.speed_rotation));
}

void	ft_move_rotate_left(t_env *e)
{
	e->player.old_dir_x = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(e->player.speed_rotation) -
		e->player.dir.y * sin(e->player.speed_rotation);
	e->player.dir.y = e->player.old_dir_x * sin(e->player.speed_rotation) +
		e->player.dir.y * cos(e->player.speed_rotation);
	e->player.old_plane_x = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(e->player.speed_rotation) -
		e->player.plane.y * sin(e->player.speed_rotation);
	e->player.plane.y = e->player.old_plane_x *
		sin(e->player.speed_rotation) + e->player.plane.y *
		cos(e->player.speed_rotation);
}

void	ft_move_rotate(t_env *e)
{
	if (e->player.rotate_right && !e->player.dead && !e->sdl.pause)
		ft_move_rotate_right(e);
	if (e->player.rotate_left && !e->player.dead && !e->sdl.pause)
		ft_move_rotate_left(e);
}

void	ft_move(t_env *e)
{
	e->player.picked = 0;
	e->player.hurt = 0;
	e->player.died = 0;
	e->sdl.just_transitate = 0;
	if (e->player.forward && !e->player.dead && !e->sdl.pause)
	{
		ft_move_forward_x(e);
		ft_move_forward_y(e);
	}
	if (e->player.backward && !e->player.dead && !e->sdl.pause)
	{
		ft_move_backward_x(e);
		ft_move_backward_y(e);
	}
	if (e->player.right && !e->player.dead && !e->sdl.pause)
	{
		ft_move_right_x(e);
		ft_move_right_y(e);
	}
	if (e->player.left && !e->player.dead && !e->sdl.pause)
	{
		ft_move_left_x(e);
		ft_move_left_y(e);
	}
	ft_move_rotate(e);
}
