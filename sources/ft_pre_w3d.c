/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_w3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:56:48 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/23 10:59:28 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

void			ft_pre_w3d(t_w3d *w3d)
{
	w3d->mlx = ft_mlx_init(w3d->mlx, WIN_X, WIN_Y, "wolf3d");
	ft_load_w3d_textures(w3d, w3d->mlx, &w3d->texture);
	w3d->cam.pos.x = w3d->spawn.x;
	w3d->cam.pos.y = w3d->spawn.y;
	ft_wolf3d(w3d);
	mlx_hook(w3d->mlx->p_win, KeyPress, KeyPressMask, ft_wolf_move, w3d);
	mlx_hook(w3d->mlx->p_win, KeyRelease, KeyPressMask, ft_release_key, w3d);
	mlx_loop_hook(w3d->mlx->p_mlx, ft_wolf3d_loop, w3d);
	mlx_loop(w3d->mlx->p_mlx);
}
