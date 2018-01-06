/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_enemy_7.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 22:47:43 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 23:28:12 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_enemy_swipe(t_enemy *this, t_player *player)
{
	double	tmp_dirx;
	double	angle;

	tmp_dirx = this->sprite->dir.x;
	if (player == NULL)
	{
		this->sprite->dir.x = this->sprite->dir.x * cos(M_PI / 4) -
			this->sprite->dir.y * sin(M_PI / 4);
		this->sprite->dir.y = tmp_dirx * sin(M_PI / 4) + cos(M_PI / 4) *
			this->sprite->dir.y;
	}
	else
	{
		ft_enemy_swipe_process(this, &angle);
		this->sprite->dir.x = this->sprite->dir.x * cos(angle) -
			this->sprite->dir.y * sin(angle);
		this->sprite->dir.y = tmp_dirx * sin(angle) + cos(angle) *
			this->sprite->dir.y;
		this->sprite->swipe_index = (this->sprite->swipe_index + 1) % 4;
	}
	this->sprite->plane.x = -this->sprite->dir.y;
	this->sprite->plane.y = this->sprite->dir.x;
}

void	ft_process_can_see_player_1(t_env *e, t_enemy *this, int *move)
{
	int		map_x;
	double	new_x;

	new_x = this->sprite->pos.x + e->player.s_width *
		(this->sprite->dir.x > 0 ? 1 : -1) + this->sprite->dir.x *
		this->speed_walk;
	if (e->map.data[map_x = (int)new_x][(int)(this->sprite->pos.y)].wall <= 0 &&
			e->map.data[map_x]
			[(int)(this->sprite->pos.y)].item <= BLOCK_SPRITE_INDEX)
	{
		if (ft_no_enemy_beside(e, this, new_x, this->sprite->pos.y))
		{
			this->sprite->pos.x += this->sprite->dir.x * this->speed_walk;
			*move = 1;
		}
	}
}

void	ft_process_can_see_player_2(t_env *e, t_enemy *this, int *move)
{
	int		map_y;
	double	new_y;

	new_y = this->sprite->pos.y + e->player.s_width *
		(this->sprite->dir.y > 0 ? 1 : -1) + this->sprite->dir.y *
		this->speed_walk;
	if (e->map.data[(int)(this->sprite->pos.x)][map_y = (int)new_y].wall <= 0 &&
			e->map.data[(int)(this->sprite->pos.x)]
			[map_y].item <= BLOCK_SPRITE_INDEX)
	{
		if (ft_no_enemy_beside(e, this, this->sprite->pos.x, new_y))
		{
			this->sprite->pos.y += this->sprite->dir.y * this->speed_walk;
			*move = 1;
		}
	}
}

void	ft_process_can_see_player_3(t_env *e, t_enemy *this, int move)
{
	t_list	*tmp;

	if (!move || this->sprite->animation_index == 4)
		this->sprite->animation_index = this->move_frames *
			get_index(e->player, *(this->sprite));
	if (move)
	{
		this->sprite->animation_index = this->move_frames *
			get_index(e->player, *(this->sprite)) +
			(this->sprite->animation_index + 1) % this->move_frames;
		if (!(tmp = ft_lstnew_ptr((void *)(new_xy(this->sprite->pos.x,
								this->sprite->pos.y)), sizeof(t_xy))))
			ft_error("malloc error");
		ft_lstadd(&(this->pos_stack), tmp);
	}
}

void	ft_look_for_player_process_1(t_env *e, t_enemy *this, double *new_x,
		int *move)
{
	int		map_x;

	*new_x = this->sprite->pos.x + e->player.s_width *
		(this->sprite->dir.x > 0 ? 1 : -1) + this->sprite->dir.x *
		this->speed_walk;
	if (e->map.data[map_x = (int)(*new_x)]
			[(int)(this->sprite->pos.y)].wall <= 0)
	{
		if (e->map.data[map_x]
				[(int)(this->sprite->pos.y)].item <= BLOCK_SPRITE_INDEX)
		{
			if (ft_no_enemy_beside(e, this, *new_x, this->sprite->pos.y))
			{
				this->sprite->pos.x += this->sprite->dir.x * this->speed_walk;
				*move = 1;
			}
		}
	}
}
