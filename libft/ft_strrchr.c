/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:10:49 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/07 18:30:58 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	int		last;

	index = 0;
	last = -1;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			last = index;
		index++;
	}
	if (last != -1)
		return ((char*)&(s[last]));
	if (c == '\0')
		return ((char*)&(s[index]));
	return (NULL);
}
