/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:51:58 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 03:35:51 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_free_surfaces_enemies_1(t_env *e)
{
	int i;

	i = 0;
	while (i <= 48)
	{
		SDL_FreeSurface(e->dtex.enemy[0].s[i]);
		SDL_FreeSurface(e->dtex.enemy[1].s[i]);
		SDL_FreeSurface(e->dtex.enemy[2].s[i]);
		i++;
	}
	SDL_FreeSurface(e->dtex.enemy[2].s[49]);
	i = 0;
	while (i <= 38)
	{
		SDL_FreeSurface(e->dtex.enemy[3].s[i]);
		i++;
	}
}

void	ft_free_surfaces_enemies(t_env *e)
{
	int i;

	ft_free_surfaces_enemies_1(e);
	i = 0;
	while (i <= 9)
	{
		SDL_FreeSurface(e->dtex.enemy[4].s[i]);
		SDL_FreeSurface(e->dtex.enemy[5].s[i]);
		SDL_FreeSurface(e->dtex.enemy[6].s[i]);
		SDL_FreeSurface(e->dtex.enemy[7].s[i]);
		i++;
	}
	SDL_FreeSurface(e->dtex.enemy[6].s[10]);
	SDL_FreeSurface(e->dtex.enemy[7].s[10]);
	i = 0;
	while (i <= 24)
	{
		SDL_FreeSurface(e->dtex.enemy[8].s[i]);
		i++;
	}
}

void	ft_free_surfaces_others(t_env *e)
{
	int i;

	i = 0;
	while (i <= 4)
	{
		SDL_FreeSurface(e->dtex.hud[0].s[i]);
		SDL_FreeSurface(e->dtex.hud[1].s[i]);
		SDL_FreeSurface(e->dtex.hud[2].s[i]);
		SDL_FreeSurface(e->dtex.hud[3].s[i]);
		i++;
	}
	i = 0;
	while (i <= 3)
	{
		SDL_FreeSurface(e->dtex.projectile[1].s[i]);
		i++;
	}
	SDL_FreeSurface(e->dtex.projectile[0].s[0]);
	SDL_FreeSurface(e->dtex.projectile[0].s[1]);
}

void	ft_free_surfaces(t_env *e)
{
	int i;

	i = 0;
	while (i <= 141)
	{
		SDL_FreeSurface(e->stex.wall[i]);
		i++;
	}
	i = 0;
	while (i <= 48)
	{
		SDL_FreeSurface(e->stex.item[i]);
		i++;
	}
	ft_free_surfaces_enemies(e);
	ft_free_surfaces_others(e);
}

void	ft_free_sdl(t_env *e)
{
	ft_free_sounds(e);
	ft_free_textures(e);
	ft_free_surfaces(e);
}
