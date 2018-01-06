/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:22:04 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/07 17:28:52 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;

	index = 0;
	while ((src[index] != '\0') && (index < len))
	{
		dst[index] = src[index];
		index++;
	}
	while (index < len)
	{
		dst[index] = '\0';
		index++;
	}
	return (dst);
}
