/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:39:59 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/02 15:12:28 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

int		ft_wolf_move(int keycode, t_w3d *w3d)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
		w3d->cam.keym = 1;
	if (keycode == 1)
		w3d->cam.keym = -1;
	if (keycode == 0)
		w3d->cam.keym = 2;
	if (keycode == 2)
		w3d->cam.keym = -2;
	if (keycode == 124)
		w3d->cam.keyr = 1;
	if (keycode == 123)
		w3d->cam.keyr = -1;
	if (keycode == 12)
		w3d->port = 1;
	if (keycode == 14)
		w3d->port = -1;

	return (0);
}

int		ft_release_key(int keycode, t_w3d *w3d)
{
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		w3d->cam.keym = 0;
	if (keycode == 124 || keycode == 123)
		w3d->cam.keyr = 0;
	if (keycode == 12 || keycode == 14)
		w3d->port = 0;
	return (0);
}

int		ft_wolf3d_loop(t_w3d *w3d)
{
	double	elapsedtime;

	gettimeofday(&w3d->delt.t1, NULL);
	ft_wolf3d(w3d);
	ft_reset_img(w3d->mlx, 0);
	gettimeofday(&w3d->delt.t2, NULL);
	elapsedtime = (w3d->delt.t2.tv_sec - w3d->delt.t1.tv_sec) * 1000.0;
	elapsedtime += (w3d->delt.t2.tv_usec - w3d->delt.t1.tv_usec) / 1000.0;
	w3d->delt.dt = elapsedtime / 1000;
	if (w3d->delt.dt < 0)
		w3d->delt.dt = -w3d->delt.dt;
	return (0);
}
