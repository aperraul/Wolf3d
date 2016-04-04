/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:52:37 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/04 15:30:28 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbwords(char const *s, char c)
{
	int cpt;
	int nbw;

	cpt = 0;
	nbw = 0;
	if (s[cpt] != c)
		nbw++;
	while (s[cpt] == c && s[cpt] != '\0')
		cpt++;
	while (s[cpt] != '\0')
	{
		if (s[cpt - 1] == c && s[cpt] != c)
			nbw++;
		cpt++;
	}
	return (nbw);
}

static int	ft_size(char const *s, char c)
{
	int size;
	int cpt;

	size = 0;
	cpt = 0;
	while (s[cpt] != '\0' && s[cpt] != c)
	{
		size++;
		cpt++;
	}
	if (size == 0)
		size++;
	return (size);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		cpt;

	if (!s)
		return (NULL);
	tab = (char**)malloc(sizeof(char *) * (ft_nbwords(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	cpt = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			tab[cpt] = ft_strsub(s, 0, ft_size(s, c));
			if (tab[cpt] == NULL)
				return (NULL);
			s = s + ft_size(s, c);
			cpt++;
		}
	}
	tab[cpt] = NULL;
	return (tab);
}
