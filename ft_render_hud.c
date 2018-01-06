/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_hud.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 01:55:51 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 05:31:53 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_display_nbr(t_env *e, int nbr, int width)
{
	SDL_Rect	rect;

	rect.x = width;
	rect.y = 916;
	rect.w = 26;
	rect.h = 53;
	if (nbr >= 10)
	{
		ft_display_nbr(e, nbr / 10, width - 26);
		SDL_RenderCopy(e->sdl.renderer, e->sdl.hud[(nbr % 10) + 7],
				NULL, &rect);
	}
	else
		SDL_RenderCopy(e->sdl.renderer, e->sdl.hud[(nbr % 10) + 7],
				NULL, &rect);
}

void	ft_render_hud_1(t_env *e)
{
	SDL_Rect	screen_rect;
	SDL_Rect	weapon_rect;
	SDL_Rect	key_rect;

	screen_rect.x = 0;
	screen_rect.y = 0;
	screen_rect.w = SCREENW;
	screen_rect.h = SCREENH;
	if (!e->transition && !e->sdl.just_transitate)
		SDL_RenderCopy(e->sdl.renderer, e->sdl.hud[0], NULL, &screen_rect);
	weapon_rect.x = 842;
	weapon_rect.y = 874;
	weapon_rect.w = 211;
	weapon_rect.h = 111;
	SDL_RenderCopy(e->sdl.renderer, e->sdl.hud[e->player.weapon.id + 1],
			NULL, &weapon_rect);
	if (e->player.has_key)
	{
		key_rect.x = 815;
		key_rect.y = 874;
		key_rect.w = 27;
		key_rect.h = 54;
		SDL_RenderCopy(e->sdl.renderer, e->sdl.hud[6], NULL, &key_rect);
	}
}

void	ft_render_hud_2(t_env *e)
{
	SDL_Rect	face_rect;

	face_rect.x = 456;
	face_rect.y = 874;
	face_rect.w = 108;
	face_rect.h = 111;
	if (e->player.health == 0)
		SDL_RenderCopy(e->sdl.renderer, e->sdl.hud[20], NULL, &face_rect);
	else
	{
		if (e->sdl.hud_timer % 30 == 0)
		{
			e->sdl.hud_timer = 1;
			e->sdl.hud_face = rand() % 3;
		}
		else if (!e->sdl.pause)
			e->sdl.hud_timer++;
		SDL_RenderCopy(e->sdl.renderer, e->sdl.hud[e->sdl.hud_face + 17],
				NULL, &face_rect);
	}
}

void	ft_render_hud(t_env *e)
{
	ft_render_hud_1(e);
	ft_render_hud_2(e);
	ft_display_nbr(e, e->player.floor, 90);
	ft_display_nbr(e, e->player.score, 310);
	ft_display_nbr(e, e->player.lives, 388);
	ft_display_nbr(e, e->player.health, 628);
	ft_display_nbr(e, e->player.ammo, 758);
}
