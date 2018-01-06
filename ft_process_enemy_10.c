/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_enemy_10.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 23:50:12 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 00:11:28 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_attack_process_2(t_env *e, t_enemy *this)
{
	if (this->sprite->animation_index == this->index_attack + 1)
	{
		ft_play_sound(e, this->weapon.id);
		this->first_shot = 0;
		ft_hurt_player(e, this);
		this->sprite->animation_index++;
	}
	else if (this->sprite->animation_index == this->index_attack + 2)
		this->sprite->animation_index = this->index_attack + 1;
	else
		this->sprite->animation_index++;
}

void	ft_attack_process_1(t_env *e, t_enemy *this)
{
	if (this->sprite->animation_index == this->index_attack)
		this->sprite->fast_index = (this->sprite->fast_index + 1) % 5;
	if (this->sprite->animation_index == this->index_attack + 1)
	{
		if (this->first_shot == 1)
			this->sprite->fast_index = (this->sprite->fast_index + 1) %
				this->reaction_time;
		else
			this->sprite->fast_index = (this->sprite->fast_index + 1) %
				this->weapon.fire_rate;
	}
	if (this->sprite->animation_index == this->index_attack + 2)
		this->sprite->fast_index = (this->sprite->fast_index + 1) % 5;
	if (this->sprite->fast_index == 0)
		ft_attack_process_2(e, this);
}

void	ft_attack(t_env *e, t_enemy *this)
{
	if (ft_can_see_player(e, this))
	{
		if (!(this->sprite->animation_index >= this->index_attack &&
					this->sprite->animation_index <= this->index_attack + 2))
		{
			this->first_shot = 1;
			this->sprite->animation_index = this->index_attack;
			this->sprite->fast_index = 0;
		}
		else
			ft_attack_process_1(e, this);
	}
	else
	{
		this->sprite->state = MOVE;
		this->sprite->animation_index = 0;
	}
}

void	ft_process_swipe(t_env *e, t_enemy *this)
{
	if (this->sprite->fast_index == 0)
	{
		ft_enemy_swipe(this, &(e->player));
		this->sprite->animation_index = get_index(e->player, *(this->sprite)) *
			this->move_frames;
	}
	this->sprite->fast_index = (this->sprite->fast_index + 1) % 10;
	if (this->sprite->swipe_iterations == 3)
		this->sprite->state = GOBACK;
}

void	ft_process_ss_process_1(t_env *e, t_enemy *this)
{
	ft_look_toward_player(e, this);
	this->sprite->last_pos_seen.x = e->player.pos.x;
	this->sprite->last_pos_seen.y = e->player.pos.y;
	if (this->sprite->state == SWIPE || this->sprite->state == GOBACK ||
			this->sprite->state == MOVE)
	{
		if (this->triggered == 0)
		{
			if (rand() % 2 == 0)
				ft_play_sound(e, this->index_achtung);
			else
				ft_play_sound(e, this->index_halt);
			this->triggered = 1;
		}
		this->sprite->state = ATTACK;
	}
}
