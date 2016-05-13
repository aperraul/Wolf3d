/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_portal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 14:40:31 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/13 16:31:49 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

static void		ft_do_dda(t_w3d *w3d, t_ptd *sd, t_ptd *dd, t_pt *m)
{
	while (w3d->map[m->x][m->y] == 0)
	{
		if (sd->x < sd->y)
		{
			sd->x += dd->x;
			m->x += w3d->ray.step.x;
			w3d->ray.side = 0;
		}
		else
		{
			sd->y += dd->y;
			m->y += w3d->ray.step.y;
			w3d->ray.side = 1;
		}
	}
	if (w3d->portal.type == 1)
		ft_set_blue_portal(w3d, &w3d->ray.map);
	else if (w3d->portal.type == 2)
		ft_set_orange_portal(w3d, &w3d->ray.map);
}

static void		ft_do_step(t_w3d *w3d, t_ptd *d, t_ptd *p, t_ptd *sdt)
{
	double x;
	double y;

	x = w3d->ray.ddist.x;
	y = w3d->ray.ddist.y;
	if (d->x < 0)
	{
		w3d->ray.step.x = -1;
		sdt->x = (p->x - w3d->ray.map.x) * x;
	}
	else
	{
		w3d->ray.step.x = 1;
		sdt->x = (w3d->ray.map.x + 1.0 - p->x) * x;
	}
	if (d->y < 0)
	{
		w3d->ray.step.y = -1;
		sdt->y = (p->y - w3d->ray.map.y) * y;
	}
	else
	{
		w3d->ray.step.y = 1;
		sdt->y = (w3d->ray.map.y + 1.0 - p->y) * y;
	}
}

static void		ft_calc_ray_dist(t_w3d *w3d, t_ptd *ddist, t_ptd *raydir)
{
	ddist->x = sqrt(1 + (raydir->y * raydir->y) / (raydir->x * raydir->x));
	ddist->y = sqrt(1 + (raydir->x * raydir->x) / (raydir->y * raydir->y));
	ft_do_step(w3d, &w3d->ray.rdir, &w3d->ray.rpos, &w3d->ray.sdist);
	ft_do_dda(w3d, &w3d->ray.sdist, &w3d->ray.ddist, &w3d->ray.map);
}

void			ft_set_portal(t_w3d *w3d)
{
	int		x;

	x = WIN_X / 2;
	w3d->wall.wall_x = x;
	w3d->ray.cam_x = 2 * x / (double)WIN_X - 1;
	w3d->ray.rpos.x = w3d->cam.pos.x;
	w3d->ray.rpos.y = w3d->cam.pos.y;
	w3d->ray.rdir.x = w3d->cam.dir.x + w3d->cam.plan.x * w3d->ray.cam_x;
	w3d->ray.rdir.y = w3d->cam.dir.y + w3d->cam.plan.y * w3d->ray.cam_x;
	w3d->ray.map.x = (int)w3d->ray.rpos.x;
	w3d->ray.map.y = (int)w3d->ray.rpos.y;
	ft_calc_ray_dist(w3d, &w3d->ray.ddist, &w3d->ray.rdir);
}

void			ft_wolf_portal(t_w3d *w3d)
{
	if (w3d->port == 1)
	{
		w3d->portal.type = 1;
		ft_set_portal(w3d);
	}
	if (w3d->port == -1)
	{
		w3d->portal.type = 2;
		ft_set_portal(w3d);
	}
}
