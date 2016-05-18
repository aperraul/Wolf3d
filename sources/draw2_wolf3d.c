/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_wolf3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:44:55 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/18 15:04:54 by aperraul         ###   ########.fr       */
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

static int	ft_draw_portal(t_w3d *w3d, int *c, int *c2, int tex_y, int v)
{
	int		color;
	int		ov;

	ov = (v == 8 ? w3d->portal.ovb : w3d->portal.ovo);
	if ((v == 8 && ft_wall_side(w3d) == w3d->portal.orib) || (v == 9 && ft_wall_side(w3d) == w3d->portal.orio))
	{
		if (c[tex_y] == -16777216)
		{
			if (c2 == NULL)
				color = ft_choose_color(ov, w3d->ray.side, 0);
			else
				color = c2[tex_y];
		}
		else
		color = c[tex_y];
	}
	else
	{
		if (c2 == NULL)
			color = ft_choose_color(ov, w3d->ray.side, 0);
		else
			color = c2[tex_y];
	}
return (color);
}

void		ft_draw_texture(t_w3d *w3d, int v, int size_y, int ds, int de)
{
	t_mlx		*mlx;
	int			*colon;
	int			*colon2;
	int			tex_y;
	t_wall		*w;
	int			val;
	int			color;
	long int	a;
	void		*data;
	long int	position;

	mlx = w3d->mlx;
	w = &w3d->wall;
	colon2 = NULL;
	data = w3d->mlx->mlx_img->data;
	size_y = w3d->texture.tab_xpm[v]->size.y;
	if (v == 8 || v == 9)
	{
		val = v == 8 ? w3d->portal.ovb - 20 : w3d->portal.ovo - 20;
		if (val >= 0 && val <= 7)
			colon2 = w3d->texture.tab_textures[val][ft_tex_x(&w3d->ray, w3d->wall.pwd, w3d->texture.tab_xpm[v]->size.x)];
	}
	colon = w3d->texture.tab_textures[v][ft_tex_x(&w3d->ray, w3d->wall.pwd, w3d->texture.tab_xpm[v]->size.x)];
	while (ds < de)
	{
		a = ds * 256 - WIN_Y * 128 + w->hline * 128;
		tex_y = ((a * size_y) / w->hline) / 256;
		if (v == 8 || v == 9)
			color = ft_draw_portal(w3d, colon, colon2, tex_y, v);
		else
			color = colon[tex_y]; // simple texture;
		position = (ds * mlx->mlx_img->width) + (w->wall_x * mlx->mlx_img->octet);
		ft_memcpy(data + position, &color, (unsigned)mlx->mlx_img->octet);
		ds++;
	}
}

void		ft_draw_top(t_mlx *mlx, int x, int color, int ds)
{
	t_pt		pt;
	int			i;
	void		*data;
	long int	position;

	data = mlx->mlx_img->data;
	i = -1;
	pt.x = x;
	int max = mlx->mlx_img->width;
	while (++i < ds)
	{
		pt.y = i;
		position = (pt.y * mlx->mlx_img->width) + (pt.x * mlx->mlx_img->octet);
		if (position < 0 || position >= max * mlx->y)
		{
			ft_putstr("YOLO");
			return ;
		}
		ft_memcpy(data + position, &color, (unsigned)mlx->mlx_img->octet);
	}
}

void	ft_draw_bot(t_mlx *mlx, int x, int color, int de)
{
	void		*data;
	long int	position;
	t_pt		pt;

	data = mlx->mlx_img->data;
	pt.x = x;
	int max = mlx->mlx_img->width;
	while (de < WIN_Y)
	{
		pt.y = de;
		position = (pt.y * mlx->mlx_img->width) + (pt.x * mlx->mlx_img->octet);
		if (position < 0 || position >= max * mlx->y)
		{
			ft_putstr("YOLO");
			return ;
		}
		ft_memcpy(data + position, &color, (unsigned)mlx->mlx_img->octet);
		de++;
	}

}
