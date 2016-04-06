/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:18:01 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/06 11:10:16 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

int		ft_check_line(char *line)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == ' ' ||
				line[i] == '-')
		{
			if (line[i] == '-' && (line[i + 1] == '-' || line[i + 1] == ' '))
				return (0);
			if (line[i] >= '0' && line[i] <= '9')
				f++;
			i++;
		}
		else
			return (0);
	}
	if (f == 0)
		return (0);
	return (i);
}
