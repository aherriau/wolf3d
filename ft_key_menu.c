/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 03:26:36 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 04:38:38 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_menu_options_1(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
		e->sdl.menu_img = 3;
	if (event.key.keysym.sym == SDLK_DOWN)
		e->sdl.menu_img = 2;
	if (event.key.keysym.sym == SDLK_RETURN)
		e->sdl.menu_img = 4;
}

void	ft_menu_options_2(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
		e->sdl.menu_img = 1;
	if (event.key.keysym.sym == SDLK_DOWN)
		e->sdl.menu_img = 3;
	if (event.key.keysym.sym == SDLK_RETURN)
	{
		if (e->sdl.sound && e->sdl.musik)
			e->sdl.menu_img = 7;
		else if (e->sdl.musik)
			e->sdl.menu_img = 11;
		else if (e->sdl.sound)
			e->sdl.menu_img = 15;
		else
			e->sdl.menu_img = 19;
	}
}

void	ft_menu_options_3(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
		e->sdl.menu_img = 2;
	if (event.key.keysym.sym == SDLK_DOWN)
		e->sdl.menu_img = 1;
	if (event.key.keysym.sym == SDLK_RETURN)
	{
		if (e->sdl.mouse)
			e->sdl.menu_img = 24;
		else
			e->sdl.menu_img = 23;
	}
}

void	ft_menu_options(t_env *e, SDL_Event event)
{
	if (e->sdl.menu_img == 1)
		ft_menu_options_1(e, event);
	else if (e->sdl.menu_img == 2)
		ft_menu_options_2(e, event);
	else
		ft_menu_options_3(e, event);
	if (event.key.keysym.sym == SDLK_RETURN)
		ft_play_sound(e, 40);
}

void	ft_keydown_menu(t_env *e, SDL_Event event)
{
	if (e->sdl.menu_img <= 3)
		ft_menu_options(e, event);
	else if (e->sdl.menu_img <= 6)
		ft_menu_games(e, event);
	else if (e->sdl.menu_img <= 22)
		ft_menu_sounds(e, event);
	else
		ft_menu_controls(e, event);
	if (e->sdl.menu_img <= 22 && (event.key.keysym.sym == SDLK_UP ||
		event.key.keysym.sym == SDLK_DOWN))
		ft_play_sound(e, 38);
}
