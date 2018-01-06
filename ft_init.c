/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:42:12 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 06:28:56 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_init_sdl_1(t_env *e)
{
	e->sdl.screen.x = 100;
	e->sdl.screen.y = 200;
	e->sdl.screen.w = SCREENW;
	e->sdl.screen.h = SCREENH;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (0);
	e->sdl.window = SDL_CreateWindow("Wolf3D", e->sdl.screen.x, e->sdl.screen.y,
			e->sdl.screen.w, e->sdl.screen.h, 0);
	if (e->sdl.window == NULL)
		return (0);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		return (0);
	Mix_VolumeMusic(32);
	e->sdl.renderer = SDL_CreateRenderer(e->sdl.window, -1, 0);
	if (e->sdl.renderer == NULL)
		return (0);
	if (SDL_RenderSetLogicalSize(e->sdl.renderer,
		e->sdl.screen.w, e->sdl.screen.h) < 0)
		return (0);
	if (SDL_SetRenderDrawColor(e->sdl.renderer, 0, 0, 0, 255) < 0)
		return (0);
	e->sdl.surface = SDL_CreateRGBSurface(0, W, H, 32, 0, 0, 0, 0);
	if (e->sdl.surface == NULL)
		return (0);
	return (1);
}

int		ft_init_sdl(t_env *e)
{
	if (ft_init_sdl_1(e) == 0)
		return (0);
	ft_init_sdl_menu_textures(e);
	ft_init_sdl_hud_textures(e);
	e->sdl.filter_timer = 0;
	e->sdl.menu_img = 1;
	e->sdl.sound = 1;
	e->sdl.musik = 1;
	e->sdl.mouse = 1;
	e->sdl.hud_timer = 1;
	e->sdl.transition_timer = 0;
	e->sdl.hud_face = 0;
	e->sdl.pause = 0;
	e->sdl.just_pause = 0;
	e->sdl.can_pause = 1;
	e->sdl.levelup = 0;
	e->sdl.levelup_timer = 0;
	e->sdl.just_transitate = 0;
	e->sdl.door = 0;
	e->sdl.d.x = 0;
	e->sdl.d.y = 0;
	return (1);
}

int		ft_init(t_env *e)
{
	srand(time(NULL));
	if (ft_init_sdl(e) == 0)
		return (0);
	ft_init_init(e);
	ft_init_process(e);
	ft_init_wall_textures(e);
	ft_init_item_sprites(e);
	ft_init_enemy_sprites(e);
	ft_init_sounds(e);
	ft_init_hud(e);
	ft_init_projectiles(e);
	ft_init_functions(e);
	e->menu = 1;
	e->transition = 0;
	return (1);
}
