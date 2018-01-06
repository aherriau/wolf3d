/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:51:22 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/09 11:28:51 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		index;
	int		index2;
	int		count;

	index = 0;
	count = 0;
	while (s[index] != '\0')
	{
		index2 = index;
		while ((s[index2] != '\0') && (s[index2] != c))
			index2++;
		if (s[index2] == '\0')
		{
			count++;
			return (count);
		}
		if ((s[index2] == c) && (index2 > index))
		{
			count++;
			index = index2;
		}
		index++;
	}
	return (count);
}

static void	ft_split_words(char const *s, char c, char **tab, int *index)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (s[i] != '\0')
	{
		j = i;
		while ((s[j] != '\0') && (s[j] != c))
			j++;
		if ((s[j] == '\0') || ((s[j] == c) && (j > i)))
		{
			tab[*index] = (char *)malloc(sizeof(char) * ((j - i) + 1));
			if (tab[*index] == NULL)
				return ;
			k = 0;
			while (i < j)
				tab[*index][k++] = s[i++];
			tab[*index][k] = '\0';
			*index += 1;
			if (s[j] == '\0')
				return ;
		}
		i++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		count;
	int		index;

	if (s == NULL)
		return (NULL);
	count = ft_count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (tab == NULL)
		return (NULL);
	index = 0;
	ft_split_words(s, c, tab, &index);
	tab[index] = 0;
	return (tab);
}
