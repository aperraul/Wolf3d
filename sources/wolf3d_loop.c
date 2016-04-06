/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:39:59 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/06 14:26:10 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

int		ft_wolf3d_loop(t_w3d *w3d)
{
	double	elapsedtime;

	gettimeofday(&w3d->delt.t1, NULL);
	ft_wolf3d(w3d);
	gettimeofday(&w3d->delt.t2, NULL);
	elapsedtime = (w3d->delt.t2.tv_sec - w3d->delt.t1.tv_sec) * 1000.0;
	elapsedtime += (w3d->delt.t2.tv_usec - w3d->delt.t1.tv_usec) / 1000.0;
	w3d->delt.dt = elapsedtime / 1000;
}
