/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:01:42 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 10:58:25 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				index;
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (src < dst)
	{
		index = len;
		while (index > 0)
		{
			d[index - 1] = s[index - 1];
			index--;
		}
	}
	else
	{
		index = 0;
		while (index < len)
		{
			d[index] = s[index];
			index++;
		}
	}
	return (dst);
}
