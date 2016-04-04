/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:55:55 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/04 15:30:19 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*chr;

	chr = (char *)malloc(sizeof(char) * (size + 1));
	if (chr)
		return (ft_memset(chr, 0, size + 1));
	return (NULL);
}
