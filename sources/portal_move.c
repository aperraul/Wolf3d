/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:31:30 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/02 12:59:32 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

static void		ft_port_rot(int ob, int oo, int mode, t_w3d *w3d)
{
	double rot;

	rot = 0.0;
	if (mode == 1)
	{
		rot = ob * (M_PI / 2) - oo * (M_PI / 2);
			rot += M_PI;
		if (rot < 0)
		{
			rot = -rot;
			ft_rotate(0, &w3d->cam.dir, &w3d->cam.plan, rot);
		}
		else
			ft_rotate(1, &w3d->cam.dir, &w3d->cam.plan, rot);
	}
	if (mode == 2)
		rot = fmod(oo * (M_PI / 2) - ob * (M_PI / 2), M_2_PI);
}

void			ft_portal_b_to_o(t_w3d *w3d)
{
	ft_port_rot(w3d->portal.orib, w3d->portal.orio, 1, w3d);
	if (w3d->portal.orib == 1)
	{
		if (w3d->portal.orio == 1)
		{
			w3d->cam.pos.x = w3d->portal.poso.x + 1.5;
			w3d->cam.pos.y = w3d->portal.poso.y + 0.5;
		}
		else if (w3d->portal.orio == 3)
		{
			w3d->cam.pos.x = w3d->portal.poso.x - 0.5;
			w3d->cam.pos.y = w3d->portal.poso.y + 0.5;
		}
		else if (w3d->portal.orio == 2)
		{
			w3d->cam.pos.x = w3d->portal.poso.x + 0.5;
			w3d->cam.pos.y = w3d->portal.poso.y + 1.5;
		}
		else if (w3d->portal.orio == 4)
		{
			w3d->cam.pos.x = w3d->portal.poso.x + 0.5;
			w3d->cam.pos.y = w3d->portal.poso.y - 0.5;
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
}

//void			ft_portal_o_to_b(t_w3d *w3d)