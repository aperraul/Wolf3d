/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:02:04 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/08 17:25:35 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

static void		ft_dda(t_w3d *w3d, t_ptd *sd, t_ptd *dd, t_pt *m, t_ptd *s)
{
	while (w3d->map[m->x][m->y] == 0)
	{
		if (sd->x < sd->y)
		{
			sd->x += dd->x;
			m->x += s->x;
			w3d->ray.side = 0;
		}
		else
		{
			sd->y += dd->y;
			m->y += s->y;
			w3d->ray.side = 1;
		}
	}
}

static void		ft_step(t_w3d *w3d, t_ptd *d, t_ptd *p, t_ptd *sdt, t_pt *m)
{
	double x;
	double y;

	x = w3d->ray.ddist.x;
	y = w3d->ray.ddist.y;
	if (d->x < 0)
	{
		w3d->ray.step.x = -1;
		sdt->x = (p->x - m->x) * x;
	}
	else
	{
		w3d->ray.step.x = 1;
		sdt->x = (m->x + 1.0 - p->x) * x;
	}
	if (d->y < 0)
	{
		w3d->ray.step.y = -1;
		sdt->y = (p->y - m->y) * y;
	}
	else
	{
		w3d->ray.step.y = 1;
		sdt->y = (m->y + 1.0 - p->y) * y;
	}
}

static void		ft_calc_ray_dist(t_w3d *w3d, t_ptd *ddist, t_ptd *raydir)
{
	ddist->x = sqrt(1 + (raydir->y * raydir->y) / (raydir->x * raydir->x));
	ddist->y = sqrt(1 + (raydir->x * raydir->x) / (raydir->y * raydir->y));
	ft_step(w3d, &w3d->ray.rdir, &w3d->ray.rpos, &w3d->ray.sdist, &w3d->ray.map);
	ft_dda(w3d, &w3d->ray.sdist, &w3d->ray.ddist, &w3d->ray.map, &w3d->ray.step);
}

void			ft_wolf3d(t_w3d *w3d)
{
	int		x;

	x = -1;
	ft_wolf_events(w3d);
	while (++x < WIN_X)
	{
		w3d->wall.wall_x = x;
		w3d->ray.cam_x = 2 * x / (double)WIN_X - 1;
		w3d->ray.rpos.x = w3d->cam.pos.x;
		w3d->ray.rpos.y = w3d->cam.pos.y;
		w3d->ray.rdir.x = w3d->cam.dir.x + w3d->cam.plan.x * w3d->ray.cam_x;
		w3d->ray.rdir.y = w3d->cam.dir.y + w3d->cam.plan.y * w3d->ray.cam_x;
		w3d->ray.map.x = (int)w3d->ray.rpos.x;
		w3d->ray.map.y = (int)w3d->ray.rpos.y;
		ft_calc_ray_dist(w3d, &w3d->ray.ddist, &w3d->ray.rdir);
		ft_draw_wolf3d(w3d, &w3d->wall, &w3d->ray);
	}
	w3d->cam.keym = 0;
	w3d->cam.keyr = 0;
	ft_flush_img(w3d->mlx);
}
