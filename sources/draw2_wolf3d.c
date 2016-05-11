/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_wolf3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:44:55 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/11 14:33:27 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

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

int		ft_draw_texture(t_w3d *w3d, int pos, int tex_value, int size_y)
{
	int			*colon;
	int			tex_y;
	t_wall		*w;
	int			color;
	long int	a;

	w = &w3d->wall;
	size_y = w3d->texture.tab_xpm[tex_value]->size.y;
	colon = w3d->texture.tab_textures[tex_value][ft_tex_x(&w3d->ray, w3d->wall.pwd, w3d->texture.tab_xpm[tex_value]->size.x)];
	while (w->dstart < w->dend)
	{
		a = w->dstart * 256 - WIN_Y * 128 + w->hline * 128;
		tex_y = ((a * size_y) / w->hline) / 256;
		color = colon[tex_y];
		ft_memcpy(w3d->mlx->mlx_img->data + pos, &color, w3d->mlx->mlx_img->octet);
		pos += w3d->mlx->mlx_img->width;
		w->dstart++;
	}
	return (pos);
}

int		ft_draw_top(t_w3d *w3d, int x)
{
	int		i;
	int		pos;
	int		color;

	pos = x * w3d->mlx->mlx_img->octet;
	color = 0x3399FF;
	i = -1;
	while (++i < w3d->wall.dstart)
	{
		ft_memcpy(w3d->mlx->mlx_img->data + pos, &color, w3d->mlx->mlx_img->octet);
		pos += w3d->mlx->mlx_img->width;
	}
	return (pos);
}

void	ft_draw_bot(t_w3d *w3d, int pos)
{
	int		color;
	int		i;
	int		s;

	s = w3d->wall.dend - 1;
	color = 0x009900;
	i = WIN_Y;
	while (++s < i)
	{
		ft_memcpy(w3d->mlx->mlx_img->data + pos, &color, w3d->mlx->mlx_img->octet);
		pos += w3d->mlx->mlx_img->width;
	}
}
