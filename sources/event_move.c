/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 15:02:54 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/17 14:48:27 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"
#include <stdio.h>

void		ft_move_forward(t_w3d *w3d, t_ptd *cpos, t_ptd *cdir)
{
	double	v;
	double	w;

	v = cdir->x * w3d->cam.mspeed;
	w = cdir->y * w3d->cam.mspeed;
	if (v >= 1)
		v = 0.95;
	if (w >= 1)
		w = 0.95;
	if (w3d->map[(int)(cpos->x + v)][(int)(cpos->y)] == 0)
		cpos->x += v;
	else if (w3d->map[(int)(cpos->x + v)][(int)(cpos->y)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x + v)][(int)(cpos->y)] == 29)
		ft_portal_o_to_b(w3d);
	if (w3d->map[(int)(cpos->x)][(int)(cpos->y + w)] == 0)
		cpos->y += w;
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y + w)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y + w)] == 29)
		ft_portal_o_to_b(w3d);
}

void		ft_move_backward(t_w3d *w3d, t_ptd *cpos, t_ptd *cdir)
{
	double	v;
	double	w;

	v = cdir->x * w3d->cam.mspeed;
	w = cdir->y * w3d->cam.mspeed;
	if (v >= 1)
		v = 0.95;
	if (w >= 1)
		w = 0.95;
	if (w3d->map[(int)(cpos->x - v)][(int)(cpos->y)] == 0)
		cpos->x -= v;
	else if (w3d->map[(int)(cpos->x - v)][(int)(cpos->y)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x - v)][(int)(cpos->y)] == 29)
		ft_portal_o_to_b(w3d);
	if (w3d->map[(int)(cpos->x)][(int)(cpos->y - w)] == 0)
		cpos->y -= w;
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y - w)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y - w)] == 29)
		ft_portal_o_to_b(w3d);
}

void		ft_move_right(t_w3d *w3d, t_ptd *cpos, t_ptd *cdir)
{
	double	v;
	double	w;

	v = cdir->x * w3d->cam.mspeed;
	w = cdir->y * w3d->cam.mspeed;
	if (v >= 1)
		v = 0.95;
	if (w >= 1)
		w = 0.95;
	if (w3d->map[(int)(cpos->x + w)][(int)(cpos->y)] == 0)
		cpos->x += w;
	else if (w3d->map[(int)(cpos->x + w)][(int)(cpos->y)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x + w)][(int)(cpos->y)] == 29)
		ft_portal_o_to_b(w3d);
	if (w3d->map[(int)(cpos->x)][(int)(cpos->y - v)] == 0)
		cpos->y -= v;
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y - v)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y - v)] == 29)
		ft_portal_o_to_b(w3d);
}

void		ft_move_left(t_w3d *w3d, t_ptd *cpos, t_ptd *cdir)
{
	double	v;
	double	w;

	v = cdir->x * w3d->cam.mspeed;
	w = cdir->y * w3d->cam.mspeed;
	if (v >= 1)
		v = 0.95;
	if (w >= 1)
		w = 0.95;
	if (w3d->map[(int)(cpos->x - w)][(int)(cpos->y)] == 0)
		cpos->x -= w;
	else if (w3d->map[(int)(cpos->x - w)][(int)(cpos->y)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x - w)][(int)(cpos->y)] == 29)
		ft_portal_o_to_b(w3d);
	if (w3d->map[(int)(cpos->x)][(int)(cpos->y + v)] == 0)
		cpos->y += v;
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y + v)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y + v)] == 29)
		ft_portal_o_to_b(w3d);
}
