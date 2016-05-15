/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_w3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:56:48 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/15 17:50:50 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

void	ft_pre_w3d(t_w3d *w3d)
{
	int x;
	int	y;


	w3d->mlx = ft_mlx_init(w3d->mlx, WIN_X, WIN_Y, "wolf3d");
	ft_load_w3d_textures(w3d, w3d->mlx, &w3d->texture);
	y = -1;
	while (++y < w3d->nb_lines)
	{
		x = -1;
		while (++x < w3d->nb_x_line[y])
		{
			ft_putnbr(w3d->map[y][x]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	ft_wolf3d(w3d);
	mlx_hook(w3d->mlx->p_win, KeyPress, KeyPressMask, ft_wolf_move, w3d);
	mlx_hook(w3d->mlx->p_win, KeyRelease, KeyPressMask, ft_release_key, w3d);
	mlx_loop_hook(w3d->mlx->p_mlx, ft_wolf3d_loop, w3d);
	mlx_loop(w3d->mlx->p_mlx);
}
