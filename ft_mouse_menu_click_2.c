/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_menu_click_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 05:07:29 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 05:10:45 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_games_menu_click_process(t_env *e, int floor)
{
	e->menu = 0;
	SDL_SetRelativeMouseMode(1);
	if (floor == 1)
	{
		ft_verify_map(e, "./maps/level1.wlf");
		ft_init_map(e, "./maps/level1.wlf");
	}
	else if (floor == 2)
	{
		ft_verify_map(e, "./maps/level2.wlf");
		ft_init_map(e, "./maps/level2.wlf");
	}
	else
	{
		ft_verify_map(e, "./maps/level3.wlf");
		ft_init_map(e, "./maps/level3.wlf");
	}
	e->player.floor = floor;
	ft_init_player(e, 3);
	ft_play_sound(e, 40);
	Mix_VolumeMusic(128);
	Mix_HaltMusic();
	ft_play_music(e, floor - 1);
}

void	ft_games_menu_click(t_env *e, SDL_Event event)
{
	int		x;
	int		y;

	x = event.button.x;
	y = event.button.y;
	if (x >= 432 && x <= 784)
	{
		if (y >= 330 && y <= 396)
			ft_games_menu_click_process(e, 1);
		else if (y >= 396 && y <= 463)
			ft_games_menu_click_process(e, 2);
		else if (y >= 463 && y <= 530)
			ft_games_menu_click_process(e, 3);
	}
}

void	ft_sounds_menu_click_process(t_env *e, int y)
{
	if (y >= 317 && y <= 365)
	{
		if (!e->sdl.sound)
		{
			e->sdl.sound = 1;
			ft_menu_sound_2(e, e->sdl.menu_img - 4, 39);
		}
	}
	else if (y >= 365 && y <= 418)
	{
		if (e->sdl.sound)
		{
			e->sdl.sound = 0;
			ft_menu_sound_2(e, e->sdl.menu_img + 4, 39);
		}
	}
	else if (y >= 506 && y <= 554)
	{
		if (!e->sdl.musik)
		{
			e->sdl.musik = 1;
			ft_menu_sound_2(e, e->sdl.menu_img - 8, 39);
		}
	}
}

void	ft_sounds_menu_click(t_env *e, SDL_Event event)
{
	int		x;
	int		y;

	x = event.button.x;
	y = event.button.y;
	if (x >= 237 && x <= 962)
	{
		if ((y >= 317 && y <= 365) || (y >= 365 && y <= 418) ||
				(y >= 506 && y <= 554))
			ft_sounds_menu_click_process(e, y);
		else if (y >= 554 && y <= 607)
		{
			if (e->sdl.musik)
			{
				e->sdl.musik = 0;
				Mix_HaltMusic();
				ft_menu_sound_2(e, e->sdl.menu_img + 8, 39);
			}
		}
	}
}

void	ft_controls_menu_click(t_env *e, SDL_Event event)
{
	int		x;
	int		y;

	x = event.button.x;
	y = event.button.y;
	if (x >= 196 && x <= 1019 && y >= 292 && y <= 361)
	{
		if (e->sdl.menu_img == 23)
		{
			ft_menu_sound_2(e, 24, 39);
			e->sdl.mouse = 1;
		}
		else
		{
			ft_menu_sound_2(e, 23, 39);
			e->sdl.mouse = 0;
		}
	}
}
