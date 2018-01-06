/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:45:35 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 03:27:53 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_keydown_pause(t_env *e)
{
	if (e->sdl.pause == 0)
	{
		ft_play_sound(e, 41);
		e->sdl.can_pause = 0;
		e->sdl.pause = 1;
		e->sdl.just_pause = 1;
		SDL_SetRelativeMouseMode(0);
		Mix_VolumeMusic(32);
		SDL_WarpMouseInWindow(e->sdl.window, SCREENW / 2, SCREENH / 2);
	}
	else
	{
		ft_play_sound(e, 42);
		e->sdl.pause = 0;
		SDL_SetRelativeMouseMode(1);
		Mix_VolumeMusic(128);
		e->sdl.can_pause = 0;
	}
}

void	ft_keydown_shoot(t_env *e)
{
	e->player.did_not_shoot = 1;
	e->player.shooting = 1;
	e->player.can_shoot = 0;
}

void	ft_keydown_game(t_env *e, SDL_Event event)
{
	if (e->sdl.levelup)
		return ;
	if (event.key.keysym.sym == SDLK_p && e->sdl.can_pause)
		ft_keydown_pause(e);
	if (event.key.keysym.sym == SDLK_w)
		e->player.forward = 1;
	if (event.key.keysym.sym == SDLK_s)
		e->player.backward = 1;
	if (event.key.keysym.sym == SDLK_a)
		e->player.left = 1;
	if (event.key.keysym.sym == SDLK_d)
		e->player.right = 1;
	if (event.key.keysym.sym == SDLK_LEFT)
		e->player.rotate_left = 1;
	if (event.key.keysym.sym == SDLK_RIGHT)
		e->player.rotate_right = 1;
	if (e->player.dead || e->sdl.pause)
		return ;
	if (event.key.keysym.sym == SDLK_x && e->player.can_shoot)
		ft_keydown_shoot(e);
	if (event.key.keysym.sym == SDLK_SPACE)
		ft_keydown_door(e);
	if (event.key.keysym.sym == SDLK_LSHIFT)
		e->player.speed_walk = 0.3;
}

void	ft_keydown(t_env *e, SDL_Event event)
{
	if (e->menu)
		ft_keydown_menu(e, event);
	else
		ft_keydown_game(e, event);
}

void	ft_keyup(t_env *e, SDL_Event event)
{
	if (!e->menu)
	{
		if (event.key.keysym.sym == SDLK_w)
			e->player.forward = 0;
		if (event.key.keysym.sym == SDLK_s)
			e->player.backward = 0;
		if (event.key.keysym.sym == SDLK_a)
			e->player.left = 0;
		if (event.key.keysym.sym == SDLK_d)
			e->player.right = 0;
		if (event.key.keysym.sym == SDLK_LEFT)
			e->player.rotate_left = 0;
		if (event.key.keysym.sym == SDLK_RIGHT)
			e->player.rotate_right = 0;
		if (event.key.keysym.sym == SDLK_LSHIFT)
			e->player.speed_walk = 0.2;
		if (event.key.keysym.sym == SDLK_p)
			e->sdl.can_pause = 1;
		if (event.key.keysym.sym == SDLK_x)
		{
			e->player.shooting = 0;
			e->player.can_shoot = 1;
		}
	}
}
