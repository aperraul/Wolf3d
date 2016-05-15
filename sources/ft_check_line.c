/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:18:01 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/15 17:47:17 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

static int		ft_check_spawn(char *line, t_w3d *w3d, int i, int *f)
{
	w3d->nb_spawn++;
	if (w3d->nb_spawn > 1)
	{
		ft_putstr("error: too much spawn set\n");
		return (0);
	}
	if (line[i + 1] != ' ')
		return (0);
	w3d->spawn.y = w3d->nb_lines;
	w3d->spawn.x = (*f + 1);
	ft_putnbr(w3d->spawn.x);
	ft_putchar(' ');
	ft_putnbr(w3d->spawn.y);
	line[i] = '0';
	return (1);
}

static int		ft_check_character(t_w3d *w3d, char *line, int i, int *f)
{
static int	tmp = 0;
	if (line[i] == 's')
	{
		if (!ft_check_spawn(line, w3d, i, f))
			return (0);
	}
	if (line[i] >= '0' && line[i] <= '9')
	{
		if (line[i + 1] == 's')
			return (0);
	}
	if (line[i] == ' ' && tmp != ' ')
		*f += 1;
	tmp = line[i];
	return (1);
}

int				ft_check_line(char *line, t_w3d *w3d)
{
	int		i;
	int		f;
	int		e;

	f = 1;
	i = -1;
	e = ft_strlen(line) - 1;
	if (!((line[0] >= '0' && line[0] <= '9') && (line[e] >= '0' &&
				line[e] <= '9')))
		return (0);
	while (line[++i])
	{
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == ' ' ||
				line[i] == 's')
		{
			if (!(ft_check_character(w3d, line, i, &f)))
				return (0);
		}
		else
			return (0);
	}
	return (f < 2 ? 0 : i);
}
