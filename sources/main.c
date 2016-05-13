/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:41:27 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/13 10:40:04 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int		main(int argc, char **argv)
{
	int			ret;
	t_w3d		*w3d;

	if (argc == 2)
	{
		w3d = NULL;
		if ((ret = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putstr("error file");
			return (0);
		}
		w3d = ft_w3d_init();
		ft_get_map(w3d, ret);
		if (w3d->map == NULL)
		{
			ft_putstr("bad file");
			return (0);
		}
		ft_pre_w3d(w3d);
	}
	else
		ft_putstr("nb maps != 1");
	return (0);
}
