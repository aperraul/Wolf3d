/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 15:02:54 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/13 14:25:05 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"
#include <stdio.h>

void		ft_move_forward(t_w3d *w3d, t_ptd *cpos, t_ptd *cdir)
{
	double	s;

	s = w3d->cam.mspeed;
	if (w3d->map[(int)(cpos->x + cdir->x * s)][(int)(cpos->y)] == 0)
		cpos->x += cdir->x * s;
	else if (w3d->map[(int)(cpos->x + cdir->x * s)][(int)(cpos->y)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x + cdir->x * s)][(int)(cpos->y)] == 29)
		ft_portal_o_to_b(w3d);
	if (w3d->map[(int)(cpos->x)][(int)(cpos->y + cdir->y * s)] == 0)
		cpos->y += cdir->y * s;
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y + cdir->y * s)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y + cdir->y * s)] == 29)
		ft_portal_o_to_b(w3d);
}

void		ft_move_backward(t_w3d *w3d, t_ptd *cpos, t_ptd *cdir)
{
	double	s;

	s = w3d->cam.mspeed;
	if (w3d->map[(int)(cpos->x - cdir->x * s)][(int)(cpos->y)] == 0)
		cpos->x -= cdir->x * s;
	else if (w3d->map[(int)(cpos->x - cdir->x * s)][(int)(cpos->y)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x - cdir->x * s)][(int)(cpos->y)] == 29)
		ft_portal_o_to_b(w3d);
	if (w3d->map[(int)(cpos->x)][(int)(cpos->y - cdir->y * s)] == 0)
		cpos->y -= cdir->y * s;
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y - cdir->y * s)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y - cdir->y * s)] == 29)
		ft_portal_o_to_b(w3d);
}

void		ft_move_right(t_w3d *w3d, t_ptd *cpos, t_ptd *cdir)
{
	double	s;

	s = w3d->cam.mspeed;
	if (w3d->map[(int)(cpos->x + cdir->y * s)][(int)(cpos->y)] == 0)
		cpos->x += cdir->y * s;
	else if (w3d->map[(int)(cpos->x + cdir->y * s)][(int)(cpos->y)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x + cdir->y * s)][(int)(cpos->y)] == 29)
		ft_portal_o_to_b(w3d);
	if (w3d->map[(int)(cpos->x)][(int)(cpos->y - cdir->x * s)] == 0)
		cpos->y -= cdir->x * s;
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y - cdir->x * s)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y - cdir->x * s)] == 29)
		ft_portal_o_to_b(w3d);
}

void		ft_move_left(t_w3d *w3d, t_ptd *cpos, t_ptd *cdir)
{
	double	s;

	s = w3d->cam.mspeed;
	if (w3d->map[(int)(cpos->x - cdir->y * s)][(int)(cpos->y)] == 0)
		cpos->x -= cdir->y * s;
	else if (w3d->map[(int)(cpos->x - cdir->y * s)][(int)(cpos->y)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x - cdir->y * s)][(int)(cpos->y)] == 29)
		ft_portal_o_to_b(w3d);
	if (w3d->map[(int)(cpos->x)][(int)(cpos->y + cdir->x * s)] == 0)
		cpos->y += cdir->x * s;
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y + cdir->x * s)] == 28)
		ft_portal_b_to_o(w3d);
	else if (w3d->map[(int)(cpos->x)][(int)(cpos->y + cdir->x * s)] == 29)
		ft_portal_o_to_b(w3d);
}
