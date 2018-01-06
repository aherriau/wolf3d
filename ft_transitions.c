/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transitions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 21:44:05 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 05:20:31 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_process_transition_success(t_env *e)
{
	SDL_Rect rect;

	rect.x = 0;
	rect.y = 0;
	rect.w = SCREENW;
	rect.h = SCREENH;
	if (e->transition == SUCCESS && e->sdl.transition_timer != 185)
		SDL_RenderCopy(e->sdl.renderer, e->sdl.hud[23], NULL, &rect);
	else
	{
		e->transition = 0;
		e->menu = 1;
		e->sdl.menu_img = 1;
		SDL_SetRelativeMouseMode(0);
		Mix_VolumeMusic(32);
		e->sdl.transition_timer = 0;
		e->sdl.just_transitate = 1;
		Mix_HaltMusic();
		ft_play_music(e, 5);
		ft_free_map(e);
	}
	e->sdl.transition_timer++;
}

void	ft_process_transition_game_over(t_env *e)
{
	SDL_Rect rect;

	rect.x = 0;
	rect.y = 0;
	rect.w = SCREENW;
	rect.h = SCREENH;
	if (e->transition == GAME_OVER && e->sdl.transition_timer != 120)
		SDL_RenderCopy(e->sdl.renderer, e->sdl.hud[22], NULL, &rect);
	else
	{
		e->transition = 0;
		e->menu = 1;
		ft_free_map(e);
		e->sdl.menu_img = 1;
		SDL_SetRelativeMouseMode(0);
		Mix_VolumeMusic(32);
		e->sdl.transition_timer = 0;
		e->sdl.just_transitate = 1;
		Mix_HaltMusic();
		ft_play_music(e, 5);
	}
	e->sdl.transition_timer++;
}

void	ft_transite_dead(t_env *e)
{
	e->player.current_filter = 0;
	if (e->player.lives > 0)
	{
		ft_free_map(e);
		if (e->player.floor == 1)
			ft_init_map(e, "./maps/level1.wlf");
		else if (e->player.floor == 2)
			ft_init_map(e, "./maps/level2.wlf");
		else
			ft_init_map(e, "./maps/level3.wlf");
		e->player.lives--;
		e->player.health = 100;
		e->player.weapon = ft_new_pistol();
		e->player.best_weapon = 1;
		e->player.ammo = 15;
		e->player.score = e->player.score_floor;
		ft_init_player_levelup(e);
	}
	else
	{
		e->transition = GAME_OVER;
		e->sdl.transition_timer = 0;
		Mix_HaltMusic();
		ft_play_music(e, 3);
	}
}

void	ft_transite(t_env *e)
{
	if (e->player.current_filter == 3 && e->sdl.filter_timer == 41)
		ft_transite_dead(e);
	if (e->player.win)
	{
		e->player.win = 0;
		e->transition = SUCCESS;
		e->sdl.transition_timer = 0;
		Mix_HaltMusic();
		ft_play_music(e, 4);
	}
	if (e->transition == GAME_OVER)
		ft_process_transition_game_over(e);
	else if (e->transition == SUCCESS)
		ft_process_transition_success(e);
}
