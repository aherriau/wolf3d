/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_butcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 23:40:33 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 23:00:28 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_process_movement_butcher(t_env *e, t_enemy *this)
{
	if (this->sprite->state == ATTACK)
		this->sprite->animation_index = this->sprite->animation_movement;
	ft_process_can_see_player_boss(e, this);
	if (++this->sprite->fast_index % 5 == 0)
	{
		this->sprite->animation_index = (this->sprite->animation_index + 1) % 4;
		this->sprite->animation_movement = this->sprite->animation_index;
	}
}

void	ft_drop_item_butcher(t_env *e, t_enemy *this)
{
	int			i;
	int			has_other_dead;
	t_sprite	*sprite;

	sprite = NULL;
	i = 0;
	has_other_dead = 0;
	while (i < e->map.nb_enemy)
	{
		if (e->map.enemies[i].id == this->id &&
			e->map.enemies[i].dead && this != &(e->map.enemies[i]))
		{
			i += e->map.nb_enemy;
			has_other_dead = 1;
		}
		i++;
	}
	if (has_other_dead)
		e->player.kill_butcher = 1;
	ft_drop_item(e, this);
}

int		ft_process_boss_butcher_1(t_env *e, t_enemy *this)
{
	ft_look_toward_player(e, this);
	if (this->dead && this->sprite->animation_index ==
		this->index_die + this->die_count)
		return (1);
	if (!this->dead && this->health <= 0)
	{
		this->dead = 1;
		this->sprite->state = DIE;
		this->sprite->animation_index = this->index_die;
		ft_play_sound(e, this->index_death1);
	}
	if (!this->dead && this->sprite->state == MOVE)
		ft_process_movement_butcher(e, this);
	if (!this->dead && ft_can_see_player(e, this))
	{
		if (!this->triggered)
		{
			ft_play_sound(e, this->index_halt);
			this->triggered = 1;
		}
		if (this->sprite->state == ATTACK)
			this->attack(e, this);
	}
	return (0);
}

int		ft_process_boss_butcher(t_env *e, t_enemy *this)
{
	if (ft_process_boss_butcher_1(e, this))
		return (0);
	if (this->sprite->state == DIE &&
			this->sprite->animation_index <
			this->index_die + this->die_count)
	{
		this->sprite->fast_index = (this->sprite->fast_index + 1) % 2;
		if (this->sprite->fast_index == 0)
		{
			if (++this->sprite->animation_index ==
					this->index_die + this->die_count)
				ft_drop_item_butcher(e, this);
		}
	}
	return (1);
}
