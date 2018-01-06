/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_menu_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 04:36:55 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 04:37:26 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_menu_sounds_1(t_env *e, SDL_Event event)
{
	if (e->sdl.menu_img == 7 || e->sdl.menu_img == 8)
		ft_menu_sounds_1_process(e, event);
	else if (e->sdl.menu_img == 9)
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 8;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 10;
	}
	else
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 9;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 7;
		if (event.key.keysym.sym == SDLK_RETURN)
		{
			e->sdl.musik = 0;
			Mix_HaltMusic();
			e->sdl.menu_img = 18;
		}
	}
}

void	ft_menu_sounds_2_process(t_env *e, SDL_Event event)
{
	if (e->sdl.menu_img == 11)
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 14;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 12;
		if (event.key.keysym.sym == SDLK_RETURN)
		{
			e->sdl.sound = 1;
			e->sdl.menu_img = 7;
		}
	}
	else if (e->sdl.menu_img == 12)
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 11;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 13;
	}
}

void	ft_menu_sounds_2(t_env *e, SDL_Event event)
{
	if (e->sdl.menu_img == 11 || e->sdl.menu_img == 12)
		ft_menu_sounds_2_process(e, event);
	else if (e->sdl.menu_img == 13)
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 12;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 14;
	}
	else
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 13;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 11;
		if (event.key.keysym.sym == SDLK_RETURN)
		{
			e->sdl.musik = 0;
			Mix_HaltMusic();
			e->sdl.menu_img = 22;
		}
	}
}

void	ft_menu_sounds_3_process(t_env *e, SDL_Event event)
{
	if (e->sdl.menu_img == 15)
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 18;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 16;
	}
	else if (e->sdl.menu_img == 16)
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 15;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 17;
		if (event.key.keysym.sym == SDLK_RETURN)
		{
			e->sdl.sound = 0;
			e->sdl.menu_img = 20;
		}
	}
}

void	ft_menu_sounds_3(t_env *e, SDL_Event event)
{
	if (e->sdl.menu_img == 15 || e->sdl.menu_img == 16)
		ft_menu_sounds_3_process(e, event);
	else if (e->sdl.menu_img == 17)
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 16;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 18;
		if (event.key.keysym.sym == SDLK_RETURN)
		{
			e->sdl.musik = 1;
			e->sdl.menu_img = 9;
		}
	}
	else
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 17;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 15;
	}
}
