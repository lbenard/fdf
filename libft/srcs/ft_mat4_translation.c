/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_translation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 02:27:56 by freezee           #+#    #+#             */
/*   Updated: 2018/12/08 16:35:55 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat4	ft_mat4_translation(t_vec3f translation)
{
	float	x;
	float	y;
	float	z;

	x = translation.x;
	y = translation.y;
	z = translation.z;
	return ((t_mat4)(struct s_mat4_data) {
		1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1
	});
}