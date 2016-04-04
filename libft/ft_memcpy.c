/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:02:11 by aperraul          #+#    #+#             */
/*   Updated: 2015/11/29 15:00:20 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			cpt;
	unsigned char	*d;
	unsigned char	*s;

	cpt = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (cpt < n)
	{
		d[cpt] = s[cpt];
		cpt++;
	}
	return ((void *)d);
}
