/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:00:43 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 11:17:51 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				index;
	unsigned char		*d;
	const unsigned char	*s;

	index = 0;
	d = dst;
	s = src;
	while (index < n)
	{
		d[index] = s[index];
		index++;
	}
	return (dst);
}
