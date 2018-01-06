/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 03:02:02 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 07:05:42 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_restore_health(t_player *player, int value)
{
	player->health = ft_min(player->health + value, 100);
}

void	ft_restore_ammo(t_player *player, int value)
{
	player->ammo = ft_min(player->ammo + value, 99);
}

void	ft_hurt_player(t_env *e, t_enemy *enemy)
{
	e->player.health = ft_max(e->player.health - enemy->weapon.damage, 0);
	e->player.hurt = 1;
	if (e->player.health == 0 && !e->player.dead)
	{
		e->player.died = 1;
		e->player.dead = 1;
		ft_play_sound(e, 16);
	}
	else if (!e->player.dead)
		ft_play_sound(e, 14);
}

void	ft_init_functions(t_env *e)
{
	e->itemfunc[0].func = &ft_pick_up_food;
	e->itemfunc[1].func = &ft_pick_up_medkit;
	e->itemfunc[2].func = &ft_pick_up_ammo;
	e->itemfunc[3].func = &ft_pick_up_cup;
	e->itemfunc[4].func = &ft_pick_up_diamond;
	e->itemfunc[5].func = &ft_pick_up_chest;
	e->itemfunc[6].func = &ft_pick_up_key;
	e->itemfunc[7].func = &ft_pick_up_smg;
	e->itemfunc[8].func = &ft_pick_up_minigun;
	e->itemfunc[9].func = &ft_pick_up_bowl;
}
