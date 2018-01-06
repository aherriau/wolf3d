/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_menu_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 04:37:32 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 04:38:08 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_menu_sounds_4_process(t_env *e, SDL_Event event)
{
	if (e->sdl.menu_img == 19)
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 22;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 20;
		if (event.key.keysym.sym == SDLK_RETURN)
		{
			e->sdl.sound = 1;
			e->sdl.menu_img = 15;
		}
	}
	else if (e->sdl.menu_img == 20)
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 19;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 21;
	}
}

void	ft_menu_sounds_4(t_env *e, SDL_Event event)
{
	if (e->sdl.menu_img == 19 || e->sdl.menu_img == 20)
		ft_menu_sounds_4_process(e, event);
	else if (e->sdl.menu_img == 21)
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 20;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 22;
		if (event.key.keysym.sym == SDLK_RETURN)
		{
			e->sdl.musik = 1;
			e->sdl.menu_img = 13;
		}
	}
	else
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 21;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 19;
	}
}

void	ft_menu_sounds(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_BACKQUOTE)
		e->sdl.menu_img = 2;
	else
	{
		if (e->sdl.sound && e->sdl.musik)
			ft_menu_sounds_1(e, event);
		else if (e->sdl.musik)
			ft_menu_sounds_2(e, event);
		else if (e->sdl.sound)
			ft_menu_sounds_3(e, event);
		else
			ft_menu_sounds_4(e, event);
	}
	if (event.key.keysym.sym == SDLK_BACKQUOTE)
		ft_play_sound(e, 40);
	else if (event.key.keysym.sym == SDLK_RETURN)
		ft_play_sound(e, 39);
}

void	ft_menu_controls(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_BACKQUOTE)
		e->sdl.menu_img = 3;
	else
	{
		if (event.key.keysym.sym == SDLK_RETURN)
		{
			if (e->sdl.menu_img == 23)
			{
				e->sdl.menu_img = 24;
				e->sdl.mouse = 1;
			}
			else
			{
				e->sdl.menu_img = 23;
				e->sdl.mouse = 0;
			}
		}
	}
	if (event.key.keysym.sym == SDLK_BACKQUOTE)
		ft_play_sound(e, 40);
	else if (event.key.keysym.sym == SDLK_RETURN)
		ft_play_sound(e, 39);
}
