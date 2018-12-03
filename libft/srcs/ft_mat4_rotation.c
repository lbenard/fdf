/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 02:48:36 by freezee           #+#    #+#             */
/*   Updated: 2018/12/03 03:33:33 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "math.h"

static t_mat4	ft_mat_xaxis_rotation(float x)
{
	t_mat4	ret;

	ret = ft_mat4_identity();
	ret.m[1][1] = cos(x);
	ret.m[1][2] = -sin(x);
	ret.m[2][1] = sin(x);
	ret.m[2][2] = cos(x);
	ft_print_mat4(&ret);
	return (ret);
}

static t_mat4	ft_mat_yaxis_rotation(float y)
{
	t_mat4	ret;

	ret = ft_mat4_identity();
	ret.m[0][0] = cos(y);
	ret.m[0][3] = sin(y);
	ret.m[2][0] = -ret.m[0][3];
	ret.m[2][2] = ret.m[0][0];
	return (ret);
}

static t_mat4	ft_mat_zaxis_rotation(float z)
{
	t_mat4	ret;

	ret = ft_mat4_identity();
	ret.m[0][0] = cos(z);
	ret.m[0][1] = -sin(z);
	ret.m[1][0] = -ret.m[0][1];
	ret.m[1][1] = ret.m[0][0];
	return (ret);
}

t_mat4	ft_mat4_rotation(t_vec3f rotation)
{
	t_mat4	rotation_matrix;

	rotation_matrix = ft_mat4_x_mat4(ft_mat4_x_mat4(
		ft_mat_zaxis_rotation(rotation.z),
		ft_mat_yaxis_rotation(rotation.y)),
		ft_mat_xaxis_rotation(rotation.x));
	return (rotation_matrix);
}