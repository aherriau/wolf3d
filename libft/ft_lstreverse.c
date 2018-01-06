/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:42:46 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/09 13:35:16 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **alst)
{
	t_list	*new;
	t_list	*next;
	t_list	*current;

	new = 0;
	current = *alst;
	while (current != NULL)
	{
		next = current->next;
		current->next = new;
		new = current;
		current = next;
	}
	*alst = new;
}
