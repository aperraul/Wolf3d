/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 15:10:06 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/18 14:21:22 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

t_matrix	ft_make_matrix_x(float rad)
{
	t_matrix	m;

	m.x = ft_make_vector(1.0f, 0.0f, 0.0f);
	m.y = ft_make_vector(0.0f, cosf(rad), -sinf(rad));
	m.z = ft_make_vector(0.0f, sinf(rad), cosf(rad));
	return (m);
}

t_matrix	ft_make_matrix_y(float rad)
{
	t_matrix	m;

	m.x = ft_make_vector(cosf(rad), 0.0f, sinf(rad));
	m.y = ft_make_vector(0.0f, 1.0f, 0.0f);
	m.z = ft_make_vector(-sinf(rad), 0.0f, cosf(rad));
	return (m);
}

t_matrix	ft_make_matrix_z(float rad)
{
	t_matrix	m;

	m.x = ft_make_vector(cosf(rad), -sinf(rad), 0.0f);
	m.y = ft_make_vector(sinf(rad), cosf(rad), 0.0f);
	m.z = ft_make_vector(0.0f, 0.0f, 1.0f);
	return (m);
}
