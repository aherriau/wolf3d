/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:42:12 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 03:54:23 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

SDL_Texture	*ld_t(SDL_Renderer *renderer, char *filename)
{
	SDL_Texture	*res;

	if (!(res = IMG_LoadTexture(renderer, filename)))
	{
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_error("could not load the file");
	}
	return (res);
}

SDL_Surface	*ld_s(char *filename)
{
	SDL_Surface	*res;

	if (!(res = IMG_Load(filename)))
	{
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_error("could not load the file");
	}
	return (res);
}

void		ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

int			ft_map_error(char **tab, char **tab2, int fd, char *str)
{
	ft_tabdel(tab2);
	ft_tabdel(tab);
	close(fd);
	ft_error(str);
	return (0);
}
