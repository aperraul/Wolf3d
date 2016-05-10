/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:06:57 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/10 12:12:46 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

int		ft_get_pixel_image(t_img *img, t_pt pt)
{
	long int	position;

	position = (pt.y * img->width) + (pt.x * img->octet);
	if (pt.y >= img->size.y || pt.y < 0 || pt.x >= img->size.x || pt.x < 0)
		return (0);
	if (position < 0 || position > img->max_size)
		return (0);
	return (*(unsigned int *)(unsigned long)(img->data + position));
}

int		ft_get_pixel(t_mlx *mlx, t_pt pt)
{
	long int	position;

	position = (pt.y * mlx->mlx_img->width) + (pt.x * mlx->mlx_img->octet);
	if (pt.y >= mlx->y || pt.y < 0 || pt.x >= mlx->x || pt.x < 0)
		return (0);
	if (position < 0 || position > mlx->mlx_img->max_size)
		return (0);
	return (*(unsigned int *)(unsigned long)(mlx->mlx_img->data + position));
}
