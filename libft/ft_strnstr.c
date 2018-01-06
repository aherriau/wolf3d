/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:11:54 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 21:19:19 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	int		k;

	if (ft_strcmp(needle, "") == 0 || needle == NULL)
		return ((char*)haystack);
	if (ft_strcmp(haystack, "") == 0 || haystack == NULL || len == 0)
		return (NULL);
	i = 0;
	while (haystack[i] != '\0')
	{
		k = i;
		j = 0;
		while ((haystack[i] != '\0') && (haystack[i] == needle[j]) && (i < len))
		{
			i++;
			j++;
		}
		if ((needle[j] == '\0'))
			return ((char*)&haystack[k]);
		if (haystack[i] == '\0')
			return (NULL);
		i = k + 1;
	}
	return (NULL);
}
