/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_w3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:56:48 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/06 13:43:57 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

void	ft_pre_w3d(t_w3d *w3d)
{
	w3d->mlx = ft_mlx_init(w3d->mlx, WIN_X, WIN_Y, "wolf3d");
	ft_wolf3d(w3d);
	mlx_loop_hook(w3d->mlx->p_mlx, ft_wolf3d_loop, w3d);
	mlx_loop(w3d->mlx->p_mlx);
}
