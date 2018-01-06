/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:01:15 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 11:18:16 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				index;
	unsigned char		ch;
	unsigned char		*d;
	const unsigned char	*s;

	index = 0;
	ch = c;
	d = dst;
	s = src;
	while (index < n)
	{
		d[index] = s[index];
		if (d[index] == ch)
			return (&(dst[index + 1]));
		index++;
	}
	return (NULL);
}
