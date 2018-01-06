/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_up_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 03:06:06 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 03:07:27 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_pick_up_diamond(t_env *e)
{
	e->player.score += 500;
	ft_play_sound(e, 4);
	return (1);
}

int	ft_pick_up_chest(t_env *e)
{
	e->player.score += 1000;
	ft_play_sound(e, 4);
	return (1);
}

int	ft_pick_up_key(t_env *e)
{
	e->player.has_key = 1;
	ft_play_sound(e, 6);
	return (1);
}

int	ft_pick_up_smg(t_env *e)
{
	int		val;

	val = 0;
	if (e->player.best_weapon != 3)
	{
		e->player.weapon = ft_new_smg(&(e->player));
		val = 1;
	}
	if (e->player.ammo == 0)
	{
		if (e->player.best_weapon == 2)
			e->player.weapon = ft_new_smg(&(e->player));
		if (e->player.best_weapon == 3)
			e->player.weapon = ft_new_minigun(&(e->player));
		val = 1;
	}
	if (e->player.ammo != 99)
	{
		val = 1;
		ft_restore_ammo(&(e->player), 20);
		ft_play_sound(e, 5);
	}
	return (val);
}

int	ft_pick_up_minigun(t_env *e)
{
	if (e->player.ammo == 99 && e->player.weapon.id == 3)
		return (0);
	if (e->player.weapon.id != 3)
		ft_play_sound(e, 29);
	else
		ft_play_sound(e, 5);
	e->player.weapon = ft_new_minigun(&(e->player));
	ft_restore_ammo(&(e->player), 30);
	return (1);
}
