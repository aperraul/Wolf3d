/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wolf3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 11:10:44 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/08 17:31:06 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

static void		ft_draw_linew3d(t_w3d *w3d, int x, int ds, int de)
{
		ft_draw_line(ft_make_line(x, ds, x, de), w3d->mlx, w3d->wall.color);
}

static void		ft_choose_color(t_w3d *w3d, t_pt *m)
{
	if (w3d->map[m->x][m->y] == 1)
	{
		w3d->wall.color = 0xFFFFFF;
//		if (w3d->ray.side == 1)
//			w3d->wall.color /= 2;
	}
	else if (w3d->map[m->x][m->y] == 2)
	{
		w3d->wall.color = 0x2A7EF5;
//		if (w3d->ray.side == 1)
//			w3d->wall.color /= 2;
	}
	else if (w3d->map[m->x][m->y] == 3)
	{
		w3d->wall.color = 0x16BA42;
//		if (w3d->ray.side == 1)
//			w3d->wall.color /= 2;
	}
	else if (w3d->map[m->x][m->y] == 4)
	{
		w3d->wall.color = 0xF52A2A;
//		if (w3d->ray.side == 1)
//			w3d->wall.color /= 2;
	}
}

void			ft_draw_wolf3d(t_w3d *w3d, t_wall *w, t_ray *r)
{
	if (r->side == 0)
		w->pwd = (r->map.x - r->rpos.x + (1 - r->step.x) / 2) / r->rdir.x;
	else
		w->pwd = (r->map.y - r->rpos.y + (1 - r->step.y) / 2) / r->rdir.y;
	w->hline = (int)(WIN_X / w->pwd);
	w->dstart = -w->hline / 2 + WIN_X / 2;
	if (w->dstart < 0)
		w->dstart = 0;
	w->dend = w->hline / 2 + WIN_X / 2;
	if (w->dstart >= WIN_X)
		w->dstart = WIN_X - 1;
	ft_choose_color(w3d, &w3d->ray.map);
	ft_draw_linew3d(w3d, w3d->wall.wall_x, w3d->wall.dstart, w3d->wall.dend);
}
