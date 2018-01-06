/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_butcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 23:40:33 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 22:59:27 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		get_speed(t_enemy *this)
{
	if (this->health <= 2500 && this->health >= 2250)
		return (7);
	if (this->health < 2250 && this->health >= 2000)
		return (6);
	if (this->health < 2000 && this->health >= 1750)
		return (5);
	if (this->health < 1750 && this->health >= 1500)
		return (4);
	if (this->health < 1500 && this->health >= 1250)
		return (3);
	return (2);
}

void	add_proj_butcher(t_env *e, t_enemy *this)
{
	t_projectile	*proj;
	t_list			*tmp;

	proj = new_knife(e, this);
	if (!(tmp = ft_lstnew_ptr((void *)proj, sizeof(t_projectile))))
		ft_error("malloc error");
	ft_lstadd(&(e->map.projectiles), tmp);
}

int		ft_butcher_attack(t_env *e, t_enemy *this)
{
	if (dist_player(*this, e) < this->range && ft_can_see_player(e, this))
	{
		if (this->sprite->fast_index_2 == 0)
		{
			if (this->sprite->state == MOVE)
			{
				this->sprite->state = ATTACK;
				this->sprite->animation_index = 4;
			}
			else if (this->sprite->animation_index == 5)
				this->sprite->animation_index = 4;
			else
			{
				ft_play_sound(e, 30);
				add_proj_butcher(e, this);
				this->sprite->animation_index = 5;
			}
		}
		this->sprite->fast_index_2 =
			(this->sprite->fast_index_2 + 1) % (get_speed(this));
	}
	else
		this->sprite->state = MOVE;
	return (0);
}

void	ft_process_can_see_player_boss_1(t_env *e, t_enemy *this, t_movement *m)
{
	m->new_x = this->sprite->pos.x + e->player.s_width *
		(this->sprite->dir.x > 0 ? 1 : -1) +
		this->sprite->dir.x * this->speed_walk;
	if (e->map.data[m->map_x = (int)m->new_x][(int)(this->sprite->pos.y)].
			wall <= 0 && e->map.data[m->map_x][(int)(this->sprite->pos.y)].
			item <= BLOCK_SPRITE_INDEX)
	{
		if (ft_no_enemy_beside(e, this, m->new_x, this->sprite->pos.y))
		{
			this->sprite->pos.x += this->sprite->dir.x * this->speed_walk;
			m->move = 1;
		}
	}
}

void	ft_process_can_see_player_boss(t_env *e, t_enemy *this)
{
	t_movement m;

	if (dist_player(*this, e) > this->range &&
			ft_can_see_player(e, this))
	{
		ft_process_can_see_player_boss_1(e, this, &m);
		m.new_y = this->sprite->pos.y + e->player.s_width *
			(this->sprite->dir.y > 0 ? 1 : -1) +
			this->sprite->dir.y * this->speed_walk;
		if (e->map.data[(int)(this->sprite->pos.x)][m.map_y = (int)m.new_y].
				wall <= 0 && e->map.data[(int)(this->sprite->pos.x)][m.map_y].
				item <= BLOCK_SPRITE_INDEX)
		{
			if (ft_no_enemy_beside(e, this, this->sprite->pos.x, m.new_y))
			{
				this->sprite->pos.y += this->sprite->dir.y * this->speed_walk;
				m.move = 1;
			}
		}
	}
	else
		this->sprite->state = ATTACK;
}
