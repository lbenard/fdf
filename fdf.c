/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:58:33 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/29 20:36:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "instance.h"
#include "draw.h"
#include "colors.h"

int	main(int ac, char **av)
{
	t_instance	*instance;
	t_mat3		a;
	t_mat3		b;
	t_mat3		result;

	(void)ac;
	(void)av;
	if (!(instance = new_instance(ft_usize(1280, 720), "Test de fenetre")))
		return (-1);
	a.m[0][0] = 4;
	a.m[0][1] = 5;
	a.m[0][2] = 3;
	a.m[1][0] = 1;
	a.m[1][1] = 7;
	a.m[1][2] = 2;
	a.m[2][0] = 9;
	a.m[2][1] = 8;
	a.m[2][2] = 6;

	b.m[0][0] = 4;
	b.m[0][1] = 5;
	b.m[0][2] = 6;
	b.m[1][0] = 7;
	b.m[1][1] = 8;
	b.m[1][2] = 9;
	b.m[2][0] = 2;
	b.m[2][1] = 1;
	b.m[2][2] = 3;

	result = ft_mat3_x_mat3(a, b);
	ft_print_mat3(&result);
	draw_line(instance, ft_vec2f(0, 0), ft_vec2f(1280, 720), COLOR_WHITE,
		COLOR_BLUE);
	mlx_loop(instance->mlx);
}
