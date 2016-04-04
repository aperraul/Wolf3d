/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:06:16 by aperraul          #+#    #+#             */
/*   Updated: 2015/12/03 14:20:21 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_itoa_size(long n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		n = -n;
		size = ft_itoa_size(n);
		size++;
	}
	else if (n >= 10)
	{
		size = ft_itoa_size(n / 10);
		size++;
	}
	else
		size++;
	return (size);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*str;
	long	nbr;

	nbr = n;
	size = ft_itoa_size(nbr);
	str = (char *)malloc(sizeof(char *) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (n < 0)
		nbr = -nbr;
	while (size)
	{
		size--;
		str[size] = 48 + (nbr % 10);
		nbr = nbr / 10;
	}
	if (str[size] == '0' && str[1] != '\0')
		str[size] = '-';
	return (str);
}
