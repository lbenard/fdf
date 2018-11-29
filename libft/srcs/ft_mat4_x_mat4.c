/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_x_mat4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:25:51 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/29 20:27:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat4	ft_mat4_x_mat4(t_mat4 a, t_mat4 b)
{
	t_mat4	result;
	size_t	x;
	size_t	y;

	result = ft_mat4();
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			result.m[y][x] = a.m[y][0] * b.m[0][x] +
				a.m[y][1] * b.m[1][x] +
				a.m[y][2] * b.m[2][x] +
				a.m[y][3] * b.m[3][x];
			x++;
		}
		y++;
	}
	return (result);
}
