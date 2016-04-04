/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:06:33 by aperraul          #+#    #+#             */
/*   Updated: 2015/11/26 15:11:07 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		cpt;
	int		cpt2;

	cpt = 0;
	cpt2 = 0;
	if (!(*s2))
		return ((char *)s1);
	while (s1[cpt] != '\0')
	{
		while (s1[cpt + cpt2] == s2[cpt2] && s2[cpt2] != '\0')
			cpt2++;
		if (!s2[cpt2])
			return ((char *)&s1[cpt]);
		else
		{
			cpt2 = 0;
			cpt++;
		}
	}
	return (NULL);
}
