/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 04:43:10 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/05 02:23:54 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_init_player_level_up_1(t_env *e)
{
	e->player.pos.x = e->map.start.x + 0.5;
	e->player.pos.y = e->map.start.y + 0.5;
	e->player.dir.x = -1;
	e->player.dir.y = 0;
	e->player.plane.x = 0;
	e->player.plane.y = 0.66;
	if (e->player.floor == 1)
	{
		e->player.old_dir_x = e->player.dir.x;
		e->player.dir.x = e->player.dir.x * cos(-(M_PI / 2))
			- e->player.dir.y * sin(-(M_PI / 2));
		e->player.dir.y = e->player.old_dir_x * sin(-(M_PI / 2))
			+ e->player.dir.y * cos(-(M_PI / 2));
		e->player.old_plane_x = e->player.plane.x;
		e->player.plane.x = e->player.plane.x * cos(-(M_PI / 2))
			- e->player.plane.y * sin(-(M_PI / 2));
		e->player.plane.y = e->player.old_plane_x * sin(-(M_PI / 2))
			+ e->player.plane.y * cos(-(M_PI / 2));
	}
	e->player.can_shoot = 1;
	e->player.speed_rotation = 0.05;
	e->player.s_width = 0.1;
}

void	ft_init_player_levelup(t_env *e)
{
	ft_init_player_level_up_1(e);
	e->player.sensitivity = 1;
	e->player.forward = 0;
	e->player.backward = 0;
	e->player.left = 0;
	e->player.right = 0;
	e->player.rotate_left = 0;
	e->player.rotate_right = 0;
	e->player.has_key = 0;
	e->player.shooting = 0;
	e->player.dead = 0;
	e->player.did_not_shoot = 0;
	e->player.current_filter = -1;
	e->player.nb_enter = 0;
	e->player.kill_vodoo = 0;
	e->player.kill_butcher = 0;
	e->player.score_floor = e->player.score;
}

void	ft_init_player_1(t_env *e)
{
	e->player.health = 100;
	e->player.win = 0;
	e->player.pos.x = e->map.start.x + 0.5;
	e->player.pos.y = e->map.start.y + 0.5;
	e->player.dir.x = -1;
	e->player.dir.y = 0;
	e->player.plane.x = 0;
	e->player.plane.y = 0.66;
	if (e->player.floor == 1)
	{
		e->player.old_dir_x = e->player.dir.x;
		e->player.dir.x = e->player.dir.x * cos(-(M_PI / 2))
			- e->player.dir.y * sin(-(M_PI / 2));
		e->player.dir.y = e->player.old_dir_x * sin(-(M_PI / 2))
			+ e->player.dir.y * cos(-(M_PI / 2));
		e->player.old_plane_x = e->player.plane.x;
		e->player.plane.x = e->player.plane.x * cos(-(M_PI / 2))
			- e->player.plane.y * sin(-(M_PI / 2));
		e->player.plane.y = e->player.old_plane_x * sin(-(M_PI / 2))
			+ e->player.plane.y * cos(-(M_PI / 2));
	}
	e->player.can_shoot = 1;
	e->player.speed_walk = 0.2;
	e->player.speed_rotation = 0.05;
	e->player.s_width = 0.1;
}

void	ft_init_player(t_env *e, int lives)
{
	e->player.lives = lives;
	ft_init_player_1(e);
	e->player.sensitivity = 1;
	e->player.forward = 0;
	e->player.backward = 0;
	e->player.left = 0;
	e->player.right = 0;
	e->player.rotate_left = 0;
	e->player.rotate_right = 0;
	e->player.has_key = 0;
	e->player.ammo = 15;
	e->player.score = 0;
	e->player.score_floor = 0;
	e->player.shooting = 0;
	e->player.dead = 0;
	e->player.did_not_shoot = 0;
	e->player.weapon = ft_new_pistol();
	e->player.best_weapon = 1;
	e->player.current_filter = -1;
	e->player.nb_enter = 0;
	e->player.kill_vodoo = 0;
	e->player.kill_butcher = 0;
}
