/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:59:10 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/18 14:19:40 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

void		ft_draw_pixel(t_mlx *mlx, int color, t_pt pt)
{
	long int		position;
	long int		octet;

	octet = mlx->mlx_img->bpp / 8;
	position = (pt.y * mlx->mlx_img->width) + (pt.x * octet);
	if (pt.y >= mlx->y || pt.y < 0 || pt.x >= mlx->x || pt.x < 0)
		return ;
	if (position < 0 || position > mlx->mlx_img->width * mlx->y)
		return ;
	if (ft_memcmp(mlx->mlx_img->data + position, &color, (unsigned)octet) != 0)
		ft_memcpy(mlx->mlx_img->data + position, &color, (unsigned)octet);
}
