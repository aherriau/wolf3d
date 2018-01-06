/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_sergent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:03:47 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 21:33:58 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_go_back_sergent_2(t_enemy *this, t_xy next_pos)
{
	double norme;

	this->sprite->dir.x = next_pos.x - this->sprite->pos.x;
	this->sprite->dir.y = next_pos.y - this->sprite->pos.y;
	norme = sqrt(pow(this->sprite->dir.x, 2) +
			pow(this->sprite->dir.y, 2));
	if (norme != 0)
	{
		this->sprite->dir.x /= norme;
		this->sprite->dir.y /= norme;
	}
	this->sprite->plane.x = -this->sprite->dir.y;
	this->sprite->plane.y = this->sprite->dir.x;
	this->sprite->pos.x = next_pos.x;
	this->sprite->pos.y = next_pos.y;
	if ((this->sprite->animation_index + 1)
			% this->move_frames == 0)
		this->sprite->animation_index++;
	this->sprite->animation_index =
		(this->sprite->animation_index + 1) % this->move_frames;
}

void	ft_go_back_sergent(t_env *e, t_enemy *this)
{
	t_list	*tmp;
	t_xy	next_pos;

	if (this->sprite->fast_index == 0)
	{
		if (ft_lstsize(this->pos_stack) == 1)
			this->sprite->state = MOVE;
		else
		{
			next_pos = ft_lstpop(&(this->pos_stack));
			if (e->map.data[(int)next_pos.x][(int)next_pos.y].wall == 50)
			{
				ft_go_back_sergent_1(e, next_pos);
				if (!(tmp = ft_lstnew_ptr((void *)
					(new_xy(next_pos.x, next_pos.y)), sizeof(t_xy))))
					ft_error("malloc error");
				ft_lstadd(&(this->pos_stack), tmp);
			}
			else
				ft_go_back_sergent_2(this, next_pos);
		}
	}
	this->sprite->fast_index = (this->sprite->fast_index + 1) % 7;
}

void	ft_sergent_attack_1(t_env *e, t_enemy *this)
{
	if (this->sprite->animation_index == 4)
	{
		this->sprite->fast_index = (this->sprite->fast_index + 1) % 10;
		if (this->sprite->fast_index == 0)
			this->sprite->animation_index = 5;
	}
	if (this->sprite->animation_index == 5)
	{
		if (this->sprite->fast_index == 0)
		{
			ft_play_sound(e, 1);
			this->first_shot = 0;
			ft_hurt_player(e, this);
		}
		this->sprite->fast_index =
			(this->sprite->fast_index + 1) % 10;
		if (this->sprite->fast_index == 0)
		{
			this->sprite->fast_index = 0;
			this->sprite->animation_index = 4;
		}
	}
}

int		ft_sergent_attack(t_env *e, t_enemy *this)
{
	if (ft_can_see_player(e, this))
	{
		if (!(this->sprite->animation_index >= 4 &&
					this->sprite->animation_index <= 5))
		{
			this->first_shot = 1;
			this->sprite->animation_index = 4;
			this->sprite->fast_index = 0;
		}
		else
			ft_sergent_attack_1(e, this);
	}
	else
	{
		this->sprite->state = MOVE;
		this->sprite->animation_index = 0;
	}
	return (0);
}

int		ft_process_sergent_1(t_env *e, t_enemy *this)
{
	this->sprite->init_dir = this->sprite->dir;
	if (this->dead && this->sprite->animation_index ==
			this->index_die + this->die_count)
		return (1);
	if (this->sprite->state == GOBACK)
		ft_go_back_sergent(e, this);
	ft_look_toward_player(e, this);
	if (ft_can_see_player(e, this))
	{
		ft_look_toward_player(e, this);
		this->sprite->last_pos_seen.x = e->player.pos.x;
		this->sprite->last_pos_seen.y = e->player.pos.y;
		if (this->sprite->state == GOBACK || this->sprite->state == MOVE)
		{
			if (this->triggered == 0)
			{
				ft_play_sound(e, this->index_halt);
				this->triggered = 1;
			}
			this->sprite->state = ATTACK;
		}
	}
	else
		this->sprite->dir = this->sprite->init_dir;
	return (0);
}
