/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:02:55 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/09 11:37:55 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*tmp;

	current = *alst;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		del(tmp, tmp->content_size);
		tmp = NULL;
	}
	*alst = NULL;
}
