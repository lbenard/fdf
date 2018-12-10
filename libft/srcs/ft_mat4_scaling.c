/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_scaling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:38:06 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/07 21:47:10 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat4	ft_mat4_scaling(t_vec3f scaling)
{
	float	x;
	float	y;
	float	z;

	x = scaling.x;
	y = scaling.y;
	z = scaling.z;
	return ((t_mat4)(struct s_mat4_data) {
		x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1
	});
}
