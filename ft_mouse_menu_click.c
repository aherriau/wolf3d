/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_menu_click.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 04:44:01 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 05:10:54 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_menu_sound_2(t_env *e, int menu_img, int sound)
{
	e->sdl.menu_img = menu_img;
	ft_play_sound(e, sound);
}

void	ft_options_menu_click_process(t_env *e)
{
	if (e->sdl.sound && e->sdl.musik)
		ft_menu_sound_2(e, 7, 40);
	else if (e->sdl.musik)
		ft_menu_sound_2(e, 11, 40);
	else if (e->sdl.sound)
		ft_menu_sound_2(e, 15, 40);
	else
		ft_menu_sound_2(e, 19, 40);
}

void	ft_options_menu_click(t_env *e, SDL_Event event)
{
	int		x;
	int		y;

	x = event.button.x;
	y = event.button.y;
	if (x >= 342 && x <= 842)
	{
		if (y >= 300 && y <= 353)
			ft_menu_sound_2(e, 4, 40);
		else if (y >= 353 && y <= 406)
			ft_options_menu_click_process(e);
		else if (y >= 406 && y <= 459)
		{
			if (e->sdl.mouse)
				ft_menu_sound_2(e, 24, 40);
			else
				ft_menu_sound_2(e, 23, 40);
		}
	}
}

void	ft_mouse_down_menu_back(t_env *e)
{
	if (e->sdl.menu_img > 24)
		e->sdl.menu_img -= 21;
	if (e->sdl.menu_img <= 6)
		e->sdl.menu_img = 1;
	else if (e->sdl.menu_img <= 22)
		e->sdl.menu_img = 2;
	else
		e->sdl.menu_img = 3;
}

void	ft_mouse_down_menu(t_env *e, SDL_Event event)
{
	int		x;
	int		y;

	if (e->sdl.menu_img <= 3)
		ft_options_menu_click(e, event);
	else
	{
		x = event.motion.x;
		y = event.motion.y;
		if (x >= 41 && x <= 174 && y >= 182 && y <= 219)
		{
			ft_mouse_down_menu_back(e);
			ft_play_sound(e, 40);
		}
		else
		{
			if (e->sdl.menu_img <= 6)
				ft_games_menu_click(e, event);
			else if (e->sdl.menu_img <= 22)
				ft_sounds_menu_click(e, event);
			else
				ft_controls_menu_click(e, event);
		}
	}
}
