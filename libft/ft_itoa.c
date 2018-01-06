/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:50:57 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 21:36:23 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count_char(int n, int *count)
{
	unsigned int	nbr;

	if (n < 0)
	{
		*count += 1;
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr >= 10)
		ft_count_char(nbr / 10, count);
	*count += 1;
}

static void	ft_put_char(int n, char *tab, int *index, int len)
{
	unsigned int	nbr;

	if (n < 0)
	{
		tab[0] = '-';
		*index += 1;
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		tab[len - *index] = (nbr % 10) + '0';
		*index += 1;
		ft_put_char(nbr / 10, tab, index, len);
	}
	else
	{
		tab[len - *index] = (nbr % 10) + '0';
		*index += 1;
	}
}

char		*ft_itoa(int n)
{
	int				len;
	int				index;
	char			*result;

	len = 0;
	ft_count_char(n, &len);
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	index = 0;
	if (n < 0)
		ft_put_char(n, result, &index, len);
	else
		ft_put_char(n, result, &index, len - 1);
	return (result);
}
