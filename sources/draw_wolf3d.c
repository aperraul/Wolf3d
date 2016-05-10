/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wolf3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 11:10:44 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/10 17:54:03 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

static void		ft_draw_linew3d(t_w3d *w3d, int x, int ds, int de)
{
	ft_draw_line(ft_make_line(x, ds, x, de), w3d->mlx, w3d->wall.color);
}

static void		ft_choose_color(t_w3d *w3d, t_pt *m)
{
	t_rgb rgb;

	if (w3d->map[m->x][m->y] == 1)
		w3d->wall.color = 0xFFFFFF;
	else if (w3d->map[m->x][m->y] == 2)
		w3d->wall.color = 0x2A7EF5;
	else if (w3d->map[m->x][m->y] == 3)
		w3d->wall.color = 0x16BA42;
	else if (w3d->map[m->x][m->y] == 4)
		w3d->wall.color = 0xF52A2A;
	else if (w3d->map[m->x][m->y] == 5)
		w3d->wall.color = 0x053566;
	else if (w3d->map[m->x][m->y] == 6)
		w3d->wall.color = 0x550544;
	else if (w3d->map[m->x][m->y] == 7)
		w3d->wall.color = 0xffa500;
/*	else if (w3d->map[m->x][m->y] == 21)
		w3d->wall.color = 0x33ccff;
	else if (w3d->map[m->x][m->y] == 22)
		w3d->wall.color = 0xff8533;*/
	if (w3d->ray.side == 1)
	{
		rgb = ft_hexa_to_rgb(w3d->wall.color);
		rgb.r /= 2;
		rgb.g /= 2;
		rgb.b /= 2;
		w3d->wall.color = ft_rgb_to_hexa(rgb);
	}
}

void			ft_draw_wolf3d(t_w3d *w3d, t_ray *r)
{
	int		tex_value;

	if (w3d->map[r->map.x][r->map.y] > 1 && w3d->map[r->map.x][r->map.y] < 7)
	{
		// monocouleur
		ft_choose_color(w3d, &w3d->ray.map);
		//ft_draw_top;
		ft_draw_linew3d(w3d, w3d->wall.wall_x, w3d->wall.dstart, w3d->wall.dend);
		//ft_draw_bot;
	}
	else
	{
		// textured
		//ft_draw_top;
		tex_value = w3d->map[r->map.x][r->map.y] - 20;
		ft_draw_texture(w3d, &w3d->wall, tex_value, 0);
		//ft_draw_bot;
	}




}
