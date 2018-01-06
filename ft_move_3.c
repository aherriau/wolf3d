/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 06:44:12 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 06:44:46 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_move_right_x(t_env *e)
{
	int		map_x;
	double	new_x;

	new_x = e->player.pos.x + e->player.s_width *
		(e->player.plane.x > 0 ? 1 : -1) +
		e->player.plane.x * e->player.speed_walk;
	if (e->map.data[map_x = (int)new_x][(int)(e->player.pos.y)].wall <= 0 &&
			e->map.data[map_x][(int)e->player.pos.y].item <= BLOCK_SPRITE_INDEX)
	{
		if (ft_no_enemy(e, new_x, e->player.pos.y))
			e->player.pos.x += e->player.plane.x * e->player.speed_walk;
	}
	else
	{
		if (e->player.plane.x < 0)
			e->player.pos.x = map_x + 1 + e->player.s_width;
		else
			e->player.pos.x = map_x - e->player.s_width;
	}
}

void	ft_move_right_y(t_env *e)
{
	int		map_y;
	double	new_y;

	new_y = e->player.pos.y + e->player.s_width *
		(e->player.plane.y > 0 ? 1 : -1) +
		e->player.plane.y * e->player.speed_walk;
	if (e->map.data[(int)(e->player.pos.x)][map_y = (int)new_y].wall <= 0 &&
			e->map.data[(int)e->player.pos.x][map_y].item <= BLOCK_SPRITE_INDEX)
	{
		if (ft_no_enemy(e, e->player.pos.x, new_y))
			e->player.pos.y += e->player.plane.y * e->player.speed_walk;
	}
	else
	{
		if (e->player.plane.y < 0)
			e->player.pos.y = map_y + 1 + e->player.s_width;
		else
			e->player.pos.y = map_y - e->player.s_width;
	}
}

void	ft_move_left_x(t_env *e)
{
	int		map_x;
	double	new_x;

	new_x = e->player.pos.x - e->player.s_width *
		(e->player.plane.x > 0 ? 1 : -1) -
		e->player.plane.x * e->player.speed_walk;
	if (e->map.data[map_x = (int)new_x][(int)(e->player.pos.y)].wall <= 0 &&
			e->map.data[map_x][(int)e->player.pos.y].item <= BLOCK_SPRITE_INDEX)
	{
		if (ft_no_enemy(e, new_x, e->player.pos.y))
			e->player.pos.x -= e->player.plane.x * e->player.speed_walk;
	}
	else
	{
		if (e->player.plane.x > 0)
			e->player.pos.x = map_x + 1 + e->player.s_width;
		else
			e->player.pos.x = map_x - e->player.s_width;
	}
}

void	ft_move_left_y(t_env *e)
{
	int		map_y;
	double	new_y;

	new_y = e->player.pos.y - e->player.s_width *
		(e->player.plane.y > 0 ? 1 : -1) -
		e->player.plane.y * e->player.speed_walk;
	if (e->map.data[(int)(e->player.pos.x)][map_y = (int)new_y].wall <= 0 &&
			e->map.data[(int)e->player.pos.x][map_y].item <= BLOCK_SPRITE_INDEX)
	{
		if (ft_no_enemy(e, e->player.pos.x, new_y))
			e->player.pos.y -= e->player.plane.y * e->player.speed_walk;
	}
	else
	{
		if (e->player.plane.y > 0)
			e->player.pos.y = map_y + 1 + e->player.s_width;
		else
			e->player.pos.y = map_y - e->player.s_width;
	}
}
