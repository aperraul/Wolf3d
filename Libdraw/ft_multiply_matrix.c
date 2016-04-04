/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiply_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 15:31:01 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/18 14:21:03 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

t_matrix	ft_multiply_matrix(t_matrix m1, t_matrix m2)
{
	t_matrix	m3;

	m3.x.x = (m1.x.x * m2.x.x) + (m1.y.x * m2.x.y) + (m1.z.x * m2.x.z);
	m3.x.y = (m1.x.x * m2.y.x) + (m1.y.x * m2.y.y) + (m1.z.x * m2.y.z);
	m3.x.z = (m1.x.x * m2.z.x) + (m1.y.x * m2.z.y) + (m1.z.x * m2.z.z);
	m3.y.x = (m1.x.y * m2.x.x) + (m1.y.y * m2.x.y) + (m1.z.y * m2.x.z);
	m3.y.y = (m1.x.y * m2.y.x) + (m1.y.y * m2.y.y) + (m1.z.y * m2.y.z);
	m3.y.z = (m1.x.y * m2.z.x) + (m1.y.y * m2.z.y) + (m1.z.y * m2.z.z);
	m3.z.x = (m1.x.z * m2.x.x) + (m1.y.z * m2.x.y) + (m1.z.z * m2.x.z);
	m3.z.y = (m1.x.z * m2.y.x) + (m1.y.z * m2.y.y) + (m1.z.z * m2.y.z);
	m3.z.z = (m1.x.z * m2.z.x) + (m1.y.z * m2.z.y) + (m1.z.z * m2.z.z);
	return (m3);
}
