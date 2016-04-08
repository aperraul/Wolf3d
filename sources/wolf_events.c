/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:43:54 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/08 11:45:18 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

static void		ft_rotate(char *str, t_w3d *w3d)
{
	if (!ft_strcmp(str, "right"))
	{
		double	old_dir_x;
		double	old_plan_x;

		old_dir_x = w3d->cam.dir_x;
		w3d->cam.dir_x = w3d->cam.dir_x * cos(-w3d->cam.rspeed) - w3d->cam.dir_y * sin(-w3d->cam.rspeed);
		w3d->cam.dir_y = old_dir_x * sin(-w3d->cam.rspeed) + w3d->cam.dir_y *cos(-w3d->cam.rspeed);
		old_plan_x = w3d->cam.plan_x;
		w3d->cam.plan_x = w3d->cam.plan_x * cos(-w3d->cam.rspeed) - w3d->cam.plan_y * sin(-w3d->cam.rspeed);
		w3d->cam.plan_y = old_plan_x * sin(-w3d->cam.rspeed) + w3d->cam.plan_y *cos(-w3d->cam.rspeed);
	}
	if(!ft_strcmp(str, "left"))
	{
		double	old_dir_x;
		double	old_plan_x;

		old_dir_x = w3d->cam.dir_x;
		w3d->cam.dir_x = w3d->cam.dir_x * cos(w3d->cam.rspeed) - w3d->cam.dir_y * sin(w3d->cam.rspeed);
		w3d->cam.dir_y = old_dir_x * sin(w3d->cam.rspeed) + w3d->cam.dir_y *cos(w3d->cam.rspeed);
		old_plan_x = w3d->cam.plan_x;
		w3d->cam.plan_x = w3d->cam.plan_x * cos(w3d->cam.rspeed) - w3d->cam.plan_y * sin(w3d->cam.rspeed);
		w3d->cam.plan_y = old_plan_x * sin(w3d->cam.rspeed) + w3d->cam.plan_y *cos(w3d->cam.rspeed);
	}
}

static void		ft_move(char *str, t_w3d *w3d)
{
	if (!ft_strcmp(str, "forward"))
	{
		if (w3d->map[(int)(w3d->cam.pos_x + w3d->cam.dir_x * w3d->cam.mspeed)][(int)(w3d->cam.pos_y)] == 0)
			w3d->cam.pos_x += w3d->cam.dir_x * w3d->cam.mspeed;
		if (w3d->map[(int)(w3d->cam.pos_x)][(int)(w3d->cam.pos_y + w3d->cam.dir_y * w3d->cam.mspeed)] == 0)
			w3d->cam.pos_y += w3d->cam.pos_y * w3d->cam.mspeed;
	}
	if (!ft_strcmp(str, "backward"))
	{
		if (w3d->map[(int)(w3d->cam.pos_x - w3d->cam.dir_x * w3d->cam.mspeed)][(int)(w3d->cam.pos_y)] == 0)
			w3d->cam.pos_x -= w3d->cam.dir_x * w3d->cam.mspeed;
		if (w3d->map[(int)(w3d->cam.pos_x)][(int)(w3d->cam.pos_y - w3d->cam.dir_y * w3d->cam.mspeed)] == 0)
			w3d->cam.pos_y -= w3d->cam.pos_y * w3d->cam.mspeed;
	}
}

void			ft_wolf_events(t_w3d *w3d)
{
	w3d->cam.mspeed = w3d->delt.dt * 5;
	w3d->cam.rspeed = w3d->delt.dt * 3;
	if (w3d->cam.keym == 1 || w3d->cam.keym == -1)
	{
		if (w3d->cam.keym == 1)
			ft_move("forward", w3d);
		else
			ft_move("backword", w3d);
	}
	if (w3d->cam.keyr == 1 || w3d->cam.keyr == -1)
	{
		if (w3d->cam.keyr == 1)
			ft_rotate("right", w3d);
		else
			ft_rotate("left", w3d);
	}
}
