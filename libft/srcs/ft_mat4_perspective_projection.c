/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_perspective_projection.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:45:55 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/19 20:33:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

t_mat4	ft_mat4_perspective_projection(void)
{
	float	s;
	float	n;
	float	f;

	s = 1 / tan((120 / 2) * (PI / 180));
	n = 1.0f;
	f = 10.0f;
	return ((t_mat4)(struct s_mat4_data) {
		s, 0, 0, 0,
		0, s, 0, 0,
		0, 0, -(f) / ((f - n)), 0,
		0, 0, -(f * n) / (f - n), 1
	});
}
