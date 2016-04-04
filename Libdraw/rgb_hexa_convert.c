/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_hexa_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 11:36:07 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/23 12:16:55 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

t_rgb	ft_hexa_to_rgb(int hexa)
{
	t_rgb	rgb;

	rgb.r = ((hexa >> 16) & 0xFF) / 255;
	rgb.g = ((hexa >> 8) & 0xFF) / 255;
	rgb.b = (hexa & 0xFF) / 255;
	return (rgb);
}

int		ft_rgb_to_rgb(t_rgb rgb)
{
	int		hexa;

	hexa = 0;
	hexa += rgb.r * 0x010000;
	hexa += rgb.g * 0x000100;
	hexa += rgb.b * 0x000001;
	return (hexa);
}
