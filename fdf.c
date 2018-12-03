/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:58:33 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/03 03:44:36 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "instance.h"
#include "draw.h"
#include "colors.h"
#include "renderer.h"
#include "mesh.h"

int	main(int ac, char **av)
{
	t_instance		*instance;
	t_renderer		*renderer;
	t_projection	orthographic;

	(void)ac;
	(void)av;
	if (!(instance = new_instance(ft_usize(1280, 720), "Test de fenetre")))
		return (-1);
	orthographic.projection = ft_mat4_identity();
	orthographic.projection.m[2][2] = 0.0f;
	if (!(renderer = new_renderer(instance,
		new_mesh(av[1]),
		new_camera(ft_vec3f(0.0f, 0.0f, 0.0f), ft_vec2f(1.0f, 0.0f),
		orthographic))))
		return (-1);
	draw_mesh(instance, renderer->model_mesh);
	draw_mesh(instance, renderer->view_mesh);
	//draw_line(instance, ft_vec2f(1280, 0), ft_vec2f(0, 720), COLOR_WHITE,
	//	COLOR_WHITE);
	//draw_line(instance, ft_vec2f(100, 100), ft_vec2f(200, 100), COLOR_WHITE, COLOR_WHITE);
	//draw_line(instance, ft_vec2f(200, 100), ft_vec2f(100, 199.500427f), COLOR_WHITE, COLOR_WHITE);
	mlx_loop(instance->mlx);
}
