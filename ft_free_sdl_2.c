/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:51:58 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 03:35:32 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_free_sounds(t_env *e)
{
	int i;

	i = 0;
	while (i <= 5)
	{
		Mix_FreeMusic(e->sdl.music[i]);
		i++;
	}
	i = 0;
	while (i <= 44)
	{
		Mix_FreeChunk(e->sdl.sfx[i]);
		i++;
	}
}

void	ft_free_textures(t_env *e)
{
	int i;

	i = 0;
	while (i <= 45)
	{
		SDL_DestroyTexture(e->sdl.menu[i]);
		i++;
	}
	i = 0;
	while (i <= 23)
	{
		SDL_DestroyTexture(e->sdl.hud[i]);
		i++;
	}
}
