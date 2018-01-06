/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 04:52:12 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/05 07:05:04 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_verify_map_3(t_env *e, t_parser *parser)
{
	if (ft_atoi(parser->tab2[0]) > 0)
	{
		parser->j = 1;
		while (parser->tab2[parser->j])
		{
			if (ft_atoi(parser->tab2[parser->j]) != 0)
				ft_map_error(parser->tab,
					parser->tab2, parser->fd, "walls must be alone");
			parser->j++;
		}
	}
	if (ft_atoi(parser->tab2[1]) > 0)
	{
		if (ft_atoi(parser->tab2[2]) != 0)
			ft_map_error(parser->tab,
					parser->tab2, parser->fd, "enemies must be alone");
		e->map.nb_enemy += 1;
	}
}

void	ft_verify_map_4(t_parser *parser)
{
	if (ft_atoi(parser->tab2[1]) > 0 || ft_atoi(parser->tab2[2]) > 0)
	{
		if (ft_atoi(parser->tab2[3]) != 0)
			ft_map_error(parser->tab,
					parser->tab2, parser->fd, "start and end must be alone");
	}
	if (ft_atoi(parser->tab2[0]) > 71)
		ft_error("walls must stay between 1 and 71");
	if (ft_atoi(parser->tab2[1]) > 9)
		ft_error("enemies must stay between 1 and 9");
}

void	ft_verify_map_5(t_parser *parser)
{
	if (ft_atoi(parser->tab2[2]) > 49)
		ft_error("items must stay between 1 and 49");
	if (ft_atoi(parser->tab2[3]) > 2)
		ft_map_error(parser->tab, parser->tab2,
			parser->fd, "invalid start/end index");
	if (ft_atoi(parser->tab2[3]) == 1)
	{
		if (parser->pos_start)
			ft_map_error(parser->tab, parser->tab2,
				parser->fd, "map must have only one start");
		parser->pos_start = 1;
		parser->pos_start_x = parser->index;
		parser->pos_start_y = parser->i;
	}
	if (ft_atoi(parser->tab2[3]) == 2)
	{
		if (parser->pos_end)
			ft_map_error(parser->tab, parser->tab2,
				parser->fd, "map must have only one end");
		parser->pos_end = 1;
		parser->pos_end_x = parser->index;
		parser->pos_end_y = parser->i;
	}
	ft_tabdel(parser->tab2);
}

void	ft_verify_map_6(t_env *e, t_parser *parser)
{
	if (e->map.width == 0 || e->map.height == 0 ||
		e->map.width * e->map.height < 12)
		ft_error("map must be minimum 3 * 4");
	if (parser->pos_start == 0 || parser->pos_end == 0)
		ft_error("map must have one end and one start");
	if (parser->pos_start_x == 0 ||
		parser->pos_start_x == (e->map.height - 1) ||
		parser->pos_start_y == 0 || parser->pos_start_y == (e->map.width - 1) ||
		parser->pos_end_x == 0 || parser->pos_end_x == (e->map.height - 1) ||
		parser->pos_end_y == 0 || parser->pos_end_y == (e->map.width - 1))
		ft_error("end and start can't be at the extremities of the map");
}

void	ft_verify_map(t_env *e, char *filename)
{
	t_parser	parser;
	int			ret;

	ft_init_parser(e, &parser, filename);
	while ((ret = get_next_line(parser.fd, &(parser.line))) > 0)
	{
		ft_verify_map_1(e, &parser);
		parser.i = 0;
		while (parser.tab[parser.i])
			ft_process_verify_map(e, &parser);
		ft_tabdel(parser.tab);
		ft_strdel(&(parser.line));
		e->map.height += 1;
		parser.index++;
	}
	ft_strdel(&(parser.line));
	close(parser.fd);
	if (ret == -2)
		ft_error("map is too big to be processed");
	if (ret == -1)
		ft_error("malloc error");
	ft_verify_map_6(e, &parser);
}
