/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:25:31 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/30 18:39:00 by lbenard          ###   ########.fr       */
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
	t_mat4	ret;

	cos_pitch = cos(rotation.x);
	sin_pitch = sin(rotation.x);
	cos_yaw = cos(rotation.y);
	sin_yaw = sin(rotation.y);
	ret.m[0][0] = cos_yaw;
	ret.m[0][1] = sin_yaw * sin_pitch;
	ret.m[0][2] = sin_yaw * cos_pitch;
	ret.m[1][1] = cos_pitch;
	ret.m[1][2] = -sin_pitch;
	ret.m[2][0] = -sin_yaw;
	ret.m[2][1] = cos_yaw * sin_pitch;
	ret.m[2][2] = cos_pitch * cos_yaw;
	ret.m[3][0] = -ft_vec3f_dot(ft_vec3f(cos_yaw, 0, -sin_yaw), position);
	ret.m[3][1] = -ft_vec3f_dot(ft_vec3f(sin_yaw * sin_pitch, cos_pitch,
		cos_yaw * sin_pitch), position);
	ret.m[3][2] = -ft_vec3f_dot(ft_vec3f(sin_yaw * cos_pitch, -sin_pitch,
		cos_pitch * cos_yaw), position);
	return (ret);
}
