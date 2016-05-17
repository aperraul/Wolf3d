/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wolf3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 11:10:44 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/17 15:04:36 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

static void		ft_draw_line_w(t_w3d *w3d, int x, int ds, int de)
{
	ft_draw_line(ft_make_line(x, ds, x, de), w3d->mlx, w3d->wall.color);
}

void			ft_choose_color(int val, int side, int *c)
{
	t_rgb	rgb;

	if (val == 1)
		*c = (0xFFFFFF);
	else if (val == 2)
		*c = (0x2A7EF5);
	else if (val == 3)
		*c = (0x16BA42);
	else if (val == 4)
		*c = (0xF52A2A);
	else if (val == 5)
		*c = (0x053566);
	else if (val == 6)
		*c = (0x550544);
	else if (val == 7)
		*c = (0xffa500);
	if (side == 1)
	{
		rgb = ft_hexa_to_rgb(*c);
		rgb.r /= 2;
		rgb.g /= 2;
		rgb.b /= 2;
		*c = ft_rgb_to_hexa(rgb);
	}
}

void			ft_draw_wolf3d(t_w3d *w3d, t_ray *r, int x, int map_val)
{
//	int		tex_value;
//
	if (map_val >= 1 && map_val <= 7)
	{
		ft_choose_color(map_val, r->side, &w3d->wall.color);
//		ft_draw_top(w3d, x);
		ft_draw_line_w(w3d, x, w3d->wall.dstart, w3d->wall.dend);
//		ft_draw_bot(w3d, x);
	}
/*	else if (map_val >= 20 && map_val <= 29)
	{
		ft_draw_top(w3d, x);
		tex_value = map_val - 20;
		ft_draw_texture(w3d, tex_value, 0);
		ft_draw_bot(w3d, x);
	}*/
}
