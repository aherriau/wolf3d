/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:04:25 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/09 13:17:19 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstmap_pushback(t_list **alst, t_list *lst)
{
	t_list	*current;

	if (*alst == NULL)
		*alst = lst;
	else
	{
		current = *alst;
		while (current->next != NULL)
			current = current->next;
		current->next = lst;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*new_node;

	new_list = NULL;
	while (lst != NULL)
	{
		new_node = (t_list *)malloc(sizeof(t_list));
		new_node = f(lst);
		ft_lstmap_pushback(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
