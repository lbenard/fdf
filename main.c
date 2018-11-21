/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:58:33 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/21 19:56:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include "instance.h"

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

	(void)ac;
	(void)av;
	instance = new_instance(1280, 720, "Test de fenetre");
	mlx_mouse_hook(instance.mlx_window_handle, mouse_callback1, &instance);
	mlx_mouse_hook(instance.mlx_window_handle, mouse_callback2, &instance);
	mlx_loop(instance.mlx_handle);
}
