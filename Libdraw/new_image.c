/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 16:05:40 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/18 14:21:35 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

void		ft_new_image(t_mlx *mlx)
{
	t_img	*img;
	void	*a;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return ;
	img->endian = 0;
	img->width = mlx->x;
	img->p_img = mlx_new_image(mlx->p_mlx, mlx->x, mlx->y);
	if (!(img->p_img))
		return ;
	a = mlx_get_data_addr(img->p_img, &img->bpp, &img->width, &img->endian);
	img->data = a;
	mlx->mlx_img = img;
	mlx->mlx_img->max_size = (img->bpp / 8) * mlx->x * mlx->y;
}
