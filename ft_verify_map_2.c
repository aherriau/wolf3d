/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_map_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 05:43:30 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 05:45:24 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_init_parser(t_env *e, t_parser *parser, char *filename)
{
	parser->fd = open(filename, O_RDONLY);
	if (parser->fd == -1)
	{
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_error("could not open the file");
	}
	parser->start = 1;
	parser->pos_start = 0;
	parser->pos_end = 0;
	e->map.width = 0;
	e->map.height = 0;
	e->map.nb_enemy = 0;
	parser->index = 0;
}

void	ft_verify_map_1(t_env *e, t_parser *parser)
{
	parser->tab = ft_strsplit(parser->line, '\t');
	ft_strdel(&(parser->line));
	if (parser->start)
	{
		parser->start = 0;
		parser->i = 0;
		while (parser->tab[parser->i])
			parser->i++;
		e->map.width = parser->i;
	}
	else
	{
		parser->i = 0;
		while (parser->tab[parser->i])
			parser->i++;
		if (parser->i != e->map.width)
			ft_map_error(parser->tab, NULL,
				parser->fd, "map shall be rectangular");
	}
}

void	ft_verify_map_2(t_parser *parser)
{
	parser->tab2 = ft_strsplit(parser->tab[parser->i], ',');
	parser->j = 0;
	while (parser->tab2[parser->j])
		parser->j++;
	if (parser->j != 4)
		ft_map_error(parser->tab, parser->tab2,
			parser->fd, "map squares require 4 digits");
	parser->j = 0;
	while (parser->tab2[parser->j])
	{
		parser->k = 0;
		while (parser->tab2[parser->j][parser->k])
		{
			if (parser->tab2[parser->j][parser->k] < '0' ||
				parser->tab2[parser->j][parser->k] > '9')
				ft_map_error(parser->tab, parser->tab2,
					parser->fd, "map requires digits only");
			parser->k++;
		}
		parser->j++;
	}
}
