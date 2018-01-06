/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 06:43:13 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 06:44:08 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_move_forward_x(t_env *e)
{
	int		map_x;
	double	new_x;

	new_x = e->player.pos.x + e->player.s_width *
		(e->player.dir.x > 0 ? 1 : -1) +
		e->player.dir.x * e->player.speed_walk;
	if (e->map.data[map_x = (int)new_x][(int)(e->player.pos.y)].wall <= 0 &&
			e->map.data[map_x][(int)e->player.pos.y].item <= BLOCK_SPRITE_INDEX)
	{
		if (ft_no_enemy(e, new_x, e->player.pos.y))
			e->player.pos.x += e->player.dir.x * e->player.speed_walk;
	}
	else
	{
		if (e->player.dir.x < 0)
			e->player.pos.x = map_x + 1 + e->player.s_width;
		else
			e->player.pos.x = map_x - e->player.s_width;
	}
}

void	ft_move_forward_y(t_env *e)
{
	int		map_y;
	double	new_y;

	new_y = e->player.pos.y + e->player.s_width *
		(e->player.dir.y > 0 ? 1 : -1) +
		e->player.dir.y * e->player.speed_walk;
	if (e->map.data[(int)(e->player.pos.x)][map_y = (int)new_y].wall <= 0 &&
			e->map.data[(int)e->player.pos.x][map_y].item <= BLOCK_SPRITE_INDEX)
	{
		if (ft_no_enemy(e, e->player.pos.x, new_y))
			e->player.pos.y += e->player.dir.y * e->player.speed_walk;
	}
	else
	{
		if (e->player.dir.y < 0)
			e->player.pos.y = map_y + 1 + e->player.s_width;
		else
			e->player.pos.y = map_y - e->player.s_width;
	}
}

void	ft_move_backward_x(t_env *e)
{
	int		map_x;
	double	new_x;

	new_x = e->player.pos.x - e->player.s_width *
		(e->player.dir.x > 0 ? 1 : -1) -
		e->player.dir.x * e->player.speed_walk;
	if (e->map.data[map_x = (int)new_x][(int)(e->player.pos.y)].wall <= 0 &&
			e->map.data[map_x][(int)e->player.pos.y].item <= BLOCK_SPRITE_INDEX)
	{
		if (ft_no_enemy(e, new_x, e->player.pos.y))
			e->player.pos.x -= e->player.dir.x * e->player.speed_walk;
	}
	else
	{
		if (e->player.dir.x > 0)
			e->player.pos.x = map_x + 1 + e->player.s_width;
		else
			e->player.pos.x = map_x - e->player.s_width;
	}
}

void	ft_move_backward_y(t_env *e)
{
	int		map_y;
	double	new_y;

	new_y = e->player.pos.y - e->player.s_width *
		(e->player.dir.y > 0 ? 1 : -1) -
		e->player.dir.y * e->player.speed_walk;
	if (e->map.data[(int)(e->player.pos.x)][map_y = (int)new_y].wall <= 0 &&
			e->map.data[(int)e->player.pos.x][map_y].item <= BLOCK_SPRITE_INDEX)
	{
		if (ft_no_enemy(e, e->player.pos.x, new_y))
			e->player.pos.y -= e->player.dir.y * e->player.speed_walk;
	}
	else
	{
		if (e->player.dir.y > 0)
			e->player.pos.y = map_y + 1 + e->player.s_width;
		else
			e->player.pos.y = map_y - e->player.s_width;
	}
}
