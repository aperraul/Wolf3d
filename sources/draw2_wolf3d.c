/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_wolf3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:44:55 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/10 18:06:18 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

static int	ft_tex_x(t_ray *r, int size_x)
{
	double wallx;
}

void		ft_draw_texture(t_w3d *w3d, t_wall *w, int tex_value, int size_y)
{
	int		*colon;

	size_y = w3d->texture.tab_xpm[tex_value]->size.y;
	colon = w3d->texture.tab_textures[tex_value][ft_tex_x(&w3d->ray, w3d->texture.tab_xpm[tex_value]->size.x)];
}
