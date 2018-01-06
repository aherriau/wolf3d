/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_projectiles.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:06:37 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 22:41:21 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		ft_update_null_pointer_sprites(t_env *e)
{
	t_list *prev;
	t_list *current;

	prev = NULL;
	current = e->map.sprites;
	while (current != NULL)
	{
		if (((t_sprite *)(current->content))->is_freeable == 1)
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

void		ft_update_null_pointer_projectiles(t_env *e)
{
	t_list *prev;
	t_list *current;

	prev = NULL;
	current = e->map.projectiles;
	while (current != NULL)
	{
		if (((t_projectile *)(current->content))->is_freeable == 1)
		{
			if (prev == NULL)
				e->map.projectiles = current->next;
			else
				prev->next = current->next;
			free(current->content);
			free(current);
		}
		prev = current;
		current = current->next;
	}
}

void		ft_process_projectile_1(t_env *e, t_projectile *proj, int broken)
{
	if (broken == 1)
	{
		proj->sprite->is_freeable = 1;
		proj->is_freeable = 1;
		ft_update_null_pointer_sprites(e);
		ft_update_null_pointer_projectiles(e);
	}
	else if (proj->sprite->fast_index == 0)
		proj->sprite->animation_index =
			(proj->sprite->animation_index + 1) % proj->phases;
	if (!broken)
		proj->sprite->fast_index = (proj->sprite->fast_index + 1) % 4;
}

void		ft_process_projectile(t_env *e, t_projectile *proj)
{
	double	new_x;
	double	new_y;
	int		broken;

	broken = 0;
	new_x = proj->sprite->pos.x + proj->sprite->dir.x * proj->speed;
	new_y = proj->sprite->pos.y + proj->sprite->dir.y * proj->speed;
	if (fabs(proj->sprite->pos.x - e->player.pos.x) < 0.2 &&
		fabs(proj->sprite->pos.y - e->player.pos.y) < 0.2)
		ft_hurt_player(e, proj->enemy);
	else if ((int)new_y >= e->map.width ||
			(int)new_x >= e->map.height ||
			(int)new_x < 0 || (int)new_y < 0 ||
			e->map.data[(int)new_x][(int)new_y].wall > 0)
		broken = 1;
	else
	{
		proj->sprite->pos.x = new_x;
		proj->sprite->pos.y = new_y;
	}
	ft_process_projectile_1(e, proj, broken);
}

void		ft_process_projectiles(t_env *e)
{
	t_projectile	*proj;
	t_list			*ptr;

	ptr = e->map.projectiles;
	if (!e->player.dead)
	{
		while (ptr != NULL)
		{
			proj = (t_projectile *)(ptr->content);
			ft_process_projectile(e, proj);
			ptr = ptr->next;
		}
	}
}
