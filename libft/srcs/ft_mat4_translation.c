/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_translation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 02:27:56 by freezee           #+#    #+#             */
/*   Updated: 2018/12/03 02:32:40 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat4	ft_mat4_translation(t_vec3f translation)
{
	t_mat4	translation_matrix;

	translation_matrix = ft_mat4_identity();
	translation_matrix.m[0][3] = translation.x;
	translation_matrix.m[1][3] = translation.y;
	translation_matrix.m[2][3] = translation.z;
	return (translation_matrix);
}