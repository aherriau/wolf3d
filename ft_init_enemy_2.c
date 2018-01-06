/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_enemy_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 06:32:12 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 06:32:58 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_sa(t_enemy *this)
{
	this->health = 120;
	this->reaction_time = 12;
	this->rotation_speed = 8;
	this->weapon.fire_rate = 2;
	this->weapon.damage = 20;
	this->weapon.id = 2;
	this->drop = SMG;
	this->die_count = 3;
	this->move_frames = 5;
	this->range = 12;
	this->index_hurt_1 = 43;
	this->index_hurt_2 = 44;
	this->index_attack = 40;
	this->index_die = 45;
	this->ear_length = 30;
	this->index_achtung = 22;
	this->index_halt = 22;
	this->index_death1 = 12;
	this->index_death2 = 13;
}

void	init_ss(t_enemy *this)
{
	this->health = 100;
	this->reaction_time = 10;
	this->rotation_speed = 12;
	this->weapon.fire_rate = 15;
	this->weapon.damage = 15;
	this->weapon.id = 1;
	this->drop = AMMO;
	this->die_count = 3;
	this->move_frames = 5;
	this->range = 12;
	this->index_hurt_1 = 43;
	this->index_hurt_2 = 44;
	this->index_attack = 40;
	this->index_die = 45;
	this->ear_length = 10;
	this->index_achtung = 20;
	this->index_halt = 20;
	this->index_death1 = 12;
	this->index_death2 = 13;
}

void	init_white(t_enemy *this)
{
	this->weapon.id = 1;
	this->health = 100;
	this->reaction_time = 10;
	this->rotation_speed = 12;
	this->weapon.fire_rate = 15;
	this->weapon.damage = 20;
	this->drop = AMMO;
	this->die_count = 4;
	this->move_frames = 5;
	this->range = 12;
	this->index_hurt_1 = 43;
	this->index_hurt_2 = 44;
	this->index_attack = 40;
	this->index_die = 45;
	this->ear_length = 10;
	this->index_achtung = 23;
	this->index_halt = 22;
	this->index_death1 = 12;
	this->index_death2 = 13;
}

void	init_dog(t_enemy *this)
{
	this->weapon.id = 15;
	this->speed_walk = 0.6;
	this->health = 100;
	this->reaction_time = 1;
	this->rotation_speed = 20;
	this->weapon.fire_rate = 4;
	this->weapon.damage = 30;
	this->drop = -1;
	this->die_count = 2;
	this->move_frames = 4;
	this->range = 0.7;
	this->index_hurt_1 = 32;
	this->index_hurt_2 = 32;
	this->index_attack = 33;
	this->index_die = 36;
	this->ear_length = 200;
	this->index_achtung = 25;
	this->index_halt = 25;
	this->index_death1 = 26;
	this->index_death2 = 26;
}

void	init_spike_boss(t_enemy *this)
{
	this->weapon.id = 16;
	this->health = 500;
	this->weapon.fire_rate = 2;
	this->weapon.damage = 10;
	this->drop = MINIGUN;
	this->index_die = 7;
	this->die_count = 3;
	this->attack = &ft_spike_boss_attack;
	this->index_achtung = 24;
	this->index_halt = 24;
	this->index_death1 = 12;
	this->boss = 1;
}
