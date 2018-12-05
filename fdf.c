/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:58:33 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/03 18:13:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "instance.h"
#include "draw.h"
#include "colors.h"
#include "renderer.h"
#include "mesh.h"
#include "keycodes.h"

int	camera_control_callback(t_instance *instance, int keycode, void *param)
{
	t_renderer	*renderer;

	(void)instance;
	renderer = (t_renderer*)param;
	if (keycode == KEY_W)
		renderer->camera.position.z += 10.0f;
	if (keycode == KEY_S)
		renderer->camera.position.z -= 10.0f;
	if (keycode == KEY_A)
		renderer->camera.position.x -= 10.0f;
	if (keycode == KEY_D)
		renderer->camera.position.x += 10.0f;
	if (keycode == KEY_SPACEBAR)
		renderer->camera.position.y -= 10.0f;
	if (keycode == KEY_SHIFT_LEFT)
		renderer->camera.position.y += 10.0f;
	if (keycode == KEY_PAD_4)
		renderer->camera.rotation.y -= 0.1f;
	if (keycode == KEY_PAD_6)
		renderer->camera.rotation.y += 0.1f;
	if (keycode == KEY_PAD_8)
		renderer->camera.rotation.x -= 0.1f;
	if (keycode == KEY_PAD_5)
		renderer->camera.rotation.x += 0.1f;
	update_view_mesh(renderer);
	update_projection_mesh(renderer);
	render(renderer);
	return (1);
}


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
		new_camera(ft_vec3f(0.0f, 0.0f, 0.0f), ft_vec2f(0.0f, 0.0f),
		orthographic))))
		return (-1);
	render(renderer);
	instance_add_key_callback(instance, camera_control_callback, &renderer);
//	draw_mesh(instance, renderer->projection_mesh);
	//draw_line(instance, ft_vec2f(1280, 0), ft_vec2f(0, 720), COLOR_WHITE,
	//	COLOR_WHITE);
	//draw_line(instance, ft_vec2f(100, 100), ft_vec2f(200, 100), COLOR_WHITE, COLOR_WHITE);
	//draw_line(instance, ft_vec2f(200, 100), ft_vec2f(100, 199.500427f), COLOR_WHITE, COLOR_WHITE);
	mlx_loop(instance->mlx);
}
