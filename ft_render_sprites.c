/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:08:04 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/05 02:23:25 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_render_sprites_1(t_env *e, t_render_sprite *rs)
{
	rs->visible = 0;
	rs->sprite = (t_sprite *)(rs->ptr->content);
	rs->sprite_x = rs->sprite->pos.x - e->player.pos.x;
	rs->sprite_y = rs->sprite->pos.y - e->player.pos.y;
	rs->invdet = 1.0 / ((e->player.plane.x * e->player.dir.y) -
		(e->player.dir.x * e->player.plane.y));
	rs->transform_x = rs->invdet * (e->player.dir.y * rs->sprite_x -
		e->player.dir.x * rs->sprite_y);
	rs->transform_y = rs->invdet * (-e->player.plane.y * rs->sprite_x +
		e->player.plane.x * rs->sprite_y);
	rs->sprite_screen_x = (int)((W / 2) *
		(1 + rs->transform_x / rs->transform_y));
	rs->sprite_height = abs((int)(H / rs->transform_y));
	rs->draw_start_y = -rs->sprite_height / 2 + H / 2;
	if (rs->draw_start_y < 0)
		rs->draw_start_y = 0;
	rs->draw_end_y = rs->sprite_height / 2 + H / 2;
	if (rs->draw_end_y >= H)
		rs->draw_end_y = H - 1;
	rs->sprite_width = abs((int)(H / rs->transform_y));
	rs->draw_start_x = -rs->sprite_width / 2 + rs->sprite_screen_x;
}

void	ft_render_sprites_2(t_env *e, t_render_sprite *rs)
{
	if (rs->draw_start_x < 0)
		rs->draw_start_x = 0;
	rs->draw_end_x = rs->sprite_width / 2 + rs->sprite_screen_x;
	if (rs->draw_end_x >= W)
		rs->draw_end_x = W - 1;
	if (rs->sprite->type == 1)
		rs->data =
	(int *)e->dtex.enemy[rs->sprite->number - 1]
		.s[rs->sprite->animation_index]->pixels;
	else if (rs->sprite->type == 2)
		rs->data = (int *)e->stex.item[rs->sprite->number - 1]->pixels;
	else
		rs->data =
	(int *)e->dtex.projectile[rs->sprite->number - 1]
		.s[rs->sprite->animation_index]->pixels;
	rs->pix = (int *)e->sdl.surface->pixels;
	rs->stripe = rs->draw_start_x;
}

void	ft_render_sprites_3(t_env *e, t_render_sprite *rs)
{
	if (rs->transform_y > 0 && rs->stripe >= 0 && rs->stripe < W &&
			rs->transform_y < e->raycast.z_buff[rs->stripe])
	{
		if (!rs->visible)
		{
			rs->sprite->x_screen_start = rs->draw_start_x;
			rs->sprite->x_screen_end = rs->draw_end_x;
			rs->visible = 1;
		}
		rs->y = rs->draw_start_y;
		while (rs->y < rs->draw_end_y)
		{
			rs->d = rs->y * 256 - H * 128 + rs->sprite_height * 128;
			rs->texture_y = ((rs->d * rs->sprite->height)
					/ rs->sprite_height) / 256;
			rs->color = rs->data[rs->sprite->width *
				rs->texture_y + rs->texture_x];
			if ((rs->color & 0x00FFFFFF) != 0 && rs->y >= 0 && rs->y < H)
				rs->pix[rs->y * W + rs->stripe] = rs->color;
			rs->y++;
		}
	}
}

void	ft_render_sprites_4(t_env *e, t_render_sprite *rs)
{
	while (rs->stripe <= rs->draw_end_x)
	{
		rs->texture_x = (int)(256 * (rs->stripe -
		(-rs->sprite_width / 2 + rs->sprite_screen_x)) *
		rs->sprite->width / rs->sprite_width) / 256;
		ft_render_sprites_3(e, rs);
		rs->stripe++;
	}
}

void	ft_render_sprites(t_env *e)
{
	t_render_sprite rs;

	sort_sprites(e);
	rs.ptr = e->map.sprites;
	while (rs.ptr != NULL &&
			((dist((t_sprite *)(rs.ptr->content), e->player) > 0.2) ||
			((((t_sprite *)(rs.ptr->content))->type == 1 &&
			((((t_sprite *)(rs.ptr->content))->state != DIE))))))
	{
		ft_render_sprites_1(e, &rs);
		ft_render_sprites_2(e, &rs);
		ft_render_sprites_4(e, &rs);
		if (rs.visible)
			rs.sprite->visible = 1;
		else
		{
			rs.sprite->x_screen_start = -1;
			rs.sprite->x_screen_end = -1;
			rs.sprite->visible = 0;
		}
		rs.ptr = rs.ptr->next;
	}
}
