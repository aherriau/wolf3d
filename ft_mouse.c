/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:52:34 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 02:22:58 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_motion_mouse(t_env *e, SDL_Event event)
{
	double angle;

	if (e->menu)
		ft_motion_mouse_menu(e, event);
	else if (!e->sdl.pause && e->sdl.mouse && !e->player.dead)
	{
		angle = -(event.motion.xrel * e->player.sensitivity) / 1000;
		e->player.old_dir_x = e->player.dir.x;
		e->player.dir.x = e->player.dir.x * cos(angle) -
			e->player.dir.y * sin(angle);
		e->player.dir.y = e->player.old_dir_x * sin(angle) +
			e->player.dir.y * cos(angle);
		e->player.old_plane_x = e->player.plane.x;
		e->player.plane.x = e->player.plane.x * cos(angle) -
			e->player.plane.y * sin(angle);
		e->player.plane.y = e->player.old_plane_x * sin(angle) +
			e->player.plane.y * cos(angle);
	}
}

void	ft_mouse_down_pause(t_env *e, SDL_Event event)
{
	int		x;
	int		y;

	x = event.button.x;
	y = event.button.y;
	if (x >= 50 && x <= 209 && y >= 42 && y <= 96)
	{
		e->sdl.pause = 0;
		e->menu = 1;
		e->sdl.menu_img = 1;
		ft_play_sound(e, 40);
		Mix_HaltMusic();
		ft_play_music(e, 5);
		ft_free_map(e);
	}
}

void	ft_mouse_down(t_env *e, SDL_Event event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		if (e->sdl.levelup)
			return ;
		else if (e->menu)
			ft_mouse_down_menu(e, event);
		else if (e->sdl.pause)
			ft_mouse_down_pause(e, event);
		else if (e->sdl.mouse && !e->player.dead)
		{
			e->player.did_not_shoot = 1;
			e->player.shooting = 1;
		}
	}
}

void	ft_mouse_up(t_env *e, SDL_Event event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		if (!e->menu && e->sdl.mouse && !e->player.dead && !e->sdl.pause)
		{
			e->player.shooting = 0;
		}
	}
}
