/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:24:53 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/18 17:26:35 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*current;

	i = 0;
	current = begin_list;
	while (current != NULL && i < nbr)
	{
		current = current->next;
		i++;
	}
	if (i == nbr)
		return (current);
	else
		return (NULL);
}
