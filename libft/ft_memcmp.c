/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:02:39 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 11:16:00 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		index;
	const char	*str1;
	const char	*str2;

	index = 0;
	str1 = s1;
	str2 = s2;
	while (index < n)
	{
		if (str1[index] == str2[index])
			index++;
		else
			return ((unsigned char)str1[index] - (unsigned char)str2[index]);
	}
	return (0);
}
