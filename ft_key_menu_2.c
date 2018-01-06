/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_menu_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 04:35:30 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 07:09:02 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_menu_games_1(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
		e->sdl.menu_img = 6;
	if (event.key.keysym.sym == SDLK_DOWN)
		e->sdl.menu_img = 5;
	if (event.key.keysym.sym == SDLK_RETURN)
	{
		e->menu = 0;
		SDL_SetRelativeMouseMode(1);
		Mix_VolumeMusic(128);
		ft_verify_map(e, "./maps/level1.wlf");
		ft_init_map(e, "./maps/level1.wlf");
		e->player.floor = 1;
		Mix_HaltMusic();
		ft_play_music(e, 0);
		ft_init_player(e, 3);
	}
}

void	ft_menu_games_2(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
		e->sdl.menu_img = 4;
	if (event.key.keysym.sym == SDLK_DOWN)
		e->sdl.menu_img = 6;
	if (event.key.keysym.sym == SDLK_RETURN)
	{
		e->menu = 0;
		SDL_SetRelativeMouseMode(1);
		Mix_VolumeMusic(128);
		ft_verify_map(e, "./maps/level2.wlf");
		ft_init_map(e, "./maps/level2.wlf");
		e->player.floor = 2;
		ft_init_player(e, 3);
		Mix_HaltMusic();
		ft_play_music(e, 1);
	}
}

void	ft_menu_games_3(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
		e->sdl.menu_img = 5;
	if (event.key.keysym.sym == SDLK_DOWN)
		e->sdl.menu_img = 4;
	if (event.key.keysym.sym == SDLK_RETURN)
	{
		e->menu = 0;
		SDL_SetRelativeMouseMode(1);
		Mix_VolumeMusic(128);
		ft_verify_map(e, "./maps/level3.wlf");
		ft_init_map(e, "./maps/level3.wlf");
		e->player.floor = 3;
		ft_init_player(e, 3);
		Mix_HaltMusic();
		ft_play_music(e, 2);
	}
}

void	ft_menu_games(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_BACKQUOTE)
		e->sdl.menu_img = 1;
	else
	{
		if (e->sdl.menu_img == 4)
			ft_menu_games_1(e, event);
		else if (e->sdl.menu_img == 5)
			ft_menu_games_2(e, event);
		else
			ft_menu_games_3(e, event);
	}
	if (event.key.keysym.sym == SDLK_BACKQUOTE ||
			event.key.keysym.sym == SDLK_RETURN)
		ft_play_sound(e, 40);
}

void	ft_menu_sounds_1_process(t_env *e, SDL_Event event)
{
	if (e->sdl.menu_img == 7)
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 10;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 8;
	}
	else if (e->sdl.menu_img == 8)
	{
		if (event.key.keysym.sym == SDLK_UP)
			e->sdl.menu_img = 7;
		if (event.key.keysym.sym == SDLK_DOWN)
			e->sdl.menu_img = 9;
		if (event.key.keysym.sym == SDLK_RETURN)
		{
			e->sdl.sound = 0;
			e->sdl.menu_img = 12;
		}
	}
}
