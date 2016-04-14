/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:31:30 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/14 18:53:53 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

static double				ft_port_rot(int ob, int oo, int mode)
{
	double rot;

	if (mode == 1)
		rot = fmod((ob * M_PI + (oo * M_PI + M_PI)), M_2_PI);
	if (mode == 2)
		rot = fmod((oo * M_PI + (ob * M_PI + M_PI)), M_2_PI);
	return (rot);
}

void			ft_portal_b_to_o(t_w3d *w3d)
{
	double		rot;

	rot = ft_port_rot(w3d->portal.orib, w3d->portal.orio, 1);
	if (w3d->portal.orib == 0)
	{
		if (w3d->portal.orio == 0)
		{
			w3d->cam.pos.x = w3d->portal.poso.x + 1.2;
			w3d->cam.pos.y = w3d->portal.poso.y;
		}
		else if (w3d->portal.orio == 1)
		{
			w3d->cam.pos.x = w3d->portal.poso.x - 0.2;
			w3d->cam.pos.y = w3d->portal.poso.y;
		}
		else if (w3d->portal.orio == 2)
		{
			w3d->cam.pos.x = w3d->portal.poso.x;
			w3d->cam.pos.y = w3d->portal.poso.y + 1.2;
		}
		else if (w3d->portal.orio == 3)
		{
			w3d->cam.pos.x = w3d->portal.poso.x;
			w3d->cam.pos.y = w3d->portal.poso.y - 0.2;
		}
	}
	/*
	else if (w3d->portal.orib == 0)
	{
		if (w3d->portal.orio == 0)

		else if (w3d->portal.orio == 1)

		else if (w3d->portal.orio == 2)

		else if (w3d->portal.orio == 3)
	}
	else if (w3d->portal.orib == 0)
	{
		if (w3d->portal.orio == 0)

		else if (w3d->portal.orio == 1)

		else if (w3d->portal.orio == 2)

		else if (w3d->portal.orio == 3)
	}
	else if (w3d->portal.orib == 0)
	{
		if (w3d->portal.orio == 0)

		else if (w3d->portal.orio == 1)

		else if (w3d->portal.orio == 2)

		else if (w3d->portal.orio == 3)
	}*/
	ft_rotate(1, &w3d->cam.dir, &w3d->cam.plan, rot);
}

//void			ft_portal_o_to_b(t_w3d *w3d)
