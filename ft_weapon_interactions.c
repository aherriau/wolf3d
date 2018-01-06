/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weapon_interactions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 06:49:34 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 06:50:04 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_hurt(t_enemy *enemy, int value)
{
	enemy->health = enemy->health - value;
	if (!enemy->boss)
		enemy->sprite->state = HURT;
	enemy->triggered = 1;
}

double	dist_player(t_enemy enemy, t_env *e)
{
	return (pow(enemy.sprite->pos.x - e->player.pos.x, 2) +
			pow(enemy.sprite->pos.y - e->player.pos.y, 2));
}

void	ft_alert(t_env *e)
{
	int i;

	i = 0;
	while (i < e->map.nb_enemy)
	{
		if (dist_player(e->map.enemies[i], e) <= 100)
			ft_look_toward_player(e, &(e->map.enemies[i]));
		i++;
	}
}

void	ft_player_attack(t_env *e)
{
	int i;
	int val;

	i = 0;
	while (i < e->map.nb_enemy)
	{
		if ((val = (e->map.enemies[i].sprite->x_screen_end +
			e->map.enemies[i].sprite->x_screen_start) / 2) > 2 * W / 5
			&& val < 3 * W / 5 && !e->map.enemies[i].dead
			&& (pow(e->map.enemies[i].sprite->pos.x - e->player.pos.x, 2) +
			pow(e->map.enemies[i].sprite->pos.y - e->player.pos.y, 2) < 1))
		{
			ft_hurt(&(e->map.enemies[i]), e->player.weapon.damage);
			i += e->map.nb_enemy;
		}
		i++;
	}
	ft_play_sound(e, e->player.weapon.id);
}

void	ft_player_fire(t_env *e)
{
	int		i;
	int		val;
	double	dist;
	t_enemy *enemy;

	dist = 9e9;
	i = 0;
	enemy = NULL;
	while (i < e->map.nb_enemy)
	{
		if ((val = (e->map.enemies[i].sprite->x_screen_end +
			e->map.enemies[i].sprite->x_screen_start) / 2) > 2 * W / 5
			&& val < 3 * W / 5 &&
			!e->map.enemies[i].dead && dist_player(e->map.enemies[i], e) < dist)
		{
			enemy = &(e->map.enemies[i]);
			dist = dist_player(e->map.enemies[i], e);
		}
		i++;
	}
	ft_play_sound(e, e->player.weapon.id);
	if (enemy)
		ft_hurt(enemy, e->player.weapon.damage);
	e->player.did_not_shoot = 0;
	ft_alert(e);
}
