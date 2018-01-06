/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:03:12 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 11:37:13 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			index;
	unsigned char	*result;

	result = (unsigned char*)malloc(sizeof(unsigned char) * size);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		result[index] = '\0';
		index++;
	}
	return (result);
}
