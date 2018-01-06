/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 05:54:06 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 07:38:57 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_process_levelup(t_env *e)
{
	if (e->sdl.levelup_timer == 120)
	{
		e->sdl.levelup = 0;
		e->sdl.levelup_timer = 0;
		e->sdl.pause = 0;
		ft_free_map(e);
		if (e->player.floor == 1)
		{
			ft_verify_map(e, "./maps/level2.wlf");
			ft_init_map(e, "./maps/level2.wlf");
			Mix_HaltMusic();
			e->player.floor = 2;
			ft_init_player_levelup(e);
		}
		else if (e->player.floor == 2)
		{
			ft_verify_map(e, "./maps/level3.wlf");
			ft_init_map(e, "./maps/level3.wlf");
			e->player.floor = 3;
			Mix_HaltMusic();
			ft_init_player_levelup(e);
		}
	}
	else
		e->sdl.levelup_timer++;
}

void	ft_process_game_2(t_env *e)
{
	SDL_Rect	rect;

	SDL_LockSurface(e->sdl.surface);
	ft_render(e);
	ft_render_sprites(e);
	SDL_UnlockSurface(e->sdl.surface);
	ft_render_weapon(e);
	ft_apply_filter(e);
	ft_transite(e);
	ft_render_hud(e);
	if (!e->transition && !e->sdl.just_transitate)
	{
		if (!(e->sdl.texture = SDL_CreateTextureFromSurface(e->sdl.renderer,
						e->sdl.surface)))
			ft_error("SDL malloc error");
		SDL_FillRect(e->sdl.surface, NULL, 0x000000);
		rect.x = 35;
		rect.y = 25;
		rect.w = W;
		rect.h = H;
		SDL_RenderCopy(e->sdl.renderer, e->sdl.texture, NULL, &rect);
		SDL_DestroyTexture(e->sdl.texture);
	}
}

void	ft_process_game_3(t_env *e)
{
	SDL_Rect	pause_rect;
	SDL_Rect	menu_rect;

	pause_rect.x = W / 2 - 256 / 2 + 35;
	pause_rect.y = 372;
	pause_rect.w = 256;
	pause_rect.h = 128;
	SDL_RenderCopy(e->sdl.renderer, e->sdl.hud[5], NULL, &pause_rect);
	menu_rect.x = 50;
	menu_rect.y = 42;
	menu_rect.w = 159;
	menu_rect.h = 54;
	SDL_RenderCopy(e->sdl.renderer, e->sdl.hud[21], NULL, &menu_rect);
}

void	ft_process_game(t_env *e)
{
	if (!e->sdl.pause)
	{
		if (!e->transition)
			ft_door(e);
		if (e->sdl.door)
			ft_switch_process_door(e);
		else
		{
			ft_move(e);
			ft_pick(e);
			ft_process_enemies(e);
			ft_process_weapon(e);
			ft_process_projectiles(e);
		}
	}
	if (!e->sdl.pause || e->sdl.just_pause)
		ft_process_game_2(e);
	if (e->sdl.just_pause && !e->sdl.levelup)
		ft_process_game_3(e);
	if (e->sdl.levelup)
		ft_process_levelup(e);
}
