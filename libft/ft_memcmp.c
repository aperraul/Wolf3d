/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:03:59 by aperraul          #+#    #+#             */
/*   Updated: 2015/11/29 14:58:46 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			cpt;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	cpt = 0;
	while ((cpt < n) && (str1 != '\0') && (str2 != '\0'))
	{
		if (str1[cpt] != str2[cpt])
			return (str1[cpt] - str2[cpt]);
		cpt++;
	}
	return (0);
}
