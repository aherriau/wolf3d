/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_enemy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 14:29:51 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/05 02:23:37 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_can_see_player(t_env *e, t_enemy *this)
{
	int				x;
	t_render_sprite	rs;

	x = 0;
	while (x < W)
	{
		e->raycast.camera_x = 2 * x / (double)W - 1;
		ft_can_see_player_1(e, this);
		ft_can_see_player_2(e);
		while (e->raycast.hit == 0)
			ft_can_see_player_3(e, this);
		ft_can_see_player_4(e);
		e->raycast.z_buff[x] = e->raycast.perp_wall_dist;
		x++;
	}
	ft_can_see_player_5(e, this, &rs);
	return (ft_can_see_player_6(e, &rs));
}

void	ft_process_can_see_player(t_env *e, t_enemy *this)
{
	int		move;

	if (this->sprite->fast_index == 0)
	{
		if (fabs(this->sprite->pos.x - e->player.pos.x) > this->range ||
				fabs(this->sprite->pos.y - e->player.pos.y) > this->range)
		{
			ft_process_can_see_player_1(e, this, &move);
			ft_process_can_see_player_2(e, this, &move);
			ft_process_can_see_player_3(e, this, move);
		}
		else
		{
			this->sprite->animation_index = 0;
			this->sprite->state = ATTACK;
		}
	}
	this->sprite->fast_index = (this->sprite->fast_index + 1) % 7;
}

void	ft_process_movement_ss(t_env *e, t_enemy *this)
{
	int		move;

	move = 0;
	if (ft_can_see_player(e, this))
		ft_process_can_see_player(e, this);
	else if (this->sprite->last_pos_seen.x != -1 &&
			this->sprite->last_pos_seen.y != -1)
		ft_look_for_player(e, this);
	else if (dist_player(*this, e) < this->ear_length)
		ft_look_toward_player(e, this);
	else
	{
		if (this->sprite->fast_index == 0)
		{
			ft_enemy_swipe(this, NULL);
			this->sprite->animation_index = get_index(e->player,
					*(this->sprite)) * this->move_frames;
		}
		this->sprite->fast_index = (this->sprite->fast_index +
				1) % this->rotation_speed;
	}
}

int		ft_process_ss(t_env *e, t_enemy *this)
{
	if (this->dead && this->sprite->animation_index == this->index_die +
			this->die_count)
		return (0);
	if (this->sprite->state == GOBACK)
		ft_go_back(e, this);
	if (this->sprite->state == SWIPE)
		ft_process_swipe(e, this);
	if (ft_can_see_player(e, this))
		ft_process_ss_process_1(e, this);
	if ((fabs(this->sprite->pos.x - e->player.pos.x) > this->range ||
			fabs(this->sprite->pos.y - e->player.pos.y) > this->range) &&
			this->sprite->state == ATTACK)
		this->sprite->state = MOVE;
	if (!this->dead && this->sprite->state == MOVE)
		ft_process_movement_ss(e, this);
	ft_process_ss_process_2(e, this);
	if (this->sprite->state == ATTACK)
		ft_attack(e, this);
	return (0);
}

void	ft_process_enemies(t_env *e)
{
	int		i;

	i = 0;
	if (!e->player.dead)
	{
		while (i < e->map.nb_enemy)
		{
			e->map.enemies[i].process(e, &(e->map.enemies[i]));
			i++;
		}
	}
}
