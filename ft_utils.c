/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:25:41 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/04 05:15:20 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double	ft_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	ft_clamp(double a, double mi, double ma)
{
	return (ft_min(ft_max(a, mi), ma));
}

void	ft_keydown_door_2_process(t_env *e)
{
	e->player.nb_enter++;
	e->sdl.door = 1;
}
