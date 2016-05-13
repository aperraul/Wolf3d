/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:09:07 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/13 16:32:55 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

void	ft_set_blue_portal(t_w3d *w3d, t_pt *m)
{
	w3d->portal.nbb++;
	if (w3d->portal.nbb > 1)
	{
		w3d->map[w3d->portal.posb.x][w3d->portal.posb.y] = w3d->portal.ovb;
		w3d->portal.nbb--;
	}
	w3d->portal.orib = ft_wall_side(w3d);
	w3d->portal.posb.x = m->x;
	w3d->portal.posb.y = m->y;
	if (w3d->portal.posb.x == w3d->portal.poso.x &&
			w3d->portal.posb.y == w3d->portal.poso.y)
	{
		w3d->portal.poso = ft_make_pt(-1, -1);
		w3d->portal.nbo -= 1;
		w3d->portal.ovb = w3d->portal.ovo;
	}
	else
		w3d->portal.ovb = w3d->map[m->x][m->y];
	w3d->map[m->x][m->y] = 28;
}

void	ft_set_orange_portal(t_w3d *w3d, t_pt *m)
{
	w3d->portal.nbo++;
	if (w3d->portal.nbo > 1)
	{
		w3d->map[w3d->portal.poso.x][w3d->portal.poso.y] = w3d->portal.ovo;
		w3d->portal.nbo--;
	}
	w3d->portal.orio = ft_wall_side(w3d);
	w3d->portal.poso.x = m->x;
	w3d->portal.poso.y = m->y;
	if (w3d->portal.poso.x == w3d->portal.posb.x &&
			w3d->portal.poso.y == w3d->portal.posb.y)
	{
		w3d->portal.posb = ft_make_pt(-1, -1);
		w3d->portal.nbb -= 1;
		w3d->portal.ovo = w3d->portal.ovb;
	}
	else
		w3d->portal.ovo = w3d->map[m->x][m->y];
	w3d->map[m->x][m->y] = 29;
}
