/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:31:30 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/14 15:51:48 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

static double				ft_port_rot(int ob, int oo, int mode)
{
	double rot;

	if (mode == 1)
		rot = (ob * M_PI + (oo * M_PI + M_PI));
	if (mode == 2)
		rot = (oo * M_PI + (ob * M_PI + M_PI));
	return (rot);
}

void			ft_portal_b_to_o(t_w3d *w3d)
{
	double		rot;

	rot = ft_port_rot(w3d->portal.orib, w3d->portal.orio, 1);
	if (w3d->portal.orib == 1)
	{
		if (w3d->portal.orio == 1)
	}

}

void			ft_portal_o_to_b(t_w3d *w3d)
{

}
