/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:37:26 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/09 13:19:43 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_front(t_list **alst, void const *content,
			size_t content_size)
{
	t_list	*new;

	new = ft_lstnew(content, content_size);
	new->next = *alst;
	*alst = new;
}
