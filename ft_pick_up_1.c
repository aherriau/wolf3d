/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_up_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 03:05:06 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 03:05:38 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_pick_up_food(t_env *e)
{
	if (e->player.health != 100)
	{
		ft_restore_health(&(e->player), 10);
		ft_play_sound(e, 4);
		return (1);
	}
	return (0);
}

int	ft_pick_up_medkit(t_env *e)
{
	if (e->player.health != 100)
	{
		if (e->player.health <= 60)
			ft_play_sound(e, 28);
		ft_restore_health(&(e->player), 40);
		ft_play_sound(e, 4);
		return (1);
	}
	return (0);
}

int	ft_pick_up_bowl(t_env *e)
{
	if (e->player.health != 100)
	{
		ft_restore_health(&(e->player), 4);
		ft_play_sound(e, 4);
		return (1);
	}
	return (0);
}

int	ft_pick_up_ammo(t_env *e)
{
	if (e->player.ammo != 99)
		ft_play_sound(e, 5);
	if (e->player.ammo == 0)
	{
		if (e->player.best_weapon == 1)
			e->player.weapon = ft_new_pistol();
		if (e->player.best_weapon == 2)
			e->player.weapon = ft_new_smg(&(e->player));
		if (e->player.best_weapon == 3)
			e->player.weapon = ft_new_minigun(&(e->player));
	}
	if (e->player.ammo != 99)
	{
		ft_restore_ammo(&(e->player), 4);
		return (1);
	}
	return (0);
}

int	ft_pick_up_cup(t_env *e)
{
	e->player.score += 100;
	ft_play_sound(e, 4);
	return (1);
}
