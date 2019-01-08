/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 02:48:36 by freezee           #+#    #+#             */
/*   Updated: 2019/01/07 12:43:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "math.h"

static t_mat4	ft_mat_xaxis_rotation(float x)
{
	float	c;
	float	s;

	c = cos(x);
	s = sin(x);
	return ((t_mat4)(struct s_mat4_data) {
		1, 0, +0, 0,
		0, c, -s, 0,
		0, s, +c, 0,
		0, 0, +0, 1
	});
}

static t_mat4	ft_mat_yaxis_rotation(float y)
{
	float	c;
	float	s;

	c = cos(y);
	s = sin(y);
	return ((t_mat4)(struct s_mat4_data) {
		+c, 0, s, 0,
		+0, 1, 0, 0,
		-s, 0, c, 0,
		+0, 0, 0, 1
	});
}

static t_mat4	ft_mat_zaxis_rotation(float z)
{
	float	c;
	float	s;

	c = cos(z);
	s = sin(z);
	return ((t_mat4)(struct s_mat4_data) {
		c, -s, 0, 0,
		s, +c, 0, 0,
		0, +0, 1, 0,
		0, +0, 0, 1
	});
}

t_mat4			ft_mat4_rotation(t_vec3f rotation)
{
	return (ft_mat4_x_mat4(ft_mat4_x_mat4(
		ft_mat_zaxis_rotation(rotation.z),
		ft_mat_yaxis_rotation(rotation.y)),
		ft_mat_xaxis_rotation(rotation.x)));
}
