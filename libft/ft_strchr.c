/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:38:21 by aperraul          #+#    #+#             */
/*   Updated: 2015/11/25 18:32:36 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	int		cpt;

	cpt = 0;
	chr = (char)c;
	while (s[cpt] && s[cpt] != chr)
		cpt++;
	if (s[cpt] == chr)
		return ((char *)&s[cpt]);
	return (NULL);
}
