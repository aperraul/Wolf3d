/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:03:58 by aperraul          #+#    #+#             */
/*   Updated: 2015/12/03 18:15:19 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		size;
	int		i;
	int		cpt;

	if (!s)
		return (NULL);
	size = ft_strlen(s) - 1;
	while (s[size] == ' ' || s[size] == '\t' || s[size] == '\n')
		size--;
	size++;
	i = 0;
	while ((i < size) && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	size = size - i;
	if (!(str = ft_strnew(size)))
		return (NULL);
	cpt = 0;
	while (cpt < size)
	{
		str[cpt] = s[i];
		cpt++;
		i++;
	}
	return (str);
}
