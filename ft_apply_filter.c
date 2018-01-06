/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_filter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 21:44:40 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 03:32:07 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_process_die_filter(t_env *e)
{
	if (e->player.died == 1)
	{
		e->player.current_filter = 3;
		e->sdl.filter_timer = 0;
	}
	ft_apply_die_filter(e);
	if (!e->sdl.pause)
		e->sdl.filter_timer++;
}

void	ft_process_pick_filter(t_env *e)
{
	if (e->player.picked == 1)
	{
		e->player.current_filter = 2;
		e->sdl.filter_timer = 10;
	}
	ft_apply_pick_filter(e);
	if (!e->sdl.pause)
		e->sdl.filter_timer--;
}

void	ft_process_hurt_filter(t_env *e)
{
	if (e->player.hurt == 1)
	{
		e->player.current_filter = 1;
		e->sdl.filter_timer = 10;
	}
	ft_apply_hurt_filter(e);
	if (!e->sdl.pause)
		e->sdl.filter_timer--;
}

void	ft_apply_filter(t_env *e)
{
	if (e->player.died == 1 ||
		(e->sdl.filter_timer <= 40 && e->player.current_filter == 3))
		ft_process_die_filter(e);
	else if (e->player.picked == 1 ||
		(e->sdl.filter_timer > 0 && e->player.current_filter == 2))
		ft_process_pick_filter(e);
	else if (e->player.hurt == 1 ||
		(e->sdl.filter_timer > 0 && e->player.current_filter == 1))
		ft_process_hurt_filter(e);
	if (e->sdl.pause && !e->sdl.levelup)
		ft_apply_pause_filter(e);
}
