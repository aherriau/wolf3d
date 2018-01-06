/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:52:59 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 07:37:53 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_menu_open(t_env *e, int *running)
{
	int			menu_timer;
	SDL_Event	event;
	SDL_Rect	rect;

	menu_timer = 1;
	while (menu_timer % 200 != 0)
	{
		while (SDL_PollEvent(&event))
		{
			if ((event.type == SDL_QUIT) || (event.type == SDL_KEYDOWN &&
					event.key.keysym.sym == SDLK_ESCAPE))
			{
				*running = 0;
				return ;
			}
		}
		rect.x = 0;
		rect.y = 0;
		rect.w = SCREENW;
		rect.h = SCREENH;
		SDL_RenderCopy(e->sdl.renderer, e->sdl.menu[0], NULL, &rect);
		SDL_RenderPresent(e->sdl.renderer);
		SDL_Delay(10);
		menu_timer++;
	}
}

void	ft_process_menu(t_env *e)
{
	SDL_Rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.w = SCREENW;
	rect.h = SCREENH;
	SDL_RenderCopy(e->sdl.renderer, e->sdl.menu[e->sdl.menu_img], NULL, &rect);
}

void	ft_process_music(t_env *e)
{
	if (e->sdl.musik && !Mix_PlayingMusic() && !e->transition)
	{
		if (e->menu)
			ft_play_music(e, 5);
		else
			ft_play_music(e, e->player.floor - 1);
	}
}

void	ft_process(t_env *e, int *running)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if ((event.type == SDL_QUIT) || (event.type == SDL_KEYDOWN &&
				event.key.keysym.sym == SDLK_ESCAPE))
			*running = 0;
		else if (event.type == SDL_KEYDOWN)
			ft_keydown(e, event);
		else if (event.type == SDL_KEYUP)
			ft_keyup(e, event);
		else if (event.type == SDL_MOUSEMOTION)
			ft_motion_mouse(e, event);
		else if (event.type == SDL_MOUSEBUTTONDOWN)
			ft_mouse_down(e, event);
		else if (event.type == SDL_MOUSEBUTTONUP)
			ft_mouse_up(e, event);
	}
	if (e->menu)
		ft_process_menu(e);
	else
		ft_process_game(e);
}

int		main(void)
{
	t_env	e;
	int		running;

	if (!ft_init(&e))
		return (1);
	running = 1;
	ft_menu_open(&e, &running);
	while (running)
	{
		ft_process(&e, &running);
		if (!e.sdl.pause || e.sdl.just_pause)
		{
			SDL_RenderPresent(e.sdl.renderer);
			e.sdl.just_pause = 0;
		}
		ft_process_music(&e);
		SDL_Delay(10);
	}
	SDL_DestroyWindow(e.sdl.window);
	ft_free_sdl(&e);
	Mix_Quit();
	SDL_Quit();
	return (0);
}
