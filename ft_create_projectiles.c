/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_projectiles.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 22:41:00 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 22:43:23 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			ft_set_knife_dir(t_env *e, t_sprite *sprite, t_enemy *this)
{
	double randx;
	double randy;
	double norme;

	randx = ((rand() % 1001) / 500.0) - 1;
	randy = ((rand() % 1001) / 500.0) - 1;
	sprite->dir.x = e->player.pos.x - this->sprite->pos.x + randx;
	sprite->dir.y = e->player.pos.y - this->sprite->pos.y + randy;
	norme = sqrt(pow(sprite->dir.x, 2) + pow(sprite->dir.y, 2));
	sprite->dir.x /= norme;
	sprite->dir.y /= norme;
}

t_projectile	*new_knife(t_env *e, t_enemy *this)
{
	t_projectile	*res;
	t_sprite		*sprite;
	t_list			*tmp;

	res = (t_projectile *)malloc(sizeof(t_projectile));
	res->enemy = this;
	res->is_freeable = 0;
	sprite = new_sprite(3, 2);
	res->id = 1;
	res->phases = 4;
	res->speed = 0.2;
	sprite->pos.x = this->sprite->pos.x;
	sprite->pos.y = this->sprite->pos.y;
	ft_set_knife_dir(e, sprite, this);
	if (!(tmp = ft_lstnew_ptr((void *)sprite, sizeof(t_sprite))))
		ft_error("malloc error");
	ft_lstadd(&(e->map.sprites), tmp);
	res->sprite = (t_sprite *)(e->map.sprites->content);
	return (res);
}

void			ft_compensate_dir(t_env *e, t_proj_dir *pdir)
{
	if (e->player.left && !e->player.right)
	{
		pdir->compensation_x = -150 * pow(e->player.speed_walk, 2) *
			e->player.plane.x;
		pdir->compensation_y = -150 * pow(e->player.speed_walk, 2) *
			e->player.plane.y;
		pdir->rand_x = ((rand() % 3001) / 1000.0) - 1.5;
		pdir->rand_y = ((rand() % 3001) / 1000.0) - 1.5;
	}
	if (e->player.right && !e->player.left)
	{
		pdir->compensation_x = 150 * pow(e->player.speed_walk, 2) *
			e->player.plane.x;
		pdir->compensation_y = 150 * pow(e->player.speed_walk, 2) *
			e->player.plane.y;
		pdir->rand_x = ((rand() % 3001) / 1000.0) - 1.5;
		pdir->rand_y = ((rand() % 3001) / 1000.0) - 1.5;
	}
}

void			ft_set_ball_dir(t_env *e, t_sprite *sprite, t_enemy *this)
{
	double		norme;
	t_proj_dir	pdir;

	pdir.compensation_x = 0;
	pdir.compensation_y = 0;
	pdir.rand_x = ((rand() % 1001) / 500.0) - 1;
	pdir.rand_y = ((rand() % 1001) / 500.0) - 1;
	if (rand() % 3 != 0)
		ft_compensate_dir(e, &pdir);
	sprite->dir.x = e->player.pos.x - this->sprite->pos.x +
		pdir.compensation_x + pdir.rand_x;
	sprite->dir.y = e->player.pos.y - this->sprite->pos.y +
		pdir.compensation_y + pdir.rand_y;
	norme = sqrt(pow(sprite->dir.x, 2) + pow(sprite->dir.y, 2));
	sprite->dir.x /= norme;
	sprite->dir.y /= norme;
}

t_projectile	*new_ball(t_env *e, t_enemy *this)
{
	t_projectile	*res;
	t_sprite		*sprite;
	t_list			*tmp;

	res = (t_projectile *)malloc(sizeof(t_projectile));
	res->enemy = this;
	res->is_freeable = 0;
	res->id = 0;
	sprite = new_sprite(3, 1);
	res->phases = 2;
	res->speed = 0.2;
	sprite->pos.x = this->sprite->pos.x;
	sprite->pos.y = this->sprite->pos.y;
	ft_set_ball_dir(e, sprite, this);
	if (!(tmp = ft_lstnew_ptr((void *)sprite, sizeof(t_sprite))))
		ft_error("malloc error");
	ft_lstadd(&(e->map.sprites), tmp);
	res->sprite = (t_sprite *)(e->map.sprites->content);
	return (res);
}
