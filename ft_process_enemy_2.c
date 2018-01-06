/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_enemy_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:17:01 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 21:42:41 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_no_enemy(t_env *e, double x, double y)
{
	int		i;

	i = 0;
	while (i < e->map.nb_enemy)
	{
		if (!e->map.enemies[i].dead &&
				fabs(e->map.enemies[i].sprite->pos.x - x) < 0.5 &&
				fabs(e->map.enemies[i].sprite->pos.y - y) < 0.5)
			return (0);
		i++;
	}
	return (1);
}

int		ft_no_enemy_door(t_env *e, int x, int y)
{
	int		i;

	i = 0;
	while (i < e->map.nb_enemy)
	{
		if (!e->map.enemies[i].dead &&
				e->map.enemies[i].sprite->pos.x >= (x - 1) &&
				e->map.enemies[i].sprite->pos.x <= (x + 1) &&
				e->map.enemies[i].sprite->pos.y >= (y - 1) &&
				e->map.enemies[i].sprite->pos.y <= (y + 1))
			return (0);
		i++;
	}
	return (1);
}

int		ft_no_enemy_beside(t_env *e, t_enemy *this, double x, double y)
{
	int		i;

	i = 0;
	while (i < e->map.nb_enemy)
	{
		if (&(e->map.enemies[i]) != this && !e->map.enemies[i].dead &&
				fabs(e->map.enemies[i].sprite->pos.x - x) < 0.5 &&
				fabs(e->map.enemies[i].sprite->pos.y - y) < 0.5)
			return (0);
		i++;
	}
	return (1);
}
