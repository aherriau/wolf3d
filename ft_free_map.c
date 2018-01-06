/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:21:15 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/03 22:24:59 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_pop_list(t_list **list)
{
	void	*content;
	void	*tmp;

	content = (*list)->content;
	tmp = *list;
	*list = (*list)->next;
	free(content);
	free(tmp);
}

void	ft_free_list(t_list **list)
{
	while (*list != NULL)
		ft_pop_list(list);
}

void	ft_free_data(t_env *e)
{
	int i;

	i = 0;
	while (i < e->map.height)
	{
		free(e->map.data[i]);
		i++;
	}
	free(e->map.data);
}

void	ft_free_enemies(t_env *e)
{
	int i;

	i = 0;
	while (i < e->map.nb_enemy)
	{
		ft_free_list(&(e->map.enemies[i].pos_stack));
		i++;
	}
	free(e->map.enemies);
}

void	ft_free_map(t_env *e)
{
	ft_free_list(&(e->map.sprites));
	ft_free_list(&(e->map.projectiles));
	ft_free_data(e);
	ft_free_enemies(e);
}
