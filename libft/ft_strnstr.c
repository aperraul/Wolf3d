/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:12:31 by aperraul          #+#    #+#             */
/*   Updated: 2015/12/03 14:19:30 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		cpt;
	size_t		cpt2;
	size_t		size;

	cpt = 0;
	cpt2 = 0;
	if (!(size = ft_strlen(s2)))
		return ((char *)s1);
	while (s1[cpt])
	{
		while ((s1[cpt + cpt2] == s2[cpt2]) && cpt + cpt2 < n)
		{
			if (cpt2 == size - 1)
				return ((char *)&s1[cpt]);
			cpt2++;
		}
		cpt2 = 0;
		cpt++;
	}
	return (NULL);
}
