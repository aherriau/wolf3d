/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:51:55 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 04:45:01 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_menu_sound(t_env *e, int menu_img)
{
	if (e->sdl.menu_img != menu_img)
	{
		e->sdl.menu_img = menu_img;
		ft_play_sound(e, 38);
	}
}

void	ft_options_menu(t_env *e, SDL_Event event)
{
	int		x;
	int		y;

	x = event.motion.x;
	y = event.motion.y;
	if (x >= 342 && x <= 842)
	{
		if (y >= 300 && y <= 353)
			ft_menu_sound(e, 1);
		else if (y >= 353 && y <= 406)
			ft_menu_sound(e, 2);
		else if (y >= 406 && y <= 459)
			ft_menu_sound(e, 3);
	}
}

void	ft_games_menu(t_env *e, SDL_Event event)
{
	int		x;
	int		y;

	x = event.motion.x;
	y = event.motion.y;
	if (x >= 432 && x <= 784)
	{
		if (y >= 330 && y <= 396)
			ft_menu_sound(e, 4);
		else if (y >= 396 && y <= 463)
			ft_menu_sound(e, 5);
		else if (y >= 463 && y <= 530)
			ft_menu_sound(e, 6);
	}
}

void	ft_sounds_menu(t_env *e, SDL_Event event)
{
	int		x;
	int		y;
	int		img_index;

	x = event.motion.x;
	y = event.motion.y;
	if (x >= 237 && x <= 962)
	{
		if (e->sdl.sound && e->sdl.musik)
			img_index = 7;
		else if (e->sdl.musik)
			img_index = 11;
		else if (e->sdl.sound)
			img_index = 15;
		else
			img_index = 19;
		if (y >= 317 && y <= 365)
			ft_menu_sound(e, img_index);
		else if (y >= 365 && y <= 418)
			ft_menu_sound(e, img_index + 1);
		else if (y >= 506 && y <= 554)
			ft_menu_sound(e, img_index + 2);
		else if (y >= 554 && y <= 607)
			ft_menu_sound(e, img_index + 3);
	}
}

void	ft_motion_mouse_menu(t_env *e, SDL_Event event)
{
	int		x;
	int		y;

	if (e->sdl.menu_img <= 3)
		ft_options_menu(e, event);
	else
	{
		x = event.motion.x;
		y = event.motion.y;
		if (x >= 41 && x <= 174 && y >= 182 && y <= 219)
		{
			if (e->sdl.menu_img <= 24)
				e->sdl.menu_img += 21;
		}
		else
		{
			if (e->sdl.menu_img > 24)
				e->sdl.menu_img -= 21;
		}
		if (e->sdl.menu_img <= 6)
			ft_games_menu(e, event);
		else if (e->sdl.menu_img <= 22)
			ft_sounds_menu(e, event);
	}
}
