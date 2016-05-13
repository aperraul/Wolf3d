/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_wolf3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:44:55 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/13 15:29:03 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

static int	ft_tex_x(t_ray *r, double pwd, int size_x)
{
	double	wallx;
	int		tex_x;

	if (r->side == 0)
		wallx = r->rpos.y + pwd * r->rdir.y;
	else
		wallx = r->rpos.x + pwd * r->rdir.x;
	wallx -= floor(wallx);
	tex_x = (int)(wallx * (double)size_x);
	if (r->side == 0 && r->rdir.x > 0)
		tex_x = size_x - tex_x - 1;
	if (r->side == 1 && r->rdir.y < 0)
		tex_x = size_x - tex_x - 1;
	return (tex_x);
}

void		ft_draw_texture(t_w3d *w3d, int tex_value, int size_y)
{
	int			*colon;
	int			*colon2;
	int			tex_y;
	t_wall		*w;
	int			val;
	int			color;
	long int	a;

	w = &w3d->wall;
	size_y = w3d->texture.tab_xpm[tex_value]->size.y;
	if (tex_value == 8 || tex_value == 9)
	{
		val = tex_value == 8 ? w3d->portal.ovb - 20 : w3d->portal.ovo - 20;
		if (val >= 0 && val <= 7)
			colon2 = w3d->texture.tab_textures[val][ft_tex_x(&w3d->ray, w3d->wall.pwd, w3d->texture.tab_xpm[tex_value]->size.x)];
	}
	colon = w3d->texture.tab_textures[tex_value][ft_tex_x(&w3d->ray, w3d->wall.pwd, w3d->texture.tab_xpm[tex_value]->size.x)];
	while (w->dstart < w->dend)
	{
		a = w->dstart * 256 - WIN_Y * 128 + w->hline * 128;
		tex_y = ((a * size_y) / w->hline) / 256;
		if (colon[tex_y] == -16777216)
		{
			if (tex_value == 8 && (w3d->portal.ovb >= 1 && w3d->portal.ovb <= 7))
				color = ft_choose_color(w3d->portal.ovb, &w3d->ray);
			else if (tex_value == 9 && (w3d->portal.ovb >= 1 && w3d->portal.ovb <= 7))
				color = ft_choose_color(w3d->portal.ovo, &w3d->ray);
			else
				color = colon2[tex_y];
		}
		else
		{
			if ((tex_value == 8 && ft_wall_side(w3d) == w3d->portal.orib) || (tex_value == 9 && ft_wall_side(w3d) == w3d->portal.orio))
				color = colon[tex_y]; //side wall with portal
			else if (tex_value == 8 || tex_value == 9)
				color = colon2[tex_y]; //side wall without portal;
			else
				color = colon[tex_y]; // simple texture;
		}
		ft_draw_pixel(w3d->mlx, color, ft_make_pt(w3d->wall.wall_x, w->dstart));
//		ft_memcpy(w3d->mlx->mlx_img->data + pos, &color, w3d->mlx->mlx_img->octet);
//pos += w3d->mlx->mlx_img->width;
		w->dstart++;
	}
}

void		ft_draw_top(t_w3d *w3d, int x)
{
	int		i;
	int		color;

	color = 0x3399FF;
	i = -1;
	while (++i < w3d->wall.dstart)
		ft_draw_pixel(w3d->mlx, color, ft_make_pt(x, i));
}

void	ft_draw_bot(t_w3d *w3d, int x)
{
	int		color;
	int		i;
	int		s;

	s = w3d->wall.dend;
	color = 0x009900;
	i = WIN_Y;
	while (++s < i)
		ft_draw_pixel(w3d->mlx, color, ft_make_pt(x, s));
}
