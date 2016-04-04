/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:14:21 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/18 14:20:38 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

t_line		ft_make_line(int x1, int y1, int x2, int y2)
{
	t_line		line;

	line.start = ft_make_pt(x1, y1);
	line.end = ft_make_pt(x2, y2);
	line.dx = x2 - x1;
	line.dy = y2 - y1;
	return (line);
}
