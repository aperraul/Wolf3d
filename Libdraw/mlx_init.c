/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:47:28 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/18 14:21:30 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

t_mlx	*ft_mlx_init(t_mlx *mlx, int size_x, int size_y, char *title)
{
	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->p_mlx = mlx_init();
	mlx->x = size_x;
	mlx->y = size_y;
	mlx->p_win = mlx_new_window(mlx->p_mlx, mlx->x, mlx->y, title);
	ft_new_image(mlx);
	return (mlx);
}
