/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wolf3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 11:10:44 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/08 13:01:27 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

static void		ft_draw_ver_line(t_w3d *w3d)
{
		ft_draw_line(ft_make_line(w3d->wall.wall_x, w3d->wall.drawstart, w3d->wall.wall_x, w3d->wall.drawend), w3d->mlx, w3d->wall.color);
}

static void		ft_choose_color(t_w3d *w3d)
{
	if (w3d->map[w3d->ray.map_x][w3d->ray.map_y] == 1)
	{
		w3d->wall.color = 0xFFFFFF;
//		if (w3d->ray.side == 1)
//			w3d->wall.color /= 2;
	}
	else if (w3d->map[w3d->ray.map_x][w3d->ray.map_y] == 2)
	{
		w3d->wall.color = 0x2A7EF5;
//		if (w3d->ray.side == 1)
//			w3d->wall.color /= 2;
	}
	else if (w3d->map[w3d->ray.map_x][w3d->ray.map_y] == 3)
	{
		w3d->wall.color = 0x16BA42;
//		if (w3d->ray.side == 1)
//			w3d->wall.color /= 2;
	}
	else if (w3d->map[w3d->ray.map_x][w3d->ray.map_y] == 4)
	{
		w3d->wall.color = 0xF52A2A;
//		if (w3d->ray.side == 1)
//			w3d->wall.color /= 2;
	}
}

void			ft_draw_wolf3d(t_w3d *w3d)
{
	if (w3d->ray.side == 0)
		w3d->wall.pwd = (w3d->ray.map_x - w3d->ray.raypos_x + (1 - w3d->ray.step_x) / 2) / w3d->ray.raydir_x;
	else
		w3d->wall.pwd = (w3d->ray.map_y - w3d->ray.raypos_y + (1 - w3d->ray.step_y) / 2) / w3d->ray.raydir_y;
	w3d->wall.hightline = (int)(WIN_X / w3d->wall.pwd);
	w3d->wall.drawstart = -w3d->wall.hightline / 2 + WIN_X / 2;
	if (w3d->wall.drawstart < 0)
		w3d->wall.drawstart = 0;
	w3d->wall.drawend = w3d->wall.hightline / 2 + WIN_X / 2;
	if (w3d->wall.drawstart >= WIN_X)
		w3d->wall.drawstart = WIN_X - 1;
	ft_choose_color(w3d);
	ft_draw_ver_line(w3d);
}
