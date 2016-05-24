/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_wolf3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:44:55 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/24 15:44:38 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

static int		ft_tex_x(t_ray *r, double pwd, int size_x)
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

static int		ft_draw_portal(t_w3d *w3d, int *c, int *c2, int tex_y)
{
	int		ov;
	int		p_side;

	ov = (w3d->v == 8 ? w3d->portal.ovb : w3d->portal.ovo);
	p_side = ft_wall_side(w3d->ray.map, w3d->cam.pos, w3d->ray.side);
	if ((w3d->v == 8 && p_side == w3d->portal.orib) ||
			(w3d->v == 9 && p_side == w3d->portal.orio))
	{
		if (c[tex_y] == -16777216)
		{
			if (c2 == NULL)
				return (ft_choose_color(ov, w3d->ray.side, 0));
			else
				return (c2[tex_y]);
		}
		else
			return (c[tex_y]);
	}
	else
	{
		if (c2 == NULL)
			return (ft_choose_color(ov, w3d->ray.side, 0));
		else
			return (c2[tex_y]);
	}
}

static void		ft_draw_tex_loop(t_w3d *w3d, t_pt d, int *c, int *c2)
{
	long int	a;
	long int	pos;
	t_pt		t_c;
	t_wall		*w;
	t_mlx		*mlx;

	w = &w3d->wall;
	mlx = w3d->mlx;
	while (d.x < d.y)
	{
		a = d.x * 256 - WIN_Y * 128 + w->hline * 128;
		t_c.x = ((a * w3d->size_y) / w->hline) / 256;
		if (w3d->v == 8 || w3d->v == 9)
			t_c.y = ft_draw_portal(w3d, c, c2, t_c.x);
		else
			t_c.y = c[t_c.x];
		pos = (d.x * mlx->mlx_img->width) + (w->wall_x * mlx->mlx_img->octet);
		ft_memcpy(w3d->data + pos, &t_c.y, (unsigned)w3d->mlx->mlx_img->octet);
		d.x++;
	}
}

void			ft_draw_texture(t_w3d *w3d, int v, int size_y, t_pt pt_draw)
{
	int			*c;
	int			*c2;
	int			val;

	c2 = NULL;
	w3d->data = w3d->mlx->mlx_img->data;
	size_y = w3d->texture.tab_xpm[v]->size.y;
	if (v == 8 || v == 9)
	{
		val = (v == 8 ? w3d->portal.ovb - 20 : w3d->portal.ovo - 20);
		if (val >= 0 && val <= 7)
			c2 = w3d->texture.tab_textures[val][ft_tex_x(&w3d->ray
					, w3d->wall.pwd, w3d->texture.tab_xpm[v]->size.x)];
	}
	c = w3d->texture.tab_textures[v]
		[ft_tex_x(&w3d->ray, w3d->wall.pwd, w3d->texture.tab_xpm[v]->size.x)];
	w3d->v = v;
	w3d->size_y = size_y;
	ft_draw_tex_loop(w3d, pt_draw, c, c2);
}
