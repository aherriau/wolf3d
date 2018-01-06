/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 23:44:27 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 03:19:11 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_open_door(t_env *e, int x, int y)
{
	if (e->map.data[x][y].door_state == 1)
	{
		if (e->map.data[x][y].door_timer >= 1)
		{
			e->map.data[x][y].door_state = 2;
			e->map.data[x][y].door_timer = 1;
			e->map.data[x][y].wall = -1;
		}
		else
			e->map.data[x][y].door_timer += 0.06;
	}
	else if (e->map.data[x][y].door_state == 3)
	{
		if (e->map.data[x][y].door_timer <= 0)
		{
			e->map.data[x][y].door_state = 0;
			e->map.data[x][y].door_timer = 0;
		}
		else
			e->map.data[x][y].door_timer -= 0.06;
	}
}

void	ft_close_door_2(t_env *e, int x, int y)
{
	if (e->player.pos.x >= x && e->player.pos.x <= (x + 1) &&
			e->player.pos.y >= y && e->player.pos.y <= (y + 1))
		e->map.data[x][y].door_index++;
	else
	{
		ft_play_sound(e, 9);
		e->map.data[x][y].door_state = 3;
		e->map.data[x][y].wall = 50;
		e->map.data[x][y].door_index = 1;
	}
}

void	ft_close_door(t_env *e, int x, int y)
{
	double	diff_x;
	double	diff_y;

	diff_x = 1;
	diff_y = 0.5;
	if (e->player.dir.y > 0.5)
	{
		diff_x = 0.5;
		diff_y = 1;
	}
	if ((abs((int)(e->player.pos.x - x - 0.5)) > diff_x ||
		abs((int)(e->player.pos.y - y - 0.5)) > diff_y) &&
		ft_no_enemy_door(e, x, y))
	{
		ft_play_sound(e, 9);
		e->map.data[x][y].door_state = 3;
		e->map.data[x][y].wall = 50;
		e->map.data[x][y].door_index = 1;
	}
	else if (e->map.data[x][y].door_index >= 70 && ft_no_enemy_door(e, x, y))
		ft_close_door_2(e, x, y);
	else
		e->map.data[x][y].door_index++;
}

void	ft_secret_door(t_env *e)
{
	if (e->map.secret_door == 1)
	{
		if (e->map.secret_door_timer >= 1)
		{
			if (e->map.height > 15 && e->map.width > 29)
				e->map.data[15][29].wall = 0;
			e->map.secret_door_timer = 0;
			e->map.secret_door = 2;
		}
		else
			e->map.secret_door_timer += 0.04;
	}
	else if (e->map.secret_door == 2)
	{
		if (e->map.secret_door_timer >= 1)
		{
			if (e->map.height > 15 && e->map.width > 28)
				e->map.data[15][28].wall = 0;
			e->map.secret_door = 3;
		}
		else
			e->map.secret_door_timer += 0.05;
	}
}

void	ft_door(t_env *e)
{
	int		x;
	int		y;

	x = 0;
	while (x < e->map.height)
	{
		y = 0;
		while (y < e->map.width)
		{
			if (e->map.data[x][y].wall == 50)
				ft_open_door(e, x, y);
			else if (e->map.data[x][y].wall == -1)
			{
				if (e->map.data[x][y].door_index % 50 == 0)
					ft_close_door(e, x, y);
				else
					e->map.data[x][y].door_index++;
			}
			y++;
		}
		x++;
	}
	ft_secret_door(e);
}
