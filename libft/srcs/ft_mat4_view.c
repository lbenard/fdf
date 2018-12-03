/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:25:31 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/02 01:10:27 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "math.h"

t_mat4	ft_mat4_view(t_vec3f position, t_vec2f rotation)
{
	float	cos_pitch;
	float	sin_pitch;
	float	cos_yaw;
	float	sin_yaw;
	t_vec3f	xaxis;
	t_vec3f	yaxis;
	t_vec3f	zaxis;
	t_mat4	ret;

	cos_pitch = cos(rotation.x);
	sin_pitch = sin(rotation.x);
	cos_yaw = cos(rotation.y);
	sin_yaw = sin(rotation.y);
	xaxis = ft_vec3f(cos_yaw, 0, -sin_yaw);
	yaxis = ft_vec3f(sin_yaw * sin_pitch, cos_pitch, cos_yaw * sin_pitch);
	zaxis = ft_vec3f(sin_yaw * cos_pitch, -sin_pitch, cos_pitch * cos_yaw);
	ret.m[0][0] = xaxis.x;
	ret.m[0][1] = yaxis.x;
	ret.m[0][2] = zaxis.x;
	ret.m[0][3] = 0;
	ret.m[1][0] = xaxis.y;
	ret.m[1][1] = yaxis.y;
	ret.m[1][2] = zaxis.y;
	ret.m[1][3] = 0;
	ret.m[2][0] = xaxis.z;
	ret.m[2][1] = yaxis.z;
	ret.m[2][2] = zaxis.z;
	ret.m[2][3] = 0;
	ret.m[3][0] = -ft_vec3f_dot(xaxis, position);
	ret.m[3][1] = -ft_vec3f_dot(yaxis, position);
	ret.m[3][2] = -ft_vec3f_dot(zaxis, position);
	ret.m[3][3] = 1;
	return (ret);
}
