/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:42:12 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 04:02:14 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_init_sdl_menu_textures_1(t_env *e)
{
	e->sdl.menu[0] = ld_t(e->sdl.renderer, "./pics/menu/menu_open.png");
	e->sdl.menu[1] = ld_t(e->sdl.renderer, "./pics/menu/menu_option_1.png");
	e->sdl.menu[2] = ld_t(e->sdl.renderer, "./pics/menu/menu_option_2.png");
	e->sdl.menu[3] = ld_t(e->sdl.renderer, "./pics/menu/menu_option_3.png");
	e->sdl.menu[4] = ld_t(e->sdl.renderer, "./pics/menu/menu_game_1.png");
	e->sdl.menu[5] = ld_t(e->sdl.renderer, "./pics/menu/menu_game_2.png");
	e->sdl.menu[6] = ld_t(e->sdl.renderer, "./pics/menu/menu_game_3.png");
	e->sdl.menu[7] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_1.png");
	e->sdl.menu[8] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_2.png");
	e->sdl.menu[9] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_3.png");
	e->sdl.menu[10] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_4.png");
	e->sdl.menu[11] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_5.png");
	e->sdl.menu[12] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_6.png");
	e->sdl.menu[13] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_7.png");
	e->sdl.menu[14] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_8.png");
	e->sdl.menu[15] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_9.png");
	e->sdl.menu[16] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_10.png");
	e->sdl.menu[17] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_11.png");
	e->sdl.menu[18] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_12.png");
	e->sdl.menu[19] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_13.png");
	e->sdl.menu[20] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_14.png");
	e->sdl.menu[21] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_15.png");
	e->sdl.menu[22] = ld_t(e->sdl.renderer, "./pics/menu/menu_sound_16.png");
	e->sdl.menu[23] = ld_t(e->sdl.renderer, "./pics/menu/menu_control_1.png");
	e->sdl.menu[24] = ld_t(e->sdl.renderer, "./pics/menu/menu_control_2.png");
}

void	ft_init_sdl_menu_textures_2(t_env *e)
{
	e->sdl.menu[25] = ld_t(e->sdl.renderer, "./pics/menu/menu_game_1_back.png");
	e->sdl.menu[26] = ld_t(e->sdl.renderer, "./pics/menu/menu_game_2_back.png");
	e->sdl.menu[27] = ld_t(e->sdl.renderer, "./pics/menu/menu_game_3_back.png");
	e->sdl.menu[28] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_1_back.png");
	e->sdl.menu[29] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_2_back.png");
	e->sdl.menu[30] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_3_back.png");
	e->sdl.menu[31] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_4_back.png");
	e->sdl.menu[32] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_5_back.png");
	e->sdl.menu[33] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_6_back.png");
	e->sdl.menu[34] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_7_back.png");
	e->sdl.menu[35] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_8_back.png");
	e->sdl.menu[36] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_9_back.png");
}

void	ft_init_sdl_menu_textures(t_env *e)
{
	ft_init_sdl_menu_textures_1(e);
	ft_init_sdl_menu_textures_2(e);
	e->sdl.menu[37] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_10_back.png");
	e->sdl.menu[38] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_11_back.png");
	e->sdl.menu[39] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_12_back.png");
	e->sdl.menu[40] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_13_back.png");
	e->sdl.menu[41] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_14_back.png");
	e->sdl.menu[42] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_15_back.png");
	e->sdl.menu[43] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_sound_16_back.png");
	e->sdl.menu[44] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_control_1_back.png");
	e->sdl.menu[45] =
		ld_t(e->sdl.renderer, "./pics/menu/menu_control_2_back.png");
}

void	ft_init_sdl_hud_textures(t_env *e)
{
	e->sdl.hud[0] = ld_t(e->sdl.renderer, "./pics/display/cadre.png");
	e->sdl.hud[1] = ld_t(e->sdl.renderer, "./pics/display/hud_knife.png");
	e->sdl.hud[2] = ld_t(e->sdl.renderer, "./pics/display/hud_pistol.png");
	e->sdl.hud[3] = ld_t(e->sdl.renderer, "./pics/display/hud_smg.png");
	e->sdl.hud[4] = ld_t(e->sdl.renderer, "./pics/display/hud_minigun.png");
	e->sdl.hud[5] = ld_t(e->sdl.renderer, "./pics/display/hud_pause.png");
	e->sdl.hud[6] = ld_t(e->sdl.renderer, "./pics/display/hud_key.png");
	e->sdl.hud[7] = ld_t(e->sdl.renderer, "./pics/display/hud_0.png");
	e->sdl.hud[8] = ld_t(e->sdl.renderer, "./pics/display/hud_1.png");
	e->sdl.hud[9] = ld_t(e->sdl.renderer, "./pics/display/hud_2.png");
	e->sdl.hud[10] = ld_t(e->sdl.renderer, "./pics/display/hud_3.png");
	e->sdl.hud[11] = ld_t(e->sdl.renderer, "./pics/display/hud_4.png");
	e->sdl.hud[12] = ld_t(e->sdl.renderer, "./pics/display/hud_5.png");
	e->sdl.hud[13] = ld_t(e->sdl.renderer, "./pics/display/hud_6.png");
	e->sdl.hud[14] = ld_t(e->sdl.renderer, "./pics/display/hud_7.png");
	e->sdl.hud[15] = ld_t(e->sdl.renderer, "./pics/display/hud_8.png");
	e->sdl.hud[16] = ld_t(e->sdl.renderer, "./pics/display/hud_9.png");
	e->sdl.hud[17] = ld_t(e->sdl.renderer, "./pics/display/hud_face_1.png");
	e->sdl.hud[18] = ld_t(e->sdl.renderer, "./pics/display/hud_face_2.png");
	e->sdl.hud[19] = ld_t(e->sdl.renderer, "./pics/display/hud_face_3.png");
	e->sdl.hud[20] = ld_t(e->sdl.renderer, "./pics/display/hud_face_4.png");
	e->sdl.hud[21] = ld_t(e->sdl.renderer, "./pics/display/menu.png");
	e->sdl.hud[22] = ld_t(e->sdl.renderer, "./pics/display/game_over.png");
	e->sdl.hud[23] = ld_t(e->sdl.renderer, "./pics/display/win.png");
}
