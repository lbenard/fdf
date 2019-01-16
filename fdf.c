/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:58:33 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/16 18:26:58 by lbenard          ###   ########.fr       */
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

int	loop_hook(void *params)
{
	t_instance		*instance;
	t_u8			*keys;
	static size_t	focused_model = 0;
	size_t			i;
	t_model			*model;

	instance = (t_instance*)params;
	keys = instance->window->keys;
	if (keys[window_exit])
		exit(0);
	if (keys[model_next] && focused_model < 1)
		focused_model++;
	if (keys[model_previous] && focused_model != 0)
		focused_model--;
	model = get_model_by_id(instance->renderer->batch, focused_model);
	model->position.x -= 5.0f * keys[translation_nx];
	model->position.x += 5.0f * keys[translation_px];
	model->position.y -= 5.0f * keys[translation_ny];
	model->position.y += 5.0f * keys[translation_py];
	model->position.z -= 5.0f * keys[translation_nz];
	model->position.z += 5.0f * keys[translation_pz];
	model->rotation.x -= 0.02f * keys[rotation_nx];
	model->rotation.x += 0.02f * keys[rotation_px];
	model->rotation.y -= 0.02f * keys[rotation_ny];
	model->rotation.y += 0.02f * keys[rotation_py];
	model->scale = ft_vec3f_scalar(model->scale, 1.0f + .1f * keys[scale_zoom]);
	model->scale = ft_vec3f_scalar(model->scale, 1.0f / (1.0f + .1f *
		keys[scale_dezoom]));
	model->scale.y *= 1.0f + (0.1f * keys[scale_stretch]);
	model->scale.y /= 1.0f + (0.1f * keys[scale_flatten]);
	update_model(model);
	//update_projection_mesh(renderer);
	render(instance->renderer);
	i = 0;
	while (get_model_by_id(instance->renderer->batch, i))
	{
		if (i == focused_model)
			mlx_string_put(instance->mlx, instance->window->handle, 0, 20 * i,
				0xFFFFFF, "> ");
		else
			mlx_string_put(instance->mlx, instance->window->handle, 0, 20 * i,
				0xFFFFFF, "  ");
		mlx_string_put(instance->mlx, instance->window->handle,
			20, 20 * i, 0xFFFFFF,
			(char*)get_model_by_id(instance->renderer->batch, i)->name);
		i++;
	}
	usleep(1.0 / 120.0 * 1000000);
	return (1);
}

#include "batch.h"

int	main(int ac, const char **av)
{
	t_instance		*instance;
	t_renderer		*renderer;

	(void)ac;
	if (ac != 2)
		return (!throw_error_str("Missing file operand"));
	if (!(instance = new_instance(ft_usize(1600, 900), "fdf")))
		return (!throw_error());
	if (!(renderer = new_renderer(instance)))
	{
		free(instance);
		return (!throw_error());
	}
	instance->renderer = renderer;
	batch_add(renderer->batch, av[1], ft_vec3f(0.0f, 0.0f, 2.0f),
		ft_vec3f(1.5707963268f, 0.0f, 0.0f));
	/*renderer->batch = ft_lstnew(new_model(parse_fdf(av[1]), // todo: fix error
		ft_vec3f(0.0f, 0.0f, 2.0f), ft_vec3f(1.5707963268f, 0.0f, 0.0f),
		ft_vec3f(1.0f, 1.0f, 1.0f)), sizeof(t_model));*/
	//parse_ply("maps/ply/white_cube.ply");
	/*ft_lstpushback(&renderer->batch, ft_lstnew(new_model(parse_fdf(av[2]),
		ft_vec3f(0.0f, 0.0f, 2.0f), ft_vec3f(1.5707963268f, 0.0f, 0.0f),
		ft_vec3f(1.0f, 1.0f, 1.0f)), sizeof(t_model)));*/
	instance_add_hook(instance, 1L << 0, 2, control_press_callback, instance);
	instance_add_hook(instance, 1L << 1, 3, control_release_callback, instance);
	instance_add_loop_callback(instance, loop_hook, instance);
	/*update_model_mesh(renderer);
	update_projection_mesh(renderer);*/
	//render(renderer);
	mlx_loop(instance->mlx);
}
