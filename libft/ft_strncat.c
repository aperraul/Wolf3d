/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:41:06 by aperraul          #+#    #+#             */
/*   Updated: 2015/11/29 14:59:27 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		cpt1;
	size_t	cpt2;

	cpt1 = 0;
	cpt2 = 0;
	while (dest[cpt1] != '\0')
		cpt1++;
	while (cpt2 < n)
	{
		if (src[cpt2] != '\0')
			dest[cpt1] = src[cpt2];
		cpt1++;
		cpt2++;
	}
	dest[cpt1] = '\0';
	return (dest);
}
