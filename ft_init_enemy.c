/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ennemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 21:32:55 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 06:34:46 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_butcher(t_enemy *this)
{
	this->weapon.id = 31;
	this->range = 64;
	this->health = 2500;
	this->weapon.fire_rate = 2;
	this->weapon.damage = 33;
	this->drop = SMG;
	this->index_die = 6;
	this->die_count = 3;
	this->attack = &ft_butcher_attack;
	this->index_halt = 23;
	this->index_death1 = 31;
	this->boss = 1;
}

void	init_sergent(t_enemy *this)
{
	this->range = 7;
	this->health = 200;
	this->speed_walk = 0.4;
	this->reaction_time = 5;
	this->move_frames = 4;
	this->weapon.fire_rate = 2;
	this->weapon.damage = 33;
	this->drop = CHEST;
	this->index_die = 6;
	this->die_count = 3;
	this->attack = &ft_sergent_attack;
	this->index_halt = 23;
	this->index_death1 = 31;
	this->boss = 1;
}

void	init_vodoo(t_enemy *this)
{
	this->weapon.id = 31;
	this->range = 30;
	this->health = 7000;
	this->speed_walk = 0.4;
	this->weapon.fire_rate = 2;
	this->weapon.damage = 34;
	this->drop = CUP;
	this->index_die = 5;
	this->die_count = 5;
	this->attack = &ft_vodoo_attack;
	this->index_halt = 23;
	this->index_death1 = 32;
	this->boss = 1;
}

void	init_hitler(t_enemy *this)
{
	this->weapon.id = 31;
	this->range = 200;
	this->health = 8000;
	this->speed_walk = 0.4;
	this->weapon.fire_rate = 2;
	this->weapon.damage = 7;
	this->drop = -1;
	this->index_die = 17;
	this->die_count = 7;
	this->attack = &ft_hitler_attack;
	this->index_halt = 23;
	this->index_death1 = 36;
	this->boss = 1;
	this->phase = 1;
}
