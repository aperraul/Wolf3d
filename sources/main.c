/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:41:27 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/05 15:58:14 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

int		main(int argc, char **argv)
{
	int			x;
	int			y;
	int			ret;
	t_w3d		*w3d;

	if (argc == 2)
	{
		w3d = NULL;
		if ((ret = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putstr("error file");
			return(0);
		}
		w3d = ft_w3d_init();
		ft_get_map(w3d, ret);
		x = -1;
		while (++x < 5)
		{
			y = -1;
			ft_putchar('\n');
			while (++y < 5)
			{
				ft_putnbr(w3d->map[x][y]);
				ft_putchar(' ');
			}
		}
	}
	else
		ft_putstr("nb maps != 1");
	return (0);
}
