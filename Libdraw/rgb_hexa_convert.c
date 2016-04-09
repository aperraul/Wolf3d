/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_hexa_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 11:36:07 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/09 11:40:43 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

t_rgb	ft_hexa_to_rgb(int hexa)
{
	t_rgb	rgb;

	rgb.r = (hexa / (256 * 256)) % 256;
	rgb.g = (hexa / 256) % 256;
	rgb.b = hexa % 256;
	return (rgb);
}

int		ft_rgb_to_hexa(t_rgb rgb)
{
	int		hexa;

	hexa = 0;
	hexa += rgb.r * 0x010000;
	hexa += rgb.g * 0x000100;
	hexa += rgb.b * 0x000001;
	return (hexa);
}
