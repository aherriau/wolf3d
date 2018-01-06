/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:20:59 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 20:04:16 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		len;
	int		index;

	len = ft_strlen(s1);
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		result[index] = s1[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
