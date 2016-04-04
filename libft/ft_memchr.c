/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 23:49:38 by aperraul          #+#    #+#             */
/*   Updated: 2015/11/29 14:58:11 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cpt;
	unsigned char	*sr;

	cpt = 0;
	sr = (unsigned char *)s;
	while (cpt < n)
	{
		if (sr[cpt] == (unsigned char)c)
			return ((void *)s + cpt);
		cpt++;
	}
	return (NULL);
}
