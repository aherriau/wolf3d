/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 03:26:15 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 04:19:41 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_keydown_door_1(t_env *e)
{
	if ((e->player.floor == 1 && (int)(e->player.pos.x + e->player.dir.x) == 40
		&& (int)(e->player.pos.y + e->player.dir.y) == 26) ||
		(e->player.floor == 2 && (int)(e->player.pos.x + e->player.dir.x) == 52
		&& (int)(e->player.pos.y + e->player.dir.y) == 58))
	{
		e->map.data[(int)(e->player.pos.x + e->player.dir.x)]
			[(int)(e->player.pos.y + e->player.dir.y)].wall = 70;
		ft_play_sound(e, 43);
		e->sdl.pause = 1;
		e->sdl.just_pause = 1;
		e->sdl.levelup = 1;
		return (1);
	}
	if (e->player.floor == 1 &&
		(int)(e->player.pos.x + e->player.dir.x) == 15 &&
		(int)(e->player.pos.y + e->player.dir.y) == 29)
	{
		if (e->map.secret_door == 0)
		{
			ft_play_sound(e, 27);
			e->map.secret_door = 1;
		}
		return (1);
	}
	return (0);
}

int		ft_keydown_door_2(t_env *e)
{
	if ((e->player.floor == 2 && (int)(e->player.pos.x + e->player.dir.x) == 55
		&& (int)(e->player.pos.y + e->player.dir.y) == 37) ||
		(e->player.floor == 3 &&
		(((int)(e->player.pos.x + e->player.dir.x) == 48
		&& (int)(e->player.pos.y + e->player.dir.y) == 4) ||
		((int)(e->player.pos.x + e->player.dir.x) == 40 &&
		(int)(e->player.pos.y + e->player.dir.y) == 54) ||
		((int)(e->player.pos.x + e->player.dir.x) == 48 &&
		(int)(e->player.pos.y + e->player.dir.y) == 46))))
	{
		e->sdl.d.x = e->player.pos.x + e->player.dir.x;
		e->sdl.d.y = e->player.pos.y + e->player.dir.y;
		if (((((int)(e->sdl.d.x) == 55 && (int)(e->sdl.d.y) == 37) ||
			((int)(e->sdl.d.x) == 48 && (int)(e->sdl.d.y) == 4)) &&
			e->player.nb_enter == 0) || ((int)(e->sdl.d.x) == 40 &&
			(int)(e->sdl.d.y) == 54 && e->player.nb_enter == 1) ||
			((int)(e->sdl.d.x) == 48 && (int)(e->sdl.d.y) == 46 &&
			e->player.nb_enter == 2 && e->player.kill_vodoo))
			ft_keydown_door_2_process(e);
		else
			ft_play_sound(e, 44);
		return (1);
	}
	return (0);
}

int		ft_keydown_door_3(t_env *e)
{
	if (e->player.floor == 2 &&
		(int)(e->player.pos.x + e->player.dir.x) == 44 &&
		(int)(e->player.pos.y + e->player.dir.y) == 56)
	{
		if (e->player.kill_butcher)
		{
			if (e->map.data[(int)(e->player.pos.x + e->player.dir.x)]
				[(int)(e->player.pos.y + e->player.dir.y)].door_state == 0)
			{
				e->map.data[(int)(e->player.pos.x + e->player.dir.x)]
					[(int)(e->player.pos.y + e->player.dir.y)].door_state = 1;
				ft_play_sound(e, 9);
			}
		}
		else
			ft_play_sound(e, 44);
		return (1);
	}
	return (0);
}

int		ft_keydown_door_4(t_env *e)
{
	if (e->player.floor == 3 &&
		(int)(e->player.pos.x + e->player.dir.x) == 2 &&
		(int)(e->player.pos.y + e->player.dir.y) == 48)
	{
		if (e->player.has_key)
		{
			if (e->map.data[(int)(e->player.pos.x + e->player.dir.x)]
				[(int)(e->player.pos.y + e->player.dir.y)].door_state == 0)
			{
				e->map.data[(int)(e->player.pos.x + e->player.dir.x)]
					[(int)(e->player.pos.y + e->player.dir.y)].door_state = 1;
				ft_play_sound(e, 9);
			}
		}
		else
			ft_play_sound(e, 44);
		return (1);
	}
	return (0);
}

void	ft_keydown_door(t_env *e)
{
	if (ft_keydown_door_1(e) == 1)
		return ;
	if (ft_keydown_door_2(e) == 1)
		return ;
	if (ft_keydown_door_3(e) == 1)
		return ;
	if (ft_keydown_door_4(e) == 1)
		return ;
	if (e->map.data[(int)(e->player.pos.x + e->player.dir.x)]
		[(int)(e->player.pos.y + e->player.dir.y)].wall == 50)
	{
		if (e->map.data[(int)(e->player.pos.x + e->player.dir.x)]
			[(int)(e->player.pos.y + e->player.dir.y)].door_state == 0)
		{
			e->map.data[(int)(e->player.pos.x + e->player.dir.x)]
				[(int)(e->player.pos.y + e->player.dir.y)].door_state = 1;
			ft_play_sound(e, 9);
		}
	}
}
