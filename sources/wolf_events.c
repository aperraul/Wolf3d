/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:43:54 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/07 14:06:39 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

void		ft_rotate(int i, t_ptd *cdir, t_ptd *cplan, double r)
{
	double	old_dir_x;
	double	old_plan_x;

	if (i == 1)
	{
		old_dir_x = cdir->x;
		cdir->x = cdir->x * cos(-r) - cdir->y * sin(-r);
		cdir->y = old_dir_x * sin(-r) + cdir->y * cos(-r);
		old_plan_x = cplan->x;
		cplan->x = cplan->x * cos(-r) - cplan->y * sin(-r);
		cplan->y = old_plan_x * sin(-r) + cplan->y * cos(-r);
	}
	if (i == 0)
	{
		old_dir_x = cdir->x;
		cdir->x = cdir->x * cos(r) - cdir->y * sin(r);
		cdir->y = old_dir_x * sin(r) + cdir->y * cos(r);
		old_plan_x = cplan->x;
		cplan->x = cplan->x * cos(r) - cplan->y * sin(r);
		cplan->y = old_plan_x * sin(r) + cplan->y * cos(r);
	}
}

void		ft_wolf_events(t_w3d *w3d)
{
	w3d->cam.mspeed = w3d->delt.dt * 5 + w3d->sprint;
	w3d->cam.rspeed = w3d->delt.dt * 3;
	if (w3d->cam.keym == 1 || w3d->cam.keym == -1)
	{
		if (w3d->cam.keym == 1)
			ft_move_forward(w3d, &w3d->cam.pos, &w3d->cam.dir);
		else
			ft_move_backward(w3d, &w3d->cam.pos, &w3d->cam.dir);
	}
	if (w3d->cam.keym == 2 || w3d->cam.keym == -2)
	{
		if (w3d->cam.keym == -2)
			ft_move_right(w3d, &w3d->cam.pos, &w3d->cam.dir);
		else
			ft_move_left(w3d, &w3d->cam.pos, &w3d->cam.dir);
	}
	if (w3d->cam.keyr == 1 || w3d->cam.keyr == -1)
	{
		if (w3d->cam.keyr == 1)
			ft_rotate(1, &w3d->cam.dir, &w3d->cam.plan, w3d->cam.rspeed);
		else
			ft_rotate(0, &w3d->cam.dir, &w3d->cam.plan, w3d->cam.rspeed);
	}
}
