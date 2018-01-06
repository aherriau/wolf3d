/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:50:58 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/09 11:28:05 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strtrim_process(char *str)
{
	int		index;
	int		index2;

	index = 0;
	while (str[index] && WHITE_SPACE(str[index]))
	{
		index2 = index;
		while (str[index2])
		{
			str[index2] = str[index2 + 1];
			index2++;
		}
	}
}

char		*ft_strtrim(char const *s)
{
	int		index;
	char	*str;
	char	*result;

	if (s == NULL)
		return (NULL);
	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	ft_strtrim_process(str);
	index = 0;
	while (str[index])
		index++;
	index--;
	while (index > 0 && WHITE_SPACE(str[index]))
		str[index--] = '\0';
	result = ft_strdup(str);
	return (result);
}
