/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sounds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:25:11 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 19:43:49 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Mix_Music	*ft_load_music(char *filename)
{
	Mix_Music	*res;

	if (!(res = Mix_LoadMUS(filename)))
	{
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_error("could not load the file");
	}
	return (res);
}

Mix_Chunk	*ft_load_sound(char *filename)
{
	Mix_Chunk	*res;

	if (!(res = Mix_LoadWAV(filename)))
	{
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_error("could not load the file");
	}
	return (res);
}

void		ft_init_sounds_1(t_env *e)
{
	e->sdl.music[0] = ft_load_music("sounds/music_0.mp3");
	e->sdl.music[1] = ft_load_music("sounds/lvl2.mp3");
	e->sdl.music[2] = ft_load_music("sounds/lvl3.mp3");
	e->sdl.music[3] = ft_load_music("sounds/game_over.wav");
	e->sdl.music[4] = ft_load_music("sounds/win.wav");
	e->sdl.music[5] = ft_load_music("sounds/menu.mp3");
	e->sdl.sfx[0] = ft_load_sound("sounds/Knife.wav");
	e->sdl.sfx[1] = ft_load_sound("sounds/Pistol.wav");
	e->sdl.sfx[2] = ft_load_sound("sounds/Machine Gun.wav");
	e->sdl.sfx[3] = ft_load_sound("sounds/Gatling Gun.wav");
	e->sdl.sfx[4] = ft_load_sound("sounds/Pickup.wav");
	e->sdl.sfx[5] = ft_load_sound("sounds/Ammo.wav");
	e->sdl.sfx[6] = ft_load_sound("sounds/Key.wav");
	e->sdl.sfx[7] = ft_load_sound("sounds/Boss Gun.wav");
	e->sdl.sfx[8] = ft_load_sound("sounds/Boss Gun.wav");
}

void		ft_init_sounds_2(t_env *e)
{
	e->sdl.sfx[9] = ft_load_sound("sounds/Door.wav");
	e->sdl.sfx[10] = ft_load_sound("sounds/Enemy Pain 1.wav");
	e->sdl.sfx[11] = ft_load_sound("sounds/Enemy Pain 2.wav");
	e->sdl.sfx[12] = ft_load_sound("sounds/Death 1.wav");
	e->sdl.sfx[13] = ft_load_sound("sounds/Death 2.wav");
	e->sdl.sfx[14] = ft_load_sound("sounds/Player Pain 1.wav");
	e->sdl.sfx[15] = ft_load_sound("sounds/Player Pain 2.wav");
	e->sdl.sfx[16] = ft_load_sound("sounds/Player Dies.wav");
	e->sdl.sfx[17] = ft_load_sound("sounds/Boss Gun.wav");
	e->sdl.sfx[18] = ft_load_sound("sounds/Halt.wav");
	e->sdl.sfx[19] = ft_load_sound("sounds/Halt.wav");
	e->sdl.sfx[20] = ft_load_sound("sounds/Halt.wav");
	e->sdl.sfx[21] = ft_load_sound("sounds/Halt 2.wav");
	e->sdl.sfx[22] = ft_load_sound("sounds/Halten Sie!.wav");
	e->sdl.sfx[23] = ft_load_sound("sounds/Achtung!.wav");
	e->sdl.sfx[24] = ft_load_sound("sounds/Guten Tag!.wav");
	e->sdl.sfx[25] = ft_load_sound("sounds/Dog.wav");
	e->sdl.sfx[26] = ft_load_sound("sounds/Dog Death.wav");
	e->sdl.sfx[27] = ft_load_sound("sounds/Secret Entrance.wav");
}

void		ft_init_sounds(t_env *e)
{
	ft_init_sounds_1(e);
	ft_init_sounds_2(e);
	e->sdl.sfx[28] = ft_load_sound("sounds/Health.wav");
	e->sdl.sfx[29] = ft_load_sound("sounds/Yeeeah!.wav");
	e->sdl.sfx[30] = ft_load_sound("sounds/knife_throw.wav");
	e->sdl.sfx[31] = ft_load_sound("sounds/Sheisse!.wav");
	e->sdl.sfx[32] = ft_load_sound("sounds/Thud!.wav");
	e->sdl.sfx[33] = ft_load_sound("sounds/fire_ball.wav");
	e->sdl.sfx[34] = ft_load_sound("sounds/Boss speak 1.wav");
	e->sdl.sfx[35] = ft_load_sound("sounds/Mechahitler Hoof.wav");
	e->sdl.sfx[36] = ft_load_sound("sounds/Sheisse-koph.wav");
	e->sdl.sfx[37] = ft_load_sound("sounds/destroy.wav");
	e->sdl.sfx[38] = ft_load_sound("sounds/hover.wav");
	e->sdl.sfx[39] = ft_load_sound("sounds/toggle.wav");
	e->sdl.sfx[40] = ft_load_sound("sounds/select.wav");
	e->sdl.sfx[41] = ft_load_sound("sounds/pause.wav");
	e->sdl.sfx[42] = ft_load_sound("sounds/unpause.wav");
	e->sdl.sfx[43] = ft_load_sound("sounds/Switch.wav");
	e->sdl.sfx[44] = ft_load_sound("sounds/door_error.wav");
}
