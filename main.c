/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:58:33 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/27 19:31:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include "instance.h"
#include "libft.h"

int	mouse_callback1(int button, int x, int y, void *param)
{
	t_instance	*handles;

	(void)button;
	handles = (t_instance*)param;
	mlx_pixel_put(handles->mlx_handle, handles->mlx_window_handle, x, y,
		16777215);
	printf("x: \t%d\ny: \t%d\n\n", x, y);
	return (0);
}

int	mouse_callback2(int button, int x, int y, void *param)
{
	t_instance	*handles;

	(void)button;
	handles = (t_instance*)param;
	mlx_pixel_put(handles->mlx_handle, handles->mlx_window_handle, x, y + 10,
		16711424);
	printf("x: \t%d\ny: \t%d\n\n", x, y);
	return (0);
}

int	main(int ac, char **av)
{
	t_instance	instance;
	t_mat3		test;
	t_mat4		test2;

	(void)ac;
	(void)av;
	test = ft_mat3_identity();
	test2 = ft_mat4_identity();
	ft_print_mat3(&test);
	ft_putchar('\n');
	ft_print_mat4(&test2);
	instance = new_instance(1280, 720, "Test de fenetre");
	mlx_mouse_hook(instance.mlx_window_handle, mouse_callback1, &instance);
	mlx_mouse_hook(instance.mlx_window_handle, mouse_callback2, &instance);
	mlx_loop(instance.mlx_handle);
}
