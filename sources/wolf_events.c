/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:43:54 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/09 11:28:39 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

static void		ft_rotate(int i, t_ptd *cdir, t_ptd *cplan, double r)
{
	if (i == 1)
	{
		double	old_dir_x;
		double	old_plan_x;

		old_dir_x = cdir->x;
		cdir->x = cdir->x * cos(-r) - cdir->y * sin(-r);
		cdir->y = old_dir_x * sin(-r) + cdir->y *cos(-r);
		old_plan_x = cplan->x;
		cplan->x = cplan->x * cos(-r) - cplan->y * sin(-r);
		cplan->y = old_plan_x * sin(-r) + cplan->y *cos(-r);
	}
	if(i == 0)
	{
		double	old_dir_x;
		double	old_plan_x;

		old_dir_x = cdir->x;
		cdir->x = cdir->x * cos(r) - cdir->y * sin(r);
		cdir->y = old_dir_x * sin(r) + cdir->y *cos(r);
		old_plan_x = cplan->x;
		cplan->x = cplan->x * cos(r) - cplan->y * sin(r);
		cplan->y = old_plan_x * sin(r) + cplan->y *cos(r);
	}
}

static void		ft_move(int i, t_w3d *w3d, t_ptd *cpos, t_ptd *cdir, double s)
{
	if (i == 1)
	{
		if (w3d->map[(int)(cpos->x + cdir->x * s)][(int)(cpos->y)] == 0)
			cpos->x += cdir->x * s;
		if (w3d->map[(int)(cpos->x)][(int)(cpos->y + cdir->y * s)] == 0)
			cpos->y += cdir->y * s;
	}
	if (i == 0)
	{
		if (w3d->map[(int)(cpos->x - cdir->x * s)][(int)(cpos->y)] == 0)
			cpos->x -= cdir->x * s;
		if (w3d->map[(int)(cpos->x)][(int)(cpos->y - cdir->y * s)] == 0)
			cpos->y -= cdir->y * s;
	}
}

void			ft_wolf_events(t_w3d *w3d)
{
	w3d->cam.mspeed = w3d->delt.dt * 5;
	w3d->cam.rspeed = w3d->delt.dt * 3;
	if (w3d->cam.keym == 1 || w3d->cam.keym == -1)
	{
		if (w3d->cam.keym == 1)
			ft_move(1, w3d, &w3d->cam.pos, &w3d->cam.dir, w3d->cam.mspeed);
		else
			ft_move(0, w3d, &w3d->cam.pos, &w3d->cam.dir, w3d->cam.mspeed);
	}
	if (w3d->cam.keyr == 1 || w3d->cam.keyr == -1)
	{
		if (w3d->cam.keyr == 1)
			ft_rotate(1, &w3d->cam.dir, &w3d->cam.plan, w3d->cam.rspeed);
		else
			ft_rotate(0, &w3d->cam.dir, &w3d->cam.plan, w3d->cam.rspeed);
	}
}
