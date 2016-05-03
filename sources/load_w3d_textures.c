/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_w3d_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 16:23:40 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/03 16:48:52 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

static int	ft_load_img(t_mlx *mlx, t_img *img, char *texture)
{
	void	*d;

	img->endian= 0;
	img->p_img = mlx_xpm_file_to_image(mlx->p_mlx, texture, & img->size.x, &img->size.y);
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

void		ft_load_w3d_textures(t_w3d *w3d, t_mlx *mlx, t_texture *tex)
{
	ft_load_img(mlx, &tex->bluestone, "./textures/bluestone.xpm");
	ft_load_img(mlx, &tex->colorstone, "./textures/colorstone.xpm");
	ft_load_img(mlx, &tex->eagle, "./textures/eagle.xpm");
	ft_load_img(mlx, &tex->greystone, "./textures/greystone.xpm");
	ft_load_img(mlx, &tex->mossy, "./textures/mossy.xpm");
	ft_load_img(mlx, &tex->purplestone, "./textures/purplestone.xpm");
	ft_load_img(mlx, &tex->redbrick, "./textures/redbrick.xpm");
	ft_load_img(mlx, &tex->wood, "./textures/wood.xpm");
}
