/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat3_x_mat3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:10:42 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/29 20:27:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat3	ft_mat3_x_mat3(t_mat3 a, t_mat3 b)
{
	t_mat3	result;
	size_t	x;
	size_t	y;

	result = ft_mat3();
	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			result.m[y][x] = a.m[y][0] * b.m[0][x] +
				a.m[y][1] * b.m[1][x] +
				a.m[y][2] * b.m[2][x];
			x++;
		}
		y++;
	}
	return (result);
}
