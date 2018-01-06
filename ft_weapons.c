/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weapons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:03:02 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 05:17:29 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_weapon	ft_new_knife(void)
{
	t_weapon	weapon;

	weapon.damage = 34;
	weapon.id = 0;
	weapon.animation_counter = 0;
	weapon.process = &ft_process_knife;
	return (weapon);
}

t_weapon	ft_new_pistol(void)
{
	t_weapon	weapon;

	weapon.damage = 50;
	weapon.id = 1;
	weapon.animation_counter = 0;
	weapon.process = &ft_process_pistol;
	return (weapon);
}

t_weapon	ft_new_smg(t_player *player)
{
	t_weapon	weapon;

	weapon.damage = 75;
	weapon.id = 2;
	weapon.animation_counter = 0;
	weapon.process = &ft_process_smg;
	if (player->best_weapon < 2)
		player->best_weapon = 2;
	return (weapon);
}

t_weapon	ft_new_minigun(t_player *player)
{
	t_weapon	weapon;

	weapon.damage = 50;
	weapon.id = 3;
	weapon.animation_counter = 0;
	weapon.process = &ft_process_minigun;
	if (player->best_weapon < 3)
		player->best_weapon = 3;
	return (weapon);
}
