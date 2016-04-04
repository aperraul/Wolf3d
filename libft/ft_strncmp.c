/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:11:02 by aperraul          #+#    #+#             */
/*   Updated: 2015/12/03 14:25:50 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			cpt;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	cpt = 0;
	while (str1[cpt] == str2[cpt] && str1[cpt] != '\0'
			&& str2[cpt] != '\0' && cpt < n)
		cpt++;
	if (cpt == n)
		return (0);
	return (str1[cpt] - str2[cpt]);
}
