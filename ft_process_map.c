/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 06:58:55 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/05 07:00:13 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_process_verify_map(t_env *e, t_parser *parser)
{
	ft_verify_map_2(parser);
	ft_verify_map_3(e, parser);
	ft_verify_map_4(parser);
	ft_verify_map_5(parser);
	parser->i++;
}

void	ft_process_init_map(t_env *e, t_maper *maper)
{
	maper->tab = ft_strsplit(maper->line, '\t');
	ft_strdel(&(maper->line));
	maper->i = 0;
	while (maper->tab[maper->i])
	{
		ft_init_map_2(e, maper);
		if (ft_atoi(maper->tab2[1]) > 0)
		{
			ft_init_map_3(e, maper);
			ft_init_map_4(e, maper);
		}
		ft_init_map_5(e, maper);
	}
	ft_tabdel(maper->tab);
	ft_strdel(&(maper->line));
	maper->index++;
}
