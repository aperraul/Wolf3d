/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_side.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:53:24 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/18 15:30:33 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int		ft_wall_side(t_pt map, t_ptd pos, int side)
{
	int		wall_side;
	int		posx;
	int		posy;
	int		mapx;
	int		mapy;

	posx = pos.x;
	posy = pos.y;
	mapx = map.x;
	mapy = map.y;
	if (side == 0)
	{
		if (posx > mapx)
			return (wall_side = 1);
		else if (posx < mapx)
			return (wall_side = 3);
	}
	else if (side == 1)
	{
		if (posy > mapy)
			return (wall_side = 2);
		else if (posy < mapy)
			return (wall_side = 4);
	}
	return (0);
}
