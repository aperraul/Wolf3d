/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_w3d_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 16:23:40 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/24 14:04:19 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

static int		ft_load_img(t_mlx *mlx, t_img *img, char *texture)
{
	void	*d;

	img->endian = 0;
	img->p_img = mlx_xpm_file_to_image(mlx->p_mlx, texture, &img->size.x
			, &img->size.y);
	if (!img->p_img)
	{
		img->loaded = 0;
		return (1);
	}
	d = mlx_get_data_addr(img->p_img, &img->bpp, &img->width, &img->endian);
	img->octet = img->bpp / 8;
	img->data = d;
	img->max_size = img->octet * img->size.x * img->size.y;
	img->loaded = 1;
	return (0);
}

static void		ft_tab_xpm(t_texture *tex)
{
	tex->tab_xpm = (t_img **)ft_memalloc(sizeof(t_img) * 10);
	tex->tab_xpm[0] = &tex->bluestone;
	tex->tab_xpm[1] = &tex->colorstone;
	tex->tab_xpm[2] = &tex->eagle;
	tex->tab_xpm[3] = &tex->greystone;
	tex->tab_xpm[4] = &tex->mossy;
	tex->tab_xpm[5] = &tex->purplestone;
	tex->tab_xpm[6] = &tex->redbrick;
	tex->tab_xpm[7] = &tex->wood;
	tex->tab_xpm[8] = &tex->blueportal;
	tex->tab_xpm[9] = &tex->orangeportal;
}

static void		ft_tab_texture(t_texture *tex)
{
	int		a;
	int		x;
	int		y;

	tex->tab_textures = (int ***)ft_memalloc(sizeof(int **) * 10);
	a = -1;
	while (++a < 10)
	{
		x = tex->tab_xpm[a]->size.x;
		tex->tab_textures[a] = (int **)ft_memalloc(sizeof(int *) * x);
		while (x--)
		{
			y = tex->tab_xpm[a]->size.y;
			tex->tab_textures[a][x] = (int *)ft_memalloc(sizeof(int) * y);
			while (y--)
				tex->tab_textures[a][x][y] = ft_get_pixel_image(tex->tab_xpm[a],
						ft_make_pt(x, y));
		}
	}
}

void			ft_load_w3d_textures(t_w3d *w3d, t_mlx *mlx, t_texture *tex)
{
	int k;

	k = 0;
	k += ft_load_img(mlx, &tex->bluestone, "./textures/bluestone.xpm");
	k += ft_load_img(mlx, &tex->colorstone, "./textures/colorstone.xpm");
	k += ft_load_img(mlx, &tex->eagle, "./textures/eagle.xpm");
	k += ft_load_img(mlx, &tex->greystone, "./textures/greystone.xpm");
	k += ft_load_img(mlx, &tex->mossy, "./textures/mossy.xpm");
	k += ft_load_img(mlx, &tex->purplestone, "./textures/purplestone.xpm");
	k += ft_load_img(mlx, &tex->redbrick, "./textures/redbrick.xpm");
	k += ft_load_img(mlx, &tex->wood, "./textures/wood.xpm");
	k += ft_load_img(mlx, &tex->blueportal, "./textures/blueportal.xpm");
	k += ft_load_img(mlx, &tex->orangeportal, "./textures/orangeportal.xpm");
	if (k > 0)
	{
		ft_putstr("textures load fail\n");
		ft_clear_w3d(w3d);
		exit(0);
	}
	ft_putstr("textures load succes\n");
	ft_tab_xpm(tex);
	ft_tab_texture(tex);
}
