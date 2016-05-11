/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_side.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:53:24 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/11 11:30:00 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

int		ft_wall_side(t_w3d *w3d)
{
	int		wall_side;

	if (w3d->ray.side == 0)
	{
		if (w3d->cam.pos.x > w3d->ray.map.x)
			return (wall_side = 1);
		else if (w3d->cam.pos.x < w3d->ray.map.x)
			return (wall_side = 3);
	}
	else if (w3d->ray.side == 1)
	{
		if (w3d->cam.pos.y > w3d->ray.map.y)
			return (wall_side = 2);
		else if (w3d->cam.pos.y < w3d->ray.map.y)
			return (wall_side = 4);
	}
	return (0);
}
