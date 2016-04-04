/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:50:30 by aperraul          #+#    #+#             */
/*   Updated: 2015/11/25 18:34:40 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		size;
	char	chr;

	size = ft_strlen(s);
	chr = (char)c;
	while (size > 0 && s[size] != chr)
		size--;
	if (s[size] == chr)
		return ((char *)&s[size]);
	return (NULL);
}
