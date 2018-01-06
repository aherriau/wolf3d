/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_sounds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:41:54 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/05 07:37:24 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_play_sound(t_env *e, int index)
{
	if (e->sdl.sound)
		Mix_PlayChannel(-1, e->sdl.sfx[index], 0);
}

void	ft_play_music(t_env *e, int index)
{
	if (e->sdl.musik)
		Mix_PlayMusic(e->sdl.music[index], 1);
}
