/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_enemy_8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 23:18:33 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 23:33:01 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_look_for_player_process_2(t_env *e, t_enemy *this, double *new_y,
		int *move)
{
	int		map_y;

	*new_y = this->sprite->pos.y + e->player.s_width *
		(this->sprite->dir.y > 0 ? 1 : -1) + this->sprite->dir.y *
		this->speed_walk;
	if (e->map.data[(int)(this->sprite->pos.x)]
			[map_y = (int)(*new_y)].wall <= 0)
	{
		if (e->map.data[(int)(this->sprite->pos.x)]
				[map_y].item <= BLOCK_SPRITE_INDEX)
		{
			if (ft_no_enemy_beside(e, this, this->sprite->pos.x, *new_y))
			{
				this->sprite->pos.y += this->sprite->dir.y * this->speed_walk;
				*move = 1;
			}
		}
	}
}

void	ft_look_for_player_process_3(t_env *e, t_enemy *this, int move)
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

void	ft_look_for_player_process(t_env *e, t_enemy *this)
{
	int		map_x;
	int		map_y;
	double	new_x;
	double	new_y;
	int		move;

	ft_look_for_player_process_1(e, this, &new_x, &move);
	ft_look_for_player_process_2(e, this, &new_y, &move);
	if (this->id != 4 && (e->map.data[map_x = (int)new_x]
		[(int)(this->sprite->pos.y)].wall == 50 ||
		e->map.data[(int)(this->sprite->pos.x)][map_y = (int)new_y].wall == 50))
	{
		if (e->map.data[map_x = (int)new_x]
				[(int)(this->sprite->pos.y)].door_state == 0)
			e->map.data[(int)new_x][(int)(this->sprite->pos.y)].door_state = 1;
		if (e->map.data[(int)(this->sprite->pos.x)]
				[map_y = (int)new_y].door_state == 0)
			e->map.data[(int)(this->sprite->pos.x)]
					[map_y = (int)new_y].door_state = 1;
	}
	ft_look_for_player_process_3(e, this, move);
}

void	ft_look_for_player(t_env *e, t_enemy *this)
{
	double	norme;

	this->sprite->dir.x = this->sprite->last_pos_seen.x - this->sprite->pos.x;
	this->sprite->dir.y = this->sprite->last_pos_seen.y - this->sprite->pos.y;
	norme = sqrt(pow(this->sprite->dir.x, 2) + pow(this->sprite->dir.y, 2));
	if (norme != 0)
	{
		this->sprite->dir.x /= norme;
		this->sprite->dir.y /= norme;
	}
	this->sprite->plane.x = -this->sprite->dir.y;
	this->sprite->plane.y = this->sprite->dir.x;
	if (fabs(this->sprite->pos.x - this->sprite->last_pos_seen.x) <
			this->speed_walk && fabs(this->sprite->pos.y -
				this->sprite->last_pos_seen.y) < this->speed_walk)
	{
		this->sprite->state = SWIPE;
		this->sprite->swipe_iterations = 0;
		this->sprite->last_pos_seen.x = -1;
		this->sprite->last_pos_seen.y = -1;
	}
	else if (this->sprite->fast_index == 0)
		ft_look_for_player_process(e, this);
	this->sprite->fast_index = (this->sprite->fast_index + 1) % 7;
}

void	ft_look_toward_player(t_env *e, t_enemy *this)
{
	double	norme;

	this->sprite->dir.x = e->player.pos.x - this->sprite->pos.x;
	this->sprite->dir.y = e->player.pos.y - this->sprite->pos.y;
	norme = sqrt(pow(this->sprite->dir.x, 2) + pow(this->sprite->dir.y, 2));
	if (norme != 0)
	{
		this->sprite->dir.x /= norme;
		this->sprite->dir.y /= norme;
	}
	this->sprite->plane.x = -this->sprite->dir.y;
	this->sprite->plane.y = this->sprite->dir.x;
}
