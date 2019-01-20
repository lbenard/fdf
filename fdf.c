/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:58:33 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/20 18:07:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "instance.h"
#include "renderer.h"
#include "mesh.h"
#include "keycodes.h"
#include "parser.h"
#include "errors.h"
#include "model.h"
#include "controls.h"
#include <stdlib.h>
#include <unistd.h>
#include "batch.h"

#include <stdio.h>

int	loop_hook(t_instance *instance)
{
	t_renderer		*renderer;
	t_u8			*keys;
	static size_t	focused_model = 0;
	size_t			i;
	t_model			*model;
	t_list			*model_list;

	renderer = instance->renderer;
	keys = instance->window->keys;
	if (keys[window_exit])
	{
		free_instance(instance);
		exit(0);
	}
	if (keys[model_previous] && focused_model != 0)
	{
		focused_model--;
		keys[model_previous] = 0;
	}
	if (keys[model_next] && focused_model + 1 < instance->renderer->batch->size)
	{
		focused_model++;
		keys[model_next] = 0;
	}
	model = batch_get_model_by_id(instance->renderer->batch, focused_model);
	model->position.x -= 5.0f * keys[model_translation_nx];
	model->position.x += 5.0f * keys[model_translation_px];
	model->position.y -= 5.0f * keys[model_translation_ny];
	model->position.y += 5.0f * keys[model_translation_py];
	model->position.z -= 5.0f * keys[model_translation_nz];
	model->position.z += 5.0f * keys[model_translation_pz];
	model->rotation.x -= 0.02f * keys[model_rotation_nx];
	model->rotation.x += 0.02f * keys[model_rotation_px];
	model->rotation.y -= 0.02f * keys[model_rotation_ny];
	model->rotation.y += 0.02f * keys[model_rotation_py];
	model->scale = ft_vec3f_scalar(model->scale, 1.0f + 0.1f
		* keys[model_scale_zoom]);
	model->scale = ft_vec3f_scalar(model->scale, 1.0f / (1.0f + 0.1f *
		keys[model_scale_dezoom]));
	model->scale.y *= 1.0f + (0.1f * keys[model_scale_stretch]);
	model->scale.y /= 1.0f + (0.1f * keys[model_scale_flatten]);

	camera_rotate(renderer->camera, ft_vec2f(
		-(0.04f * keys[camera_rotation_nx])
		+ (0.04f * keys[camera_rotation_px]),
		-(0.04f * keys[camera_rotation_ny])
		+ (0.04f * keys[camera_rotation_py])));
	camera_translate(renderer->camera, ft_vec3f(
		-(5.0f * keys[camera_translation_nx])
		+ (5.0f * keys[camera_translation_px]),
		-(5.0f * keys[camera_translation_ny])
		+ (5.0f * keys[camera_translation_py]),
		-(5.0f * keys[camera_translation_nz])
		+ (5.0f * keys[camera_translation_pz])));
	model_list = renderer->batch->batch;
	while (model_list)
	{
		model_update_model((t_model*)model_list->content);
		model_update_view((t_model*)model_list->content,
			instance->renderer->camera);
		model_list = model_list->next;
	}
	renderer_render(instance->renderer);
	i = 0;
	while (batch_get_model_by_id(instance->renderer->batch, i))
	{
		mlx_string_put(instance->mlx, instance->window->handle, 0, 20 * i + 10,
			0xFFFFFF, (i == focused_model) ? "> " : "  ");
		mlx_string_put(instance->mlx, instance->window->handle,
			20, 20 * i + 10, 0xFFFFFF,
			(char*)batch_get_model_by_id(instance->renderer->batch, i)->name);
		i++;
	}
	usleep(1.0 / 120.0 * 1000000);
	return (1);
}

int	main(int ac, const char **av)
{
	t_instance		*instance;
	t_renderer		*renderer;
	t_model			*added_model;
	size_t			i;

	if (ac < 2)
		return (!throw_error_str("Missing file operand"));
	if (!(instance = new_instance(ft_usize(1920, 1080), "fdf")))
		return (!throw_error_str("error while creating instance"));
	if (!(renderer = new_renderer(instance)))
	{
		free(instance);
		return (!throw_error_str("error while creating renderer"));
	}
	instance->renderer = renderer;
	i = 1;
	while (i < (size_t)ac)
	{
		if (!(added_model = batch_add(renderer->batch, av[i],
			ft_vec3f(0.0f, 0.0f, 50.0f), ft_vec3f(-PI, 0.0f, 0.0f))))
			return (!throw_error_str("error while adding to batch"));
		free(added_model->name);
		added_model->name = (ft_strrchr(av[i], '/'))
			? ft_strdup(ft_strrchr(av[i], '/') + 1)
			: ft_strdup(av[i]);
		i++;
	}
	instance_add_hook(instance, 1L << 0, 2, press_callback, instance);
	instance_add_hook(instance, 1L << 1, 3, release_callback, instance);
	instance_add_loop_callback(instance, loop_hook, instance);
	mlx_loop(instance->mlx);
}
