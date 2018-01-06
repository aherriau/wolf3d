/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_others.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 04:19:36 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 04:23:31 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_init_item_sprites_1(t_env *e)
{
	e->stex.item[0] = ld_s("pics/props/food.png");
	e->stex.item[1] = ld_s("pics/props/medkit.png");
	e->stex.item[2] = ld_s("pics/props/ammo.png");
	e->stex.item[3] = ld_s("pics/props/cup.png");
	e->stex.item[4] = ld_s("pics/props/diamond.png");
	e->stex.item[5] = ld_s("pics/props/chest.png");
	e->stex.item[6] = ld_s("pics/props/key.png");
	e->stex.item[7] = ld_s("pics/props/smg.png");
	e->stex.item[8] = ld_s("pics/props/mingun.png");
	e->stex.item[9] = ld_s("pics/props/bowl.png");
	e->stex.item[10] = ld_s("pics/props/blood.png");
	e->stex.item[11] = ld_s("pics/props/water.png");
	e->stex.item[12] = ld_s("pics/props/lamp.png");
	e->stex.item[13] = ld_s("pics/props/lustre.png");
	e->stex.item[14] = ld_s("pics/props/skeleton2.png");
	e->stex.item[15] = ld_s("pics/props/pot.png");
	e->stex.item[16] = ld_s("pics/props/bones.png");
	e->stex.item[17] = ld_s("pics/props/armor.png");
	e->stex.item[18] = ld_s("pics/props/barrel.png");
	e->stex.item[19] = ld_s("pics/props/altar.png");
	e->stex.item[20] = ld_s("pics/props/cage.png");
	e->stex.item[21] = ld_s("pics/props/cooking.png");
	e->stex.item[22] = ld_s("pics/props/blood_cage_skulls.png");
	e->stex.item[23] = ld_s("pics/props/cooking2.png");
	e->stex.item[24] = ld_s("pics/props/crown.png");
}

void	ft_init_item_sprites(t_env *e)
{
	ft_init_item_sprites_1(e);
	e->stex.item[25] = ld_s("pics/props/filled_well.png");
	e->stex.item[26] = ld_s("pics/props/blood_cage.png");
	e->stex.item[27] = ld_s("pics/props/flag.png");
	e->stex.item[28] = ld_s("pics/props/hoven.png");
	e->stex.item[29] = ld_s("pics/props/jar.png");
	e->stex.item[30] = ld_s("pics/props/demon_statue.png");
	e->stex.item[31] = ld_s("pics/props/pillar.png");
	e->stex.item[32] = ld_s("pics/props/pillar2.png");
	e->stex.item[33] = ld_s("pics/props/sink.png");
	e->stex.item[34] = ld_s("pics/props/skeleton_caged.png");
	e->stex.item[35] = ld_s("pics/props/skeleton.png");
	e->stex.item[36] = ld_s("pics/props/skulls.png");
	e->stex.item[37] = ld_s("pics/props/spears.png");
	e->stex.item[38] = ld_s("pics/props/table.png");
	e->stex.item[39] = ld_s("pics/props/tree.png");
	e->stex.item[40] = ld_s("pics/props/well_blood.png");
	e->stex.item[41] = ld_s("pics/props/tree2.png");
	e->stex.item[42] = ld_s("pics/props/well.png");
	e->stex.item[43] = ld_s("pics/props/bidon.png");
	e->stex.item[44] = ld_s("pics/props/table2.png");
	e->stex.item[45] = ld_s("pics/props/sink.png");
	e->stex.item[46] = ld_s("pics/props/well_filled.png");
	e->stex.item[47] = ld_s("pics/props/lamp_foot.png");
	e->stex.item[48] = ld_s("pics/props/life.png");
}

void	ft_init_hud(t_env *e)
{
	e->dtex.hud[0].s[0] = ld_s("pics/hud/knife_0.png");
	e->dtex.hud[0].s[1] = ld_s("pics/hud/knife_1.png");
	e->dtex.hud[0].s[2] = ld_s("pics/hud/knife_2.png");
	e->dtex.hud[0].s[3] = ld_s("pics/hud/knife_3.png");
	e->dtex.hud[0].s[4] = ld_s("pics/hud/knife_4.png");
	e->dtex.hud[1].s[0] = ld_s("pics/hud/pistol_0.png");
	e->dtex.hud[1].s[1] = ld_s("pics/hud/pistol_1.png");
	e->dtex.hud[1].s[2] = ld_s("pics/hud/pistol_2.png");
	e->dtex.hud[1].s[3] = ld_s("pics/hud/pistol_3.png");
	e->dtex.hud[1].s[4] = ld_s("pics/hud/pistol_4.png");
	e->dtex.hud[2].s[0] = ld_s("pics/hud/smg_0.png");
	e->dtex.hud[2].s[1] = ld_s("pics/hud/smg_1.png");
	e->dtex.hud[2].s[2] = ld_s("pics/hud/smg_2.png");
	e->dtex.hud[2].s[3] = ld_s("pics/hud/smg_3.png");
	e->dtex.hud[2].s[4] = ld_s("pics/hud/smg_4.png");
	e->dtex.hud[3].s[0] = ld_s("pics/hud/minigun_0.png");
	e->dtex.hud[3].s[1] = ld_s("pics/hud/minigun_1.png");
	e->dtex.hud[3].s[2] = ld_s("pics/hud/minigun_2.png");
	e->dtex.hud[3].s[3] = ld_s("pics/hud/minigun_3.png");
	e->dtex.hud[3].s[4] = ld_s("pics/hud/minigun_4.png");
}

void	ft_init_projectiles(t_env *e)
{
	e->dtex.projectile[0].s[0] = ld_s("pics/hitler_float/projectile_0.png");
	e->dtex.projectile[0].s[1] = ld_s("pics/hitler_float/projectile_1.png");
	e->dtex.projectile[1].s[0] = ld_s("pics/butcher/knife_0.png");
	e->dtex.projectile[1].s[1] = ld_s("pics/butcher/knife_1.png");
	e->dtex.projectile[1].s[2] = ld_s("pics/butcher/knife_2.png");
	e->dtex.projectile[1].s[3] = ld_s("pics/butcher/knife_3.png");
}
