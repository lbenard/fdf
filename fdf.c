/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:58:33 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/10 16:31:50 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "instance.h"
#include "renderer.h"
#include "mesh.h"
#include "keycodes.h"
#include "parser.h"
#include "errors.h"
#include <stdlib.h>
#include <stdio.h>

int	camera_control_callback(t_instance *instance, int keycode, void *param)
{
	t_renderer	*renderer;

	(void)instance;
	renderer = (t_renderer*)param;
	if (keycode == KEY_W)
		renderer->model_mesh->position.z += 10.0f;
	if (keycode == KEY_S)
		renderer->model_mesh->position.z -= 10.0f;
	if (keycode == KEY_A)
		renderer->model_mesh->position.x -= 10.0f;
	if (keycode == KEY_D)
		renderer->model_mesh->position.x += 10.0f;
	if (keycode == KEY_SPACEBAR)
		renderer->model_mesh->position.y -= 10.0f;
	if (keycode == KEY_SHIFT_LEFT)
		renderer->model_mesh->position.y += 10.0f;
	if (keycode == KEY_PAD_4)
		renderer->model_mesh->rotation.y -= 0.1f;
	if (keycode == KEY_PAD_6)
		renderer->model_mesh->rotation.y += 0.1f;
	if (keycode == KEY_PAD_8)
		renderer->model_mesh->rotation.x -= 0.1f;
	if (keycode == KEY_PAD_5)
		renderer->model_mesh->rotation.x += 0.1f;
	if (keycode == KEY_PAD_ADD)
	{
		renderer->model_mesh->scale.x *= 1.1f;
		renderer->model_mesh->scale.y *= 1.1f;
		renderer->model_mesh->scale.z *= 1.1f;
	}
	if (keycode == KEY_PAD_SUB)
	{
		renderer->model_mesh->scale.x /= 1.1f;
		renderer->model_mesh->scale.y /= 1.1f;
		renderer->model_mesh->scale.z /= 1.1f;
	}
	update_model_mesh(renderer);
	update_projection_mesh(renderer);
	render(renderer);
	return (1);
}

int	expose_callback(void *param)
{
	(void)param;
	printf("Expose\n");
	return (1);
}

#include <errno.h>

int	main(int ac, char **av)
{
	t_instance		*instance;
	t_renderer		*renderer;
	t_isize			map_size;

	if (ac != 2)
	{
		throw_error_str("missing file operand");
		return (-1);
	}
	if (!(instance = new_instance(ft_usize(1280, 720), "fdf")))
	{
		throw_error();
		return (-1);
	}
	if (!(renderer = new_renderer(instance, parse_map(av[1]))))
	{
		free(instance);
		throw_error();
		return (-1);
	}
	map_size = get_map_size(av[1]);
	if (map_size.x == -1 || map_size.y == -1)
	{
		free(instance);
		free(renderer);
		throw_error_str("Invalid map size");
		return (-1);
	}
	renderer->raw_mesh->position.x -= (map_size.x * 10 - 10) / 2.0f;
	renderer->raw_mesh->position.z -= (map_size.y * 10 - 10) / 2.0f;
	init_raw_mesh(renderer);
	renderer->model_mesh->rotation.x = 0.5f;
	renderer->model_mesh->rotation.y = -0.4f;
	renderer->model_mesh->scale.x = 5.0f;
	renderer->model_mesh->scale.y = 5.0f;
	renderer->model_mesh->scale.z = 5.0f;
	instance_add_key_callback(instance, camera_control_callback, &renderer);
	//instance_add_expose_callback(instance, expose_callback, &instance);
	mlx_loop(instance->mlx);
}
