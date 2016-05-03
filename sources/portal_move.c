/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:31:30 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/03 12:37:51 by aperraul         ###   ########.fr       */
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
	}
	else if (mode == 2)
	{
		rot = oo * (M_PI / 2) - ob * (M_PI / 2);
		rot += M_PI;
	}
	if (rot < 0)
	{
		rot = -rot;
		ft_rotate(0, &w3d->cam.dir, &w3d->cam.plan, rot);
	}
	else
		ft_rotate(1, &w3d->cam.dir, &w3d->cam.plan, rot);
}

static int		ft_verif_tp(t_w3d *w3d, int p_ori, t_pt p_pos)
{
	t_ptd	c_pos;

	c_pos = w3d->cam.pos;
	if (p_ori == 1)
	{
		if (c_pos.y >= p_pos.y && c_pos.y <= p_pos.y + 1 && c_pos.x > p_pos.x + 1)
			return (1);
	}
	else if (p_ori == 4)
	{
		if (c_pos.x >= p_pos.x && c_pos.x <= p_pos.x + 1 && c_pos.y < p_pos.y)
			return (1);
	}
	else if (p_ori == 3)
	{
		if (c_pos.y >= p_pos.y && c_pos.y <= p_pos.x + 1 && c_pos.x < p_pos.x)
			return (1);
	}
	else if (p_ori == 2)
	{
		if (c_pos.x >= p_pos.x && c_pos.x <= p_pos.x + 1 && c_pos.y > p_pos.y + 1)
			return (1);
	}
	return (0);
}

void			ft_portal_b_to_o(t_w3d *w3d)
{
	if (ft_verif_tp(w3d, w3d->portal.orib, w3d->portal.posb) && w3d->portal.nbo > 0)
	{
		ft_port_rot(w3d->portal.orib, w3d->portal.orio, 1, w3d);
		if (w3d->portal.orio == 1)
		{
			w3d->cam.pos.x = w3d->portal.poso.x + 1.1;
			w3d->cam.pos.y = w3d->portal.poso.y + 0.5;
		}
		else if (w3d->portal.orio == 3)
		{
			w3d->cam.pos.x = w3d->portal.poso.x - 0.1;
			w3d->cam.pos.y = w3d->portal.poso.y + 0.5;
		}
		else if (w3d->portal.orio == 2)
		{
			w3d->cam.pos.x = w3d->portal.poso.x + 0.5;
			w3d->cam.pos.y = w3d->portal.poso.y + 1.1;
		}
		else if (w3d->portal.orio == 4)
		{
			w3d->cam.pos.x = w3d->portal.poso.x + 0.5;
			w3d->cam.pos.y = w3d->portal.poso.y - 0.1;
		}
	}
}

void		ft_portal_o_to_b(t_w3d *w3d)
{
	if (ft_verif_tp(w3d, w3d->portal.orio, w3d->portal.poso) && w3d->portal.nbb > 0)
	{
		ft_port_rot(w3d->portal.orib, w3d->portal.orio, 2, w3d);
		if (w3d->portal.orib == 1)
		{
			w3d->cam.pos.x = w3d->portal.posb.x + 1.5;
			w3d->cam.pos.y = w3d->portal.posb.y + 0.5;
		}
		else if (w3d->portal.orib == 3)
		{
			w3d->cam.pos.x = w3d->portal.posb.x - 0.5;
			w3d->cam.pos.y = w3d->portal.posb.y + 0.5;
		}
		else if (w3d->portal.orib == 2)
		{
			w3d->cam.pos.x = w3d->portal.posb.x + 0.5;
			w3d->cam.pos.y = w3d->portal.posb.y + 1.5;
		}
		else if (w3d->portal.orib == 4)
		{
			w3d->cam.pos.x = w3d->portal.posb.x + 0.5;
			w3d->cam.pos.y = w3d->portal.posb.y - 0.5;
		}
	}
}
