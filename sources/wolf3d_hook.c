/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:39:59 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/24 14:05:58 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int		ft_wolf_move(int keycode, t_w3d *w3d)
{
	if (keycode == 53)
	{
		ft_clear_w3d(w3d);
		exit(0);
	}
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
	double			elapsedtime;
	static double	timer = 0;
	int				fps;

	gettimeofday(&w3d->delt.t1, NULL);
	ft_wolf3d(w3d);
	ft_reset_img(w3d->mlx, 0);
	gettimeofday(&w3d->delt.t2, NULL);
	elapsedtime = (w3d->delt.t2.tv_sec - w3d->delt.t1.tv_sec) * 1000.0;
	elapsedtime += (w3d->delt.t2.tv_usec - w3d->delt.t1.tv_usec) / 1000.0;
	w3d->delt.dt = elapsedtime / 1000;
	if (w3d->delt.dt < 0)
		w3d->delt.dt = -w3d->delt.dt;
	fps = 1 / w3d->delt.dt;
	timer += w3d->delt.dt;
	if (timer >= 0.5)
	{
		ft_putstr("FPS = ");
		ft_putnbr(fps);
		ft_putchar('\n');
		timer = 0;
	}
	return (0);
}
