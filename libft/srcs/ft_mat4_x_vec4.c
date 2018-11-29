/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_x_vec4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:03:24 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/29 23:39:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec4f	ft_mat4_x_vec4(t_mat4 a, t_vec4f b)
{
	t_vec4f	result;

	result.x = a.m[0][0] * b.x +
		a.m[0][1] * b.y +
		a.m[0][2] * b.z +
		a.m[0][3] * b.w;
	result.y = a.m[1][0] * b.x +
		a.m[1][1] * b.y +
		a.m[1][2] * b.z +
		a.m[1][3] * b.w;
	result.z = a.m[2][0] * b.x +
		a.m[2][1] * b.y +
		a.m[2][2] * b.z +
		a.m[2][3] * b.w;
	result.w = a.m[3][0] * b.x +
		a.m[3][1] * b.y +
		a.m[3][2] * b.z +
		a.m[3][3] * b.w;
	return (result);
}
