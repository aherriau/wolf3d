/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:45:18 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 13:32:05 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;
	size_t	index;

	result = (char*)malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		result[index] = '\0';
		index++;
	}
	result[index] = '\0';
	return (result);
}
