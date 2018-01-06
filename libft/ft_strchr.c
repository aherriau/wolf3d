/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:10:00 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/07 18:27:32 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			return ((char*)&(s[index]));
		index++;
	}
	if (c == '\0')
		return ((char*)&(s[index]));
	return (NULL);
}
