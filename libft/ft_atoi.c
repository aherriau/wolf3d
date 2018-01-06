/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:56:15 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 21:19:25 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_atoi_init(const char *str, int *index, int *negative)
{
	while (str[*index] == ' ' || str[*index] == '\n' || str[*index] == '\t' ||
			str[*index] == '\v' || str[*index] == '\r' || str[*index] == '\f')
		*index += 1;
	if (str[*index] == '-')
	{
		*negative = -1;
		*index += 1;
	}
	else
	{
		if (str[*index] == '+')
			*index += 1;
	}
}

int			ft_atoi(const char *str)
{
	int		result;
	int		index;
	int		negative;

	result = 0;
	index = 0;
	negative = 1;
	ft_atoi_init(str, &index, &negative);
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	result *= negative;
	return (result);
}
