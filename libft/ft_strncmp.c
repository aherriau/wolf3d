/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:13:08 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 19:53:52 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0' && index < n)
	{
		if (s1[index] == s2[index])
			index++;
		else
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	}
	if ((index == n) || (s1[index] == '\0' && s2[index] == '\0'))
		return (0);
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
