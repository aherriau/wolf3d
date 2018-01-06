/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:36:41 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 06:59:38 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	remove_list_sprite(t_env *e, double pos_x, double pos_y)
{
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	current = e->map.sprites;
	while (current != NULL)
	{
		if (((t_sprite *)(current->content))->pos.x == pos_x &&
		((t_sprite *)(current->content))->pos.y == pos_y &&
		(((t_sprite *)(current->content))->type == 2))
		{
			if (prev == NULL)
				e->map.sprites = current->next;
			else
				prev->next = current->next;
			free(current->content);
			free(current);
		}
		prev = current;
		current = current->next;
	}
}

void	ft_pick(t_env *e)
{
	int		map_x;
	int		map_y;
	int		item;

	map_x = (int)e->player.pos.x;
	map_y = (int)e->player.pos.y;
	if ((item = e->map.data[map_x][map_y].item) > 0 && item <= 10)
	{
		if (e->itemfunc[item - 1].func(e) == 1)
		{
			e->map.data[map_x][map_y].item = 0;
			e->player.picked = 1;
			remove_list_sprite(e, map_x + 0.5, map_y + 0.5);
		}
	}
}
