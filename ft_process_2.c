/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 05:55:53 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 05:56:20 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_process_door_1(t_env *e)
{
	if (e->map.data[55][37].door_state == 0 && (int)e->player.pos.y <= 37)
	{
		ft_play_sound(e, 9);
		e->map.data[55][37].door_state = 1;
	}
	else if (e->map.data[55][37].door_state == 2)
	{
		if (e->player.pos.y <= 38)
			e->player.pos.y += e->player.dir.y * e->player.speed_walk;
		else
		{
			ft_play_sound(e, 9);
			e->map.data[55][37].door_state = 3;
			e->map.data[55][37].wall = 50;
			e->map.data[55][37].door_index = 1;
		}
	}
	if (e->map.data[55][37].door_state == 0)
		e->sdl.door = 0;
}

void	ft_process_door_2(t_env *e)
{
	if (e->map.data[48][4].door_state == 0 && (int)e->player.pos.x >= 48)
	{
		ft_play_sound(e, 9);
		e->map.data[48][4].door_state = 1;
	}
	else if (e->map.data[48][4].door_state == 2)
	{
		if (e->player.pos.x >= 48)
			e->player.pos.x += e->player.dir.x * e->player.speed_walk;
		else
		{
			ft_play_sound(e, 9);
			e->map.data[48][4].door_state = 3;
			e->map.data[48][4].wall = 50;
			e->map.data[48][4].door_index = 1;
		}
	}
	if (e->map.data[48][4].door_state == 0)
		e->sdl.door = 0;
}

void	ft_process_door_3(t_env *e)
{
	if (e->map.data[40][54].door_state == 0 && (int)e->player.pos.x <= 40)
	{
		ft_play_sound(e, 9);
		e->map.data[40][54].door_state = 1;
	}
	else if (e->map.data[40][54].door_state == 2)
	{
		if (e->player.pos.x <= 41)
			e->player.pos.x += e->player.dir.x * e->player.speed_walk;
		else
		{
			ft_play_sound(e, 9);
			e->map.data[40][54].door_state = 3;
			e->map.data[40][54].wall = 50;
			e->map.data[40][54].door_index = 1;
		}
	}
	if (e->map.data[40][54].door_state == 0)
		e->sdl.door = 0;
}

void	ft_process_door_4(t_env *e)
{
	if (e->map.data[48][46].door_state == 0 && (int)e->player.pos.y >= 46)
	{
		ft_play_sound(e, 9);
		e->map.data[48][46].door_state = 1;
	}
	else if (e->map.data[48][46].door_state == 2)
	{
		if (e->player.pos.y >= 46)
			e->player.pos.y += e->player.dir.y * e->player.speed_walk;
		else
		{
			ft_play_sound(e, 9);
			e->map.data[48][46].door_state = 3;
			e->map.data[48][46].wall = 50;
			e->map.data[48][46].door_index = 1;
		}
	}
	if (e->map.data[48][46].door_state == 0)
		e->sdl.door = 0;
}

void	ft_switch_process_door(t_env *e)
{
	if ((int)(e->sdl.d.x) == 55 && (int)(e->sdl.d.y) == 37)
		ft_process_door_1(e);
	else if ((int)(e->sdl.d.x) == 48 && (int)(e->sdl.d.y) == 4)
		ft_process_door_2(e);
	else if ((int)(e->sdl.d.x) == 40 && (int)(e->sdl.d.y) == 54)
		ft_process_door_3(e);
	else if ((int)(e->sdl.d.x) == 48 && (int)(e->sdl.d.y) == 46)
		ft_process_door_4(e);
}
