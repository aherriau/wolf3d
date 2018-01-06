/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_surfaces_filter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 03:29:00 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 03:29:06 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_apply_pause_filter(t_env *e)
{
	int		i;
	int		j;
	int		*data;
	t_argb	argb;

	data = (int *)e->sdl.surface->pixels;
	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			argb.r = (data[i * W + j]) & 0xff;
			argb.g = (data[i * W + j] >> 8) & 0xff;
			argb.b = (data[i * W + j] >> 16) & 0xff;
			argb.r = ft_max(argb.r / 2, 0);
			argb.g = ft_max(argb.g / 2, 0);
			argb.b = ft_max(argb.b / 2, 0);
			data[i * W + j] = argb.r | (argb.g << 8) | (argb.b << 16);
			j++;
		}
		i++;
	}
}

void	ft_apply_pick_filter(t_env *e)
{
	int		i;
	int		j;
	int		*data;
	t_argb	argb;

	data = (int *)e->sdl.surface->pixels;
	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			argb.r = (data[i * W + j] >> 16) & 0xff;
			argb.g = (data[i * W + j] >> 8) & 0xff;
			argb.b = (data[i * W + j]) & 0xff;
			argb.r = ft_min(255, argb.r + e->sdl.filter_timer * 10);
			argb.g = ft_min(255, argb.g + e->sdl.filter_timer * 10);
			data[i * W + j] = (argb.r << 16) | (argb.g << 8) | argb.b;
			j++;
		}
		i++;
	}
}

void	ft_apply_hurt_filter(t_env *e)
{
	int		i;
	int		j;
	int		*data;
	t_argb	argb;

	data = (int *)e->sdl.surface->pixels;
	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			argb.r = (data[i * W + j] >> 16) & 0xff;
			argb.g = (data[i * W + j] >> 8) & 0xff;
			argb.b = (data[i * W + j]) & 0xff;
			argb.r = ft_min(255, argb.r + e->sdl.filter_timer * 20);
			data[i * W + j] = (argb.r << 16) | (argb.g << 8) | argb.b;
			j++;
		}
		i++;
	}
}

void	ft_apply_die_filter(t_env *e)
{
	int		i;
	int		j;
	int		*data;
	t_argb	argb;

	data = (int *)e->sdl.surface->pixels;
	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			argb.r = (data[i * W + j] >> 16) & 0xff;
			argb.g = (data[i * W + j] >> 8) & 0xff;
			argb.b = (data[i * W + j]) & 0xff;
			argb.r = ft_min(150, argb.r + e->sdl.filter_timer * 10);
			argb.g = ft_max(20, argb.g - e->sdl.filter_timer * 20);
			argb.b = ft_max(20, argb.b - e->sdl.filter_timer * 20);
			data[i * W + j] = (argb.r << 16) | (argb.g << 8) | argb.b;
			j++;
		}
		i++;
	}
}
