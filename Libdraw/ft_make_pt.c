/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_pt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:54:07 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/04 12:51:23 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

t_pt	ft_make_pt(int x, int y)
{
	t_pt	pt;

	pt.x = x;
	pt.y = y;
	return (pt);
}

t_ptf	ft_make_ptf(float x, float y)
{
	t_ptf	ptf;

	ptf.x = x;
	ptf.y = y;
	return (ptf);
}
