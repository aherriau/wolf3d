/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_enemy_sprites_3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 04:32:47 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 04:40:43 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_init_enemy_sprites_3_1(t_env *e)
{
	e->dtex.enemy[5].s[0] = ld_s("pics/butcher/move_0.png");
	e->dtex.enemy[5].s[1] = ld_s("pics/butcher/move_1.png");
	e->dtex.enemy[5].s[2] = ld_s("pics/butcher/move_2.png");
	e->dtex.enemy[5].s[3] = ld_s("pics/butcher/move_3.png");
	e->dtex.enemy[5].s[4] = ld_s("pics/butcher/attack_0.png");
	e->dtex.enemy[5].s[5] = ld_s("pics/butcher/attack_1.png");
	e->dtex.enemy[5].s[6] = ld_s("pics/butcher/die_0.png");
	e->dtex.enemy[5].s[7] = ld_s("pics/butcher/die_1.png");
	e->dtex.enemy[5].s[8] = ld_s("pics/butcher/die_2.png");
	e->dtex.enemy[5].s[9] = ld_s("pics/butcher/die_3.png");
	e->dtex.enemy[6].s[0] = ld_s("pics/spike_boss/move_0.png");
	e->dtex.enemy[6].s[1] = ld_s("pics/spike_boss/move_1.png");
	e->dtex.enemy[6].s[2] = ld_s("pics/spike_boss/move_2.png");
	e->dtex.enemy[6].s[3] = ld_s("pics/spike_boss/move_3.png");
	e->dtex.enemy[6].s[4] = ld_s("pics/spike_boss/attack_0.png");
	e->dtex.enemy[6].s[5] = ld_s("pics/spike_boss/attack_1.png");
	e->dtex.enemy[6].s[6] = ld_s("pics/spike_boss/attack_2.png");
	e->dtex.enemy[6].s[7] = ld_s("pics/spike_boss/die_0.png");
	e->dtex.enemy[6].s[8] = ld_s("pics/spike_boss/die_1.png");
	e->dtex.enemy[6].s[9] = ld_s("pics/spike_boss/die_2.png");
	e->dtex.enemy[6].s[10] = ld_s("pics/spike_boss/die_3.png");
	e->dtex.enemy[7].s[0] = ld_s("pics/hitler_float/move_0.png");
	e->dtex.enemy[7].s[1] = ld_s("pics/hitler_float/move_1.png");
	e->dtex.enemy[7].s[2] = ld_s("pics/hitler_float/move_2.png");
	e->dtex.enemy[7].s[3] = ld_s("pics/hitler_float/move_3.png");
}

void	ft_init_enemy_sprites_3_2(t_env *e)
{
	e->dtex.enemy[7].s[4] = ld_s("pics/hitler_float/attack_0.png");
	e->dtex.enemy[7].s[5] = ld_s("pics/hitler_float/die_0.png");
	e->dtex.enemy[7].s[6] = ld_s("pics/hitler_float/die_1.png");
	e->dtex.enemy[7].s[7] = ld_s("pics/hitler_float/die_2.png");
	e->dtex.enemy[7].s[8] = ld_s("pics/hitler_float/die_3.png");
	e->dtex.enemy[7].s[9] = ld_s("pics/hitler_float/die_4.png");
	e->dtex.enemy[7].s[10] = ld_s("pics/hitler_float/die_5.png");
	e->dtex.enemy[8].s[0] = ld_s("pics/hitler_meca/move_0.png");
	e->dtex.enemy[8].s[1] = ld_s("pics/hitler_meca/move_1.png");
	e->dtex.enemy[8].s[2] = ld_s("pics/hitler_meca/move_2.png");
	e->dtex.enemy[8].s[3] = ld_s("pics/hitler_meca/move_3.png");
	e->dtex.enemy[8].s[4] = ld_s("pics/hitler_meca/attack_0.png");
	e->dtex.enemy[8].s[5] = ld_s("pics/hitler_meca/attack_1.png");
	e->dtex.enemy[8].s[6] = ld_s("pics/hitler_meca/attack_2.png");
	e->dtex.enemy[8].s[7] = ld_s("pics/hitler_meca/die_0.png");
	e->dtex.enemy[8].s[8] = ld_s("pics/hitler_meca/die_1.png");
	e->dtex.enemy[8].s[9] = ld_s("pics/hitler_meca/die_2.png");
	e->dtex.enemy[8].s[10] = ld_s("pics/hitler_floor/move_0.png");
}

void	ft_init_enemy_sprites_3_3(t_env *e)
{
	e->dtex.enemy[8].s[11] = ld_s("pics/hitler_floor/move_1.png");
	e->dtex.enemy[8].s[12] = ld_s("pics/hitler_floor/move_2.png");
	e->dtex.enemy[8].s[13] = ld_s("pics/hitler_floor/move_3.png");
	e->dtex.enemy[8].s[14] = ld_s("pics/hitler_floor/attack_0.png");
	e->dtex.enemy[8].s[15] = ld_s("pics/hitler_floor/attack_1.png");
	e->dtex.enemy[8].s[16] = ld_s("pics/hitler_floor/attack_2.png");
	e->dtex.enemy[8].s[17] = ld_s("pics/hitler_floor/die_0.png");
	e->dtex.enemy[8].s[18] = ld_s("pics/hitler_floor/die_1.png");
	e->dtex.enemy[8].s[19] = ld_s("pics/hitler_floor/die_2.png");
	e->dtex.enemy[8].s[20] = ld_s("pics/hitler_floor/die_3.png");
	e->dtex.enemy[8].s[21] = ld_s("pics/hitler_floor/die_4.png");
	e->dtex.enemy[8].s[22] = ld_s("pics/hitler_floor/die_5.png");
	e->dtex.enemy[8].s[23] = ld_s("pics/hitler_floor/die_6.png");
	e->dtex.enemy[8].s[24] = ld_s("pics/hitler_floor/die_7.png");
}

void	ft_init_enemy_sprites_3(t_env *e)
{
	ft_init_enemy_sprites_3_1(e);
	ft_init_enemy_sprites_3_2(e);
	ft_init_enemy_sprites_3_3(e);
}

void	ft_init_enemy_sprites(t_env *e)
{
	ft_init_enemy_sprites_1(e);
	ft_init_enemy_sprites_2(e);
	ft_init_enemy_sprites_3(e);
}
