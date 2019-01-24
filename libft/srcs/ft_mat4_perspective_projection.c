/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_perspective_projection.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:45:55 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/24 18:07:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

t_mat4	ft_mat4_perspective_projection(void)
{
	return ((t_mat4)(struct s_mat4_data) {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 0, 1,
		0, 0, 1.0f / 500.0f, 1
	});
}
