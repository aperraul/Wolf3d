/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:42:55 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/06 14:46:42 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

static void	ft_check_1st_n_last_line(t_w3d *w3d, int y, int *error)
{
	int		x;
	int		val;

	x = -1;
	while (++x < w3d->nb_x_line[y])
	{
		val = w3d->map[y][x];
		if (!((val >= 1 && val <= 7) || (val >= 20 && val <= 27)))
			*error += 1;
	}
}

static void	ft_check_inter_lines(t_w3d *w3d, int y, int *error)
{
	int		x;
	int		val;
	int		end;

	x = -1;
	end = w3d->nb_x_line[y];
	while (++x < end)
	{
		val = w3d->map[y][x];
		if (x == 0 || x == end - 1)
		{
			if (!((val >= 1 && val <= 7) || (val >= 20 && val <= 27)))
				*error += 1;
		}
		else if (x > 0 && x < end - 1)
		{
			if (!((val >= 0 && val <= 7) || (val >= 20 && val <= 27)))
				error += 1;
		}
		if (val == 0)
			++w3d->floor_case;
	}
}

int			ft_check_map(t_w3d *w3d)
{
	int		i;
	int		error;
	int		end;
	int		nb;

	error = 0;
	nb = w3d->nb_lines;
	end = w3d->nb_lines - 1;
	while (--nb > 0)
	{
		if (w3d->nb_x_line[0] != w3d->nb_x_line[nb])
		{
			ft_putstr("error: lines size !=\n");
			error += 1;
		}
	}
	i = -1;
	while (++i < w3d->nb_lines)
	{
		if (i == 0 || i == end)
			ft_check_1st_n_last_line(w3d, i, &error);
		if (i > 0 && i < end)
			ft_check_inter_lines(w3d, i, &error);
	}
	return (error);
}
