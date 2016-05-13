/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wolf3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 11:10:44 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/13 12:20:03 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

static void		ft_draw_linew3d(t_w3d *w3d, int x, int ds, int de)
{
	ft_draw_line(ft_make_line(x, ds, x, de + 1), w3d->mlx, w3d->wall.color);
}

int				ft_choose_color(int val, t_ray *r)
{
	t_rgb	rgb;
	int		c;

	if (val == 1)
		c = (0xFFFFFF);
	else if (val == 2)
		c = (0x2A7EF5);
	else if (val == 3)
		c = (0x16BA42);
	else if (val == 4)
		c = (0xF52A2A);
	else if (val == 5)
		c = (0x053566);
	else if (val == 6)
		c = (0x550544);
	else if (val == 7)
		c = (0xffa500);
	if (r->side == 0)
	{
		rgb = ft_hexa_to_rgb(c);
		rgb.r /= 2;
		rgb.g /= 2;
		rgb.b /= 2;
		return (ft_rgb_to_hexa(rgb));
	}
	return (c);
}

void			ft_draw_wolf3d(t_w3d *w3d, t_ray *r, int x)
{
	int		tex_value;
	long int	pos;

	pos = 0;
	if (w3d->wall.hline > WIN_Y)
		w3d->wall.hline = WIN_Y;
	if (w3d->map[r->map.x][r->map.y] >= 1 && w3d->map[r->map.x][r->map.y] <= 7)
	{
		/* monocouleur */
		w3d->wall.color = ft_choose_color(w3d->map[r->map.x][r->map.y], r);
		pos = ft_draw_top(w3d, x);
		ft_draw_linew3d(w3d, w3d->wall.wall_x, w3d->wall.dstart, w3d->wall.dend);
//		pos += w3d->wall.hline * w3d->mlx->mlx_img->width;
		ft_draw_bot(w3d, x);
	}
/*	else if (w3d->map[r->map.x][r->map.y] >= 20 && w3d->map[r->map.x][r->map.y] <= 29)
	{
		// textured
		x = 0;
//		pos = ft_draw_top(w3d, x);
		tex_value = w3d->map[r->map.x][r->map.y] - 20;
		pos = ft_draw_texture(w3d, pos, tex_value, 0);
//		ft_draw_bot(w3d, pos);
	}*/
}
