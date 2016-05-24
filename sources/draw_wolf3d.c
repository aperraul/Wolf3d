/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wolf3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 11:10:44 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/24 15:41:12 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

static void		ft_draw_line_w(t_mlx *mlx, int x, t_pt pt_draw, int color)
{
	t_pt		pt;
	void		*data;
	long int	position;

	pt.x = x;
	data = mlx->mlx_img->data;
	while (pt_draw.x < pt_draw.y)
	{
		pt.y = pt_draw.x;
		position = (pt.y * mlx->mlx_img->width) + (pt.x * mlx->mlx_img->octet);
		ft_memcpy(data + position, &color, (unsigned)mlx->mlx_img->octet);
		pt_draw.x++;
	}
}

int				ft_choose_color(int val, int side, int c)
{
	t_rgb	rgb;

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
	if (side == 1)
	{
		rgb = ft_hexa_to_rgb(c);
		rgb.r /= 2;
		rgb.g /= 2;
		rgb.b /= 2;
		return (ft_rgb_to_hexa(rgb));
	}
	return (c);
}

void			ft_draw_wolf3d(t_w3d *w3d, t_ray *r, int x, int map_val)
{
	int		tex_value;
	int		color;
	t_pt	pt_draw;

	pt_draw.x = w3d->wall.dstart;
	pt_draw.y = w3d->wall.dend;
	if (map_val >= 1 && map_val <= 7)
	{
		color = ft_choose_color(map_val, r->side, 0);
		ft_draw_top(w3d->mlx, x, 0x3399FF, w3d->wall.dstart);
		ft_draw_line_w(w3d->mlx, x, pt_draw, color);
		ft_draw_bot(w3d->mlx, x, 0x009900, w3d->wall.dend);
	}
	else if (map_val >= 20 && map_val <= 29)
	{
		ft_draw_top(w3d->mlx, x, 0x3399FF, w3d->wall.dstart);
		tex_value = map_val - 20;
		ft_draw_texture(w3d, tex_value, 0, pt_draw);
		ft_draw_bot(w3d->mlx, x, 0x009900, w3d->wall.dend);
	}
}

void			ft_draw_top(t_mlx *mlx, int x, int color, int ds)
{
	t_pt		pt;
	int			i;
	void		*data;
	long int	position;

	data = mlx->mlx_img->data;
	i = -1;
	pt.x = x;
	while (++i < ds)
	{
		pt.y = i;
		position = (pt.y * mlx->mlx_img->width) + (pt.x * mlx->mlx_img->octet);
		ft_memcpy(data + position, &color, (unsigned)mlx->mlx_img->octet);
	}
}

void			ft_draw_bot(t_mlx *mlx, int x, int color, int de)
{
	void		*data;
	long int	position;
	t_pt		pt;

	data = mlx->mlx_img->data;
	pt.x = x;
	while (de < WIN_Y)
	{
		pt.y = de;
		position = (pt.y * mlx->mlx_img->width) + (pt.x * mlx->mlx_img->octet);
		ft_memcpy(data + position, &color, (unsigned)mlx->mlx_img->octet);
		de++;
	}
}
