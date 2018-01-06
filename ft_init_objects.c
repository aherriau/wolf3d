/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 03:41:25 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 03:47:00 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_sprite	*new_sprite(int type, int number)
{
	t_sprite	*res;

	if (!(res = (t_sprite *)malloc(sizeof(t_sprite))))
		ft_error("malloc error");
	res->type = type;
	res->number = number;
	res->fast_index = 0;
	res->fast_index_2 = 0;
	res->animation_index = 0;
	res->animation_movement = 0;
	res->swipe_index = 0;
	res->state = MOVE;
	res->visible = 0;
	res->width = 64;
	res->height = 64;
	res->is_freeable = 0;
	return (res);
}

t_xy		*new_xy(double x, double y)
{
	t_xy	*res;

	if (!(res = (t_xy *)malloc(sizeof(t_xy))))
		ft_error("malloc error");
	res->x = x;
	res->y = y;
	return (res);
}
