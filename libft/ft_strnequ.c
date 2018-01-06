/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:49:20 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 21:56:38 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	index;

	if (s1 == NULL || s2 == NULL)
		return (0);
	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0' && index < n)
	{
		if (s1[index] == s2[index])
			index++;
		else
			return (0);
	}
	if ((index == n) || (s1[index] == '\0' && s2[index] == '\0'))
		return (1);
	return (0);
}
