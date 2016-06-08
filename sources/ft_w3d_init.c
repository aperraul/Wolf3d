/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_w3d_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:12:05 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/08 12:15:17 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

static void		ft_del_tab_textures(t_texture *t)
{
	int		x;
	int		y;

	if (t->tab_textures)
	{
		x = -1;
		while (++x <= 9)
		{
			y = t->tab_xpm[x]->size.y;
			while (y--)
			{
				if (t->tab_textures[x][y])
					ft_memdel((void **)&t->tab_textures[x][y]);
			}
			if (t->tab_textures[x])
				free(t->tab_textures[x]);
		}
		free(t->tab_textures);
	}
	if (t->tab_xpm)
		free(t->tab_xpm);
}

static void		ft_del_tab_xpm(t_mlx *mlx, t_texture t)
{
	if (t.bluestone.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.bluestone.p_img);
	if (t.colorstone.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.colorstone.p_img);
	if (t.eagle.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.eagle.p_img);
	if (t.greystone.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.greystone.p_img);
	if (t.mossy.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.mossy.p_img);
	if (t.purplestone.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.purplestone.p_img);
	if (t.redbrick.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.redbrick.p_img);
	if (t.wood.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.wood.p_img);
	if (t.blueportal.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.blueportal.p_img);
	if (t.orangeportal.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.orangeportal.p_img);
}

void			ft_del_map(t_w3d *w3d)
{
	int		y;

	if (w3d->map)
	{
		y = -1;
		while (w3d->map[++y])
			ft_memdel((void **)&w3d->map[y]);
		free(w3d->map);
	}
}

void			ft_clear_w3d(t_w3d *w3d)
{
	if (w3d->texture.tab_textures)
		ft_del_tab_textures(&w3d->texture);
	if (w3d->texture.tab_xpm)
		ft_del_tab_xpm(w3d->mlx, w3d->texture);
	ft_del_map(w3d);
	if (w3d->nb_x_line)
		free(w3d->nb_x_line);
	if (w3d->mlx)
		ft_clear_mlx(w3d->mlx);
	free(w3d);
}

t_w3d			*ft_w3d_init(void)
{
	t_w3d	*w3d;

	w3d = (t_w3d *)ft_memalloc(sizeof(t_w3d));
	w3d->nb_x_line = NULL;
	w3d->map = NULL;
	w3d->mlx = NULL;
	w3d->texture.tab_xpm = NULL;
	w3d->texture.tab_textures = NULL;
	w3d->nb_lines = 0;
	w3d->nb_spawn = 0;
	w3d->cam.dir.x = -1;
	w3d->cam.dir.y = 0;
	w3d->cam.plan.x = 0;
	w3d->cam.plan.y = 0.66;
	w3d->delt.dt = 0;
	w3d->cam.keym = 0;
	w3d->cam.keyr = 0;
	w3d->port = 0;
	w3d->sprint = 0;
	w3d->portal.nbb = 0;
	w3d->portal.nbo = 0;
	w3d->portal.posb = ft_make_pt(-1, -1);
	w3d->portal.poso = ft_make_pt(-1, -1);
	return (w3d);
}
