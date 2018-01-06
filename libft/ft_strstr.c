/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:11:24 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 21:00:53 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;

	if (ft_strcmp(needle, "") == 0 || needle == NULL)
		return ((char*)haystack);
	if (ft_strcmp(haystack, "") == 0 || haystack == NULL)
		return (NULL);
	i = 0;
	while (haystack[i] != '\0')
	{
		k = i;
		j = 0;
		while ((haystack[i] != '\0') && (haystack[i] == needle[j]))
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char*)&haystack[k]);
		if (haystack[i] == '\0')
			return (NULL);
		i = k + 1;
	}
	return (NULL);
}
