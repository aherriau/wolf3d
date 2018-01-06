/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_enemy_9.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 23:33:18 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 00:11:19 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_drop_item(t_env *e, t_enemy *this)
{
	int			map_x;
	int			map_y;
	t_list		*tmp;
	t_sprite	*sprite;

	if (e->map.data[map_x = (int)this->sprite->pos.x]
			[map_y = (int)this->sprite->pos.y].item == 0 && this->drop != -1)
	{
		e->map.data[map_x][map_y].item = this->drop;
		sprite = new_sprite(2, this->drop);
		sprite->pos.x = map_x + 0.5;
		sprite->pos.y = map_y + 0.5;
		if (!(tmp = ft_lstnew_ptr((void *)(sprite), sizeof(*sprite))))
			ft_error("malloc error");
		ft_lstadd(&(e->map.sprites), tmp);
	}
}

void	ft_go_back_1(t_env *e, t_enemy *this, t_xy next_pos)
{
	t_list	*tmp;

	if (this->id == 4)
	{
		ft_stackdel(&(this->pos_stack));
		if (!(tmp = ft_lstnew_ptr((void *)(new_xy(this->sprite->pos.x,
								this->sprite->pos.y)), sizeof(t_xy))))
			ft_error("malloc error");
		ft_lstadd(&(this->pos_stack), tmp);
	}
	else
	{
		if (e->map.data[(int)next_pos.x][(int)next_pos.y].door_state == 0)
			e->map.data[(int)next_pos.x][(int)next_pos.y].door_state = 1;
		if (!(tmp = ft_lstnew_ptr((void *)(new_xy(next_pos.x, next_pos.y)),
						sizeof(t_xy))))
			ft_error("malloc error");
		ft_lstadd(&(this->pos_stack), tmp);
	}
}

void	ft_go_back_2(t_env *e, t_enemy *this, t_xy next_pos)
{
	double	norme;

	this->sprite->dir.x = next_pos.x - this->sprite->pos.x;
	this->sprite->dir.y = next_pos.y - this->sprite->pos.y;
	norme = sqrt(pow(this->sprite->dir.x, 2) + pow(this->sprite->dir.y, 2));
	if (norme != 0)
	{
		this->sprite->dir.x /= norme;
		this->sprite->dir.y /= norme;
	}
	this->sprite->plane.x = -this->sprite->dir.y;
	this->sprite->plane.y = this->sprite->dir.x;
	this->sprite->pos.x = next_pos.x;
	this->sprite->pos.y = next_pos.y;
	if ((this->sprite->animation_index + 1) % this->move_frames == 0)
		this->sprite->animation_index++;
	this->sprite->animation_index = this->move_frames * ((get_index(e->player,
					*(this->sprite)) + 7) % 8) +
		(this->sprite->animation_index + 1) % this->move_frames;
}

void	ft_go_back(t_env *e, t_enemy *this)
{
	t_xy	next_pos;

	if (this->sprite->fast_index == 0)
	{
		if (ft_lstsize(this->pos_stack) == 1)
			this->sprite->state = MOVE;
		else
		{
			next_pos = ft_lstpop(&(this->pos_stack));
			if (e->map.data[(int)next_pos.x][(int)next_pos.y].wall == 50)
				ft_go_back_1(e, this, next_pos);
			else
				ft_go_back_2(e, this, next_pos);
		}
	}
	this->sprite->fast_index = (this->sprite->fast_index + 1) % 7;
}

void	ft_get_hurt(t_env *e, t_enemy *this)
{
	if (this->sprite->fast_index % 2 == 0)
	{
		if (this->sprite->animation_index != this->index_hurt_1 &&
				this->sprite->animation_index != this->index_hurt_2)
		{
			if (rand() % 2 == 0)
				this->sprite->animation_index = this->index_hurt_1;
			else
				this->sprite->animation_index = this->index_hurt_2;
			if (this->id != 4)
			{
				if (rand() % 2 == 0)
					ft_play_sound(e, 10);
				else
					ft_play_sound(e, 11);
			}
			this->sprite->fast_index = 0;
		}
		else
		{
			ft_look_toward_player(e, this);
			this->sprite->state = MOVE;
		}
	}
	this->sprite->fast_index++;
}
