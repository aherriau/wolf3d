/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 05:47:36 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/05 07:02:06 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_init_map_2(t_env *e, t_maper *maper)
{
	maper->tab2 = ft_strsplit(maper->tab[maper->i], ',');
	e->map.data[maper->index][maper->i].wall = ft_atoi(maper->tab2[0]);
	if (maper->index == 0 ||
		maper->index == (e->map.height - 1) ||
		maper->i == 0 || maper->i == (e->map.width - 1))
	{
		if (e->map.data[maper->index][maper->i].wall == 0)
			e->map.data[maper->index][maper->i].wall = 1;
	}
	e->map.data[maper->index][maper->i].door_state = 0;
	e->map.data[maper->index][maper->i].door_index = 1;
	e->map.data[maper->index][maper->i].door_timer = 0;
}

void	ft_init_map_3(t_env *e, t_maper *maper)
{
	maper->enemy = &(e->map.enemies[maper->j]);
	maper->enemy->id = ft_atoi(maper->tab2[1]);
	maper->enemy->speed_walk = 0.35;
	maper->enemy->dead = 0;
	maper->enemy->side = 1;
	maper->enemy->triggered = 0;
	maper->enemy->boss = 0;
	maper->enemy->process = e->enemy_process[maper->enemy->id - 1].process;
	e->enemy_init[maper->enemy->id - 1].init(maper->enemy);
	maper->sprite = new_sprite(1, ft_atoi(maper->tab2[1]));
	maper->sprite->pos.x = maper->index + 0.5;
	maper->sprite->pos.y = maper->i + 0.5;
	if (rand() % 2 == 0)
	{
		maper->sprite->dir.x = 1;
		maper->sprite->dir.y = 0;
	}
	else
	{
		maper->sprite->dir.x = -1;
		maper->sprite->dir.y = 0;
	}
	maper->sprite->plane.x = 0;
	maper->sprite->plane.y = 0.66;
}

void	ft_init_map_4(t_env *e, t_maper *maper)
{
	maper->sprite->last_pos_seen.x = -1;
	maper->sprite->last_pos_seen.y = -1;
	maper->sprite->swipe_iterations = 0;
	if (!(maper->tmp =
		ft_lstnew_ptr((void *)(maper->sprite), sizeof(*(maper->sprite)))))
		ft_error("malloc error");
	ft_lstadd(&(e->map.sprites), maper->tmp);
	maper->enemy->sprite = (t_sprite *)(e->map.sprites->content);
	maper->enemy->pos_stack = NULL;
	if (!(maper->tmp =
		ft_lstnew_ptr((void *)
		(new_xy(maper->index + 0.5, maper->i + 0.5)), sizeof(e->player.pos))))
		ft_error("malloc error");
	ft_lstadd(&(maper->enemy->pos_stack), maper->tmp);
	maper->j++;
}

void	ft_init_map_5(t_env *e, t_maper *maper)
{
	if ((e->map.data[maper->index][maper->i].item =
		ft_atoi(maper->tab2[2])) > 0)
	{
		maper->sprite = new_sprite(2, ft_atoi(maper->tab2[2]));
		maper->sprite->pos.x = maper->index + 0.5;
		maper->sprite->pos.y = maper->i + 0.5;
		if (!(maper->tmp =
			ft_lstnew_ptr((void *)(maper->sprite), sizeof(*(maper->sprite)))))
			ft_error("malloc error");
		ft_lstadd(&(e->map.sprites), maper->tmp);
	}
	if (ft_atoi(maper->tab2[3]) == 1)
	{
		e->map.start.x = maper->index;
		e->map.start.y = maper->i;
	}
	else if (ft_atoi(maper->tab2[3]) == 2)
	{
		e->map.end.x = maper->index;
		e->map.end.y = maper->i;
	}
	ft_tabdel(maper->tab2);
	maper->i++;
}

void	ft_init_map(t_env *e, char *filename)
{
	t_maper maper;
	int		ret;

	ft_initialize_map(e);
	ft_init_map_1(e, filename, &maper);
	while ((ret = get_next_line(maper.fd, &(maper.line)) > 0))
		ft_process_init_map(e, &maper);
	ft_strdel(&(maper.line));
	close(maper.fd);
	if (ret == -2)
		ft_error("map is too big to be processed");
	if (ret == -1)
		ft_error("malloc error");
}
