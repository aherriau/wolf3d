/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_weapon.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:49:49 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 06:50:16 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_process_weapon(t_env *e)
{
	if (!e->player.dead)
	{
		e->player.weapon.process(e);
		if (e->player.ammo == 0 && e->player.weapon.animation_counter == 0)
		{
			e->player.weapon = ft_new_knife();
			e->player.shooting = 0;
		}
	}
}

void	ft_process_knife(t_env *e)
{
	if ((e->player.shooting) || e->player.weapon.animation_counter > 0)
	{
		e->player.weapon.animation_counter =
			(e->player.weapon.animation_counter + 1) % 4;
		e->player.shooting = 0;
		if (e->player.weapon.animation_counter == 3)
		{
			ft_player_attack(e);
		}
	}
}

void	ft_process_pistol(t_env *e)
{
	if ((e->player.shooting && e->player.ammo > 0) ||
		e->player.weapon.animation_counter > 0)
	{
		e->player.weapon.animation_counter =
			(e->player.weapon.animation_counter + 1) % 4;
		e->player.shooting = 0;
		if (e->player.weapon.animation_counter == 2)
		{
			ft_player_fire(e);
			e->player.ammo--;
		}
	}
}

void	ft_process_minigun(t_env *e)
{
	if ((e->player.shooting && e->player.ammo > 0) ||
		e->player.weapon.animation_counter > 0)
	{
		if (e->player.weapon.animation_counter == 2)
		{
			ft_player_fire(e);
			e->player.ammo--;
		}
		if (e->player.weapon.animation_counter == 3 &&
			e->player.shooting && e->player.ammo > 0)
		{
			ft_player_fire(e);
			e->player.weapon.animation_counter = 2;
		}
		else
			e->player.weapon.animation_counter =
				(e->player.weapon.animation_counter + 1) % 4;
	}
}

void	ft_process_smg(t_env *e)
{
	if ((e->player.shooting && e->player.ammo > 0) ||
		e->player.weapon.animation_counter > 0)
	{
		if (e->player.weapon.animation_counter == 3 &&
			(e->player.shooting || e->player.did_not_shoot) &&
			e->player.ammo > 0)
		{
			ft_player_fire(e);
			e->player.ammo--;
			if (e->player.shooting)
				e->player.weapon.animation_counter = 2;
		}
		else
			e->player.weapon.animation_counter =
			(e->player.weapon.animation_counter + 1) % 4;
	}
}
