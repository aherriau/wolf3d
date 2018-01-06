/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:23:22 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 20:21:59 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	j;
	int		res;

	res = ft_min(ft_strlen(dst), size) + ft_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (dst[i] != '\0')
			i++;
		j = 0;
		while ((src[j] != '\0') && (i + j < size - 1))
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	return (res);
}
