/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_w3d_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:12:05 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/08 11:51:50 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

t_w3d	*ft_w3d_init(void)
{
	t_w3d	*w3d;

	w3d = (t_w3d *)ft_memalloc(sizeof(t_w3d));
	w3d->nb_x_line = NULL;
	w3d->map = NULL;
	w3d->mlx = NULL;
	w3d->nb_lines = 0;
	w3d->cam.pos_x = 15;
	w3d->cam.pos_y = 5;
	w3d->cam.dir_x = -1;
	w3d->cam.dir_y = 0;
	w3d->cam.plan_x = 0;
	w3d->cam.plan_y = 0.66;
	w3d->delt.dt = 0;
	w3d->cam.keym = 0;
	w3d->cam.keyr = 0;
	return (w3d);
}
