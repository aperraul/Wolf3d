/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:59:10 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/03 14:46:05 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

void		ft_draw_pixel(t_mlx *mlx, int color, t_pt pt)
{
	long int		position;
	void			*data;

	position = (pt.y * mlx->mlx_img->width) + (pt.x * mlx->mlx_img->octet);
	if (pt.y >= mlx->y || pt.y < 0 || pt.x >= mlx->x || pt.x < 0)
		return ;
	if (position < 0 || position >= mlx->mlx_img->width * mlx->y)
		return ;
	data = mlx->mlx_img->data;
	ft_memcpy(data + position, &color, (unsigned)mlx->mlx_img->octet);
}
