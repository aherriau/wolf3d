/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:08:04 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 19:14:42 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double	dist(t_sprite *s1, t_player player)
{
	return (pow(s1->pos.x - player.pos.x, 2) +
			pow(s1->pos.y - player.pos.y, 2));
}

int		cmp_dist(void *sprite1, void *sprite2, t_env *e)
{
	t_sprite *s1;
	t_sprite *s2;

	s1 = (t_sprite *)(sprite1);
	s2 = (t_sprite *)(sprite2);
	return (dist(s1, e->player) - dist(s2, e->player));
}

void	sort_sprites(t_env *e)
{
	t_list	*list_ptr;
	int		had_changes;
	void	*tmp;

	if (e->map.sprites == NULL)
		return ;
	had_changes = 1;
	while (had_changes == 1)
	{
		had_changes = 0;
		list_ptr = e->map.sprites;
		while (list_ptr->next != NULL)
		{
			if (cmp_dist(list_ptr->content, list_ptr->next->content, e) < 0)
			{
				tmp = list_ptr->content;
				list_ptr->content = list_ptr->next->content;
				list_ptr->next->content = tmp;
				had_changes = 1;
			}
			list_ptr = list_ptr->next;
		}
	}
}

void	ft_render_weapon(t_env *e)
{
	SDL_Surface	*surface;
	t_weapon	weap;

	weap = e->player.weapon;
	surface = e->dtex.hud[weap.id].s[weap.animation_counter];
	if (SDL_BlitScaled(surface, NULL, e->sdl.surface, &(e->sdl.screen)) < 0)
		ft_error("SDL malloc error");
}
