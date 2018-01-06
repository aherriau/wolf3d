/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 06:20:25 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 06:21:50 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_initialize_map(t_env *e)
{
	e->map.secret_door = 0;
	e->map.secret_door_timer = 0;
	e->map.sprites = NULL;
	e->map.projectiles = NULL;
	e->map.secret_door = 0;
	e->map.secret_door_timer = 0;
}

void	ft_init_map_1(t_env *e, char *filename, t_maper *maper)
{
	if (!(e->map.data =
		(t_squaredata **)malloc(sizeof(t_squaredata *) * (e->map.height))))
		ft_error("malloc error");
	maper->i = 0;
	while (maper->i < e->map.height)
	{
		if (!(e->map.data[maper->i] =
			(t_squaredata *)malloc(sizeof(t_squaredata) * (e->map.width))))
			ft_error("malloc error");
		maper->i++;
	}
	if (!(e->map.enemies =
		(t_enemy *)malloc(sizeof(t_enemy) * (e->map.nb_enemy))))
		ft_error("malloc error");
	maper->fd = open(filename, O_RDONLY);
	if (maper->fd == -1)
	{
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_error("could not open the file");
	}
	maper->index = 0;
	maper->j = 0;
}
