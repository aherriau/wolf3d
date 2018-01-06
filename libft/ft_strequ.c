/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:48:49 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 21:55:42 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		index;

	if (s1 == NULL || s2 == NULL)
		return (0);
	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] == s2[index])
			index++;
		else
			return (0);
	}
	if (s1[index] != '\0' || s2[index] != '\0')
		return (0);
	return (1);
}
