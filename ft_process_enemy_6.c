/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_enemy_6.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 22:30:49 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 02:25:03 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_can_see_player_5(t_env *e, t_enemy *this, t_render_sprite *rs)
{
	rs->sprite_x = e->player.pos.x - this->sprite->pos.x;
	rs->sprite_y = e->player.pos.y - this->sprite->pos.y;
	rs->invdet = 1.0 / ((this->sprite->plane.x * this->sprite->dir.y) -
			(this->sprite->dir.x * this->sprite->plane.y));
	rs->transform_x = rs->invdet * (this->sprite->dir.y * rs->sprite_x -
			this->sprite->dir.x * rs->sprite_y);
	rs->transform_y = rs->invdet * (-this->sprite->plane.y * rs->sprite_x +
			this->sprite->plane.x * rs->sprite_y);
	rs->sprite_screen_x = (int)((W / 2) * (1 + rs->transform_x /
				rs->transform_y));
	rs->sprite_height = abs((int)(H / rs->transform_y));
	rs->draw_start_y = -rs->sprite_height / 2 + H / 2;
	if (rs->draw_start_y < 0)
		rs->draw_start_y = 0;
	rs->draw_end_y = rs->sprite_height / 2 + H / 2;
	if (rs->draw_end_y >= H)
		rs->draw_end_y = H - 1;
	rs->sprite_width = abs((int)(H / rs->transform_y));
	rs->draw_start_x = -rs->sprite_width / 2 + rs->sprite_screen_x;
	if (rs->draw_start_x < 0)
		rs->draw_start_x = 0;
	rs->draw_end_x = rs->sprite_width / 2 + rs->sprite_screen_x;
	if (rs->draw_end_x >= W)
		rs->draw_end_x = W - 1;
}

int		ft_can_see_player_6(t_env *e, t_render_sprite *rs)
{
	int		lol;

	rs->stripe = rs->draw_start_x;
	lol = 0;
	while (rs->stripe <= rs->draw_end_x)
	{
		if (rs->transform_y > 0 && rs->stripe >= 0 && rs->stripe < W &&
				rs->transform_y < e->raycast.z_buff[rs->stripe] + 0.6)
			lol++;
		rs->stripe++;
	}
	if (lol > 1 * abs((rs->draw_end_x - rs->draw_start_x)) / 2)
		return (1);
	return (0);
}

void	get_index_process(double val, int *index)
{
	int		i;
	int		min_diff;

	min_diff = 10;
	i = 0;
	while (i < 8)
	{
		if (fabs(val - (i * M_PI / 4)) < min_diff)
		{
			min_diff = fabs(val - i * (M_PI / 4));
			*index = i;
		}
		i++;
	}
}

int		get_index(t_player player, t_sprite sprite)
{
	int		index;
	double	val;
	double	norm_player;
	double	norm_sprite;
	double	dot_product;

	norm_player = sqrt(player.dir.x * player.dir.x + player.dir.y *
			player.dir.y);
	norm_sprite = sqrt(sprite.dir.x * sprite.dir.x + sprite.dir.y *
			sprite.dir.y);
	dot_product = player.dir.x * sprite.dir.x + player.dir.y * sprite.dir.y;
	val = atan2(player.dir.y, player.dir.x) - atan2(sprite.dir.y, sprite.dir.x);
	if (val < 0)
		val += 2 * M_PI;
	get_index_process(val, &index);
	return ((index + 5) % 8);
}

void	ft_enemy_swipe_process(t_enemy *this, double *angle)
{
	if (this->sprite->swipe_index == 0)
		*angle = M_PI / 4;
	else if (this->sprite->swipe_index == 1)
		*angle = -M_PI / 2;
	else if (this->sprite->swipe_index == 2)
		*angle = M_PI;
	else
	{
		*angle = M_PI / 2;
		this->sprite->swipe_iterations++;
	}
}
