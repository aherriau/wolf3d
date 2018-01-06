/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:02:09 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 21:48:10 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	const char		*str;

	index = 0;
	str = s;
	while (index < n)
	{
		if ((unsigned char)str[index] == (unsigned char)c)
			return ((void*)&(str[index]));
		index++;
	}
	return (NULL);
}
