/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:32:21 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 22:01:16 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		index;

	if (s != NULL)
	{
		index = 0;
		while (s[index] != '\0')
		{
			ft_putchar_fd(s[index], fd);
			index++;
		}
	}
}
