/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:02:04 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/08 12:00:01 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

static void		ft_perform_dda(t_w3d *w3d)
{
	while (w3d->map[w3d->ray.map_x][w3d->ray.map_y] == 0)
	{
		if (w3d->ray.sdist_x < w3d->ray.sdist_y)
		{
			w3d->ray.sdist_x += w3d->ray.ddist_x;
			w3d->ray.map_x += w3d->ray.step_x;
			w3d->ray.side = 0;
		}
		else
		{
			w3d->ray.sdist_y += w3d->ray.ddist_y;
			w3d->ray.map_y += w3d->ray.step_y;
			w3d->ray.side = 1;
		}
	}
}

static void		ft_calc_step(t_w3d *w3d, double x, double y)
{
	if (w3d->ray.raydir_x < 0)
	{
		w3d->ray.step_x = -1;
		w3d->ray.sdist_x = (w3d->ray.raypos_x - w3d->ray.map_x) * x;
	}
	else
	{
		w3d->ray.step_x = 1;
		w3d->ray.sdist_x = (w3d->ray.map_x + 1.0 - w3d->ray.raypos_x) * x;
	}
	if (w3d->ray.raydir_y < 0)
	{
		w3d->ray.step_y = -1;
		w3d->ray.sdist_y = (w3d->ray.raypos_y - w3d->ray.map_y) * y;
	}
	else
	{
		w3d->ray.step_y = 1;
		w3d->ray.sdist_y = (w3d->ray.map_y + 1.0 - w3d->ray.raypos_y) * y;
	}
}

static void		ft_calc_ray_dist(t_w3d *w3d)
{
	double	xx;
	double	yy;

	xx = w3d->ray.raydir_x;
	yy = w3d->ray.raydir_y;
	w3d->ray.ddist_x = sqrt(1 + (yy * yy) / (xx * xx));
	w3d->ray.ddist_y = sqrt(1 + (xx * xx) / (yy * yy));
	ft_calc_step(w3d, w3d->ray.ddist_x, w3d->ray.ddist_y);
	ft_perform_dda(w3d);
}

void			ft_wolf3d(t_w3d *w3d)
{
	int		x;

	x = -1;
	ft_wolf_events(w3d);
	while (++x < WIN_X)
	{
		w3d->wall.wall_x = x;
		w3d->ray.cam_x = x * 2 / (double)WIN_X - 1;
		w3d->ray.raypos_x = w3d->cam.pos_x;
		w3d->ray.raypos_y = w3d->cam.pos_y;
		w3d->ray.raydir_x = w3d->cam.dir_x + w3d->cam.plan_x * w3d->ray.cam_x;
		w3d->ray.raydir_y = w3d->cam.dir_y + w3d->cam.plan_y * w3d->ray.cam_x;
		w3d->ray.map_x = (int)w3d->ray.raypos_x;
		w3d->ray.map_y = (int)w3d->ray.raypos_y;
		ft_calc_ray_dist(w3d);
		ft_draw_wolf3d(w3d);
	}
	w3d->cam.keym = 0;
	w3d->cam.keyr = 0;
	ft_flush_img(w3d->mlx);
}
