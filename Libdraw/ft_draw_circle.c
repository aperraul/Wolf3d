/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:21:02 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/18 14:20:16 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

void		ft_draw_circle(t_mlx *mlx, t_pt center, int size, int color)
{
	t_pt	pt;
	float	rad;

	rad = 0;
	while (rad < (2 * 3.141f))
	{
		pt.x = (center.x + size * cos(rad));
		pt.y = (center.y + size * sin(rad));
		ft_draw_pixel(mlx, color, pt);
		rad += (3.141f / 2000);
	}
	size--;
	while (size > 0)
	{
		rad = 0;
		while (rad < (2 * 3.141f))
		{
			pt.x = (center.x + size * cos(rad));
			pt.y = (center.y + size * sin(rad));
			ft_draw_pixel(mlx, 0x00acac, pt);
			rad += (3.141f / 2000);
		}
		size--;
	}
}
