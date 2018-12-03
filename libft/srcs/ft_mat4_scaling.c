/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_scaling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:38:06 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/03 02:25:59 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat4	ft_mat4_scaling(t_vec3f scaling)
{
	t_mat4	scaling_matrix;

	scaling_matrix = ft_mat4_identity();
	scaling_matrix.m[0][0] = scaling.x;
	scaling_matrix.m[1][1] = scaling.y;
	scaling_matrix.m[2][2] = scaling.z;
	return (scaling_matrix);
}
