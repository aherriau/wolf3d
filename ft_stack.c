/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:26:03 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/04 05:21:42 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_xy	ft_lstpop(t_list **list)
{
	t_xy	res;
	t_list	*tmp;
	t_xy	*content;

	res = (*(t_xy *)((*list)->content));
	tmp = *list;
	content = (t_xy *)(*list)->content;
	*list = (*list)->next;
	free(content);
	free(tmp);
	return (res);
}

void	ft_stackdel(t_list **list)
{
	while (*list != NULL)
		ft_lstpop(list);
}

t_list	*ft_lstnew_ptr(void const *content, size_t content_size)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_node->content = NULL;
		new_node->content_size = 0;
	}
	else
	{
		new_node->content = (void *)content;
		new_node->content_size = content_size;
	}
	new_node->next = NULL;
	return (new_node);
}
