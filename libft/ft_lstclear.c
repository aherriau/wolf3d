/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:41:34 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/09 13:29:14 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **alst)
{
	t_list	*tmp;
	t_list	*current;

	while (*alst != NULL)
	{
		current = *alst;
		tmp = current->next;
		free(*alst);
		*alst = tmp;
	}
	*alst = NULL;
}
