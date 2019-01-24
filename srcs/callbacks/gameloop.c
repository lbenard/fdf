/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:05:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/24 17:18:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"
#include "libft.h"
#include "controls.h"
#include "window.h"
#include "mlx.h"
#include "instance.h"
#include <stdlib.h>

static void	model_transform(t_model *model, t_u8 *keys)
{
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
}

static void	camera_transform(t_camera *camera, t_u8 *keys)
{
	camera_rotate(camera, ft_vec2f(
		-(0.04f * keys[camera_rotation_nx])
		+ (0.04f * keys[camera_rotation_px]),
		-(0.04f * keys[camera_rotation_ny])
		+ (0.04f * keys[camera_rotation_py])));
	camera_translate(camera, ft_vec3f(
		-(5.0f * keys[camera_translation_nx])
		+ (5.0f * keys[camera_translation_px]),
		-(5.0f * keys[camera_translation_ny])
		+ (5.0f * keys[camera_translation_py]),
		-(5.0f * keys[camera_translation_nz])
		+ (5.0f * keys[camera_translation_pz])));
	if (keys[switch_orthographic])
		camera->perspective = 0;
	else if (keys[switch_perspective])
		camera->perspective = 1;
}

static void	control_help(void *mlx, t_window *window)
{
	mlx_string_put(mlx, window->handle, 0, window->size.y - 20 * 8, 0xFFFFFF,
		"Controls:");
	mlx_string_put(mlx, window->handle, 0, window->size.y - 20 * 7, 0xFFFFFF,
		"Camera:     WASD");
	mlx_string_put(mlx, window->handle, 0, window->size.y - 20 * 6, 0xFFFFFF,
		"Model:      Rotation: 8456 (keypad)");
	mlx_string_put(mlx, window->handle, 0, window->size.y - 20 * 5, 0xFFFFFF,
		"            Position: Arrow keys / Home End");
	mlx_string_put(mlx, window->handle, 0, window->size.y - 20 * 4, 0xFFFFFF,
		"            Vertical size: Page down / Page up");
	mlx_string_put(mlx, window->handle, 0, window->size.y - 20 * 3, 0xFFFFFF,
		"            Size: + / - (keypad)");
	mlx_string_put(mlx, window->handle, 0, window->size.y - 20 * 2, 0xFFFFFF,
		"Projection: O (orthographic) / P (perspective)");
	mlx_string_put(mlx, window->handle, 0, window->size.y - 20 * 1, 0xFFFFFF,
		"Exit:       Escape");
}

static void	models(t_instance *instance, t_batch *batch, t_u8 *keys)
{
	static size_t	focused = 0;
	size_t			i;

	if (keys[model_previous] && focused != 0)
	{
		focused--;
		keys[model_previous] = 0;
	}
	if (keys[model_next] && focused + 1 < batch->size)
	{
		focused++;
		keys[model_next] = 0;
	}
	model_transform(batch_get_model_by_id(instance->renderer->batch,
		focused), keys);
	i = 0;
	while (batch_get_model_by_id(batch, i))
	{
		mlx_string_put(instance->mlx, instance->window->handle, 0, 20 * i + 10,
			0xFFFFFF, (i == focused) ? "> " : "  ");
		mlx_string_put(instance->mlx, instance->window->handle,
			20, 20 * i + 10, 0xFFFFFF,
			(char*)batch_get_model_by_id(batch, i)->name);
		i++;
	}
}

int			gameloop(t_instance *instance)
{
	t_u8	*keys;
	t_list	*model_list;

	keys = instance->window->keys;
	if (keys[window_exit])
	{
		free_instance(instance);
		exit(0);
	}
	camera_transform(instance->renderer->camera, keys);
	model_list = instance->renderer->batch->batch;
	while (model_list)
	{
		model_update_model((t_model*)model_list->content);
		model_update_view((t_model*)model_list->content,
			instance->renderer->camera);
		model_list = model_list->next;
	}
	renderer_render(instance->renderer);
	models(instance, instance->renderer->batch, keys);
	control_help(instance->mlx, instance->window);
	return (1);
}
