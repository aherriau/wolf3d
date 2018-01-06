/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:16:02 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/09 13:18:55 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **alst, void const *content, size_t content_size)
{
	t_list	*current;
	t_list	*new;

	new = ft_lstnew(content, content_size);
	if (*alst == NULL)
		*alst = new;
	else
	{
		current = *alst;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}
