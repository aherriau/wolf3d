/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:47:20 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/09 08:57:01 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		index;

	if ((s != NULL) && (f != NULL))
	{
		index = 0;
		while (s[index] != '\0')
		{
			f((unsigned int)index, &(s[index]));
			index++;
		}
	}
}
