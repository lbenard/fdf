/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:58:33 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/14 21:14:16 by lbenard          ###   ########.fr       */
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

#include <stdio.h>

int	loop_hook(void *params)
{
	t_instance		*instance;
	t_u8			*keys;
	static size_t	focused_model = 0;
	t_model			*model;

	instance = (t_instance*)params;
	keys = instance->window->keys;
	model = get_model_by_id(instance->renderer->batch, focused_model);
	if (keys[window_exit])
		exit(0);
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
	return (1);
}

int	main(int ac, const char **av)
{
	t_instance		*instance;
	t_renderer		*renderer;

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
	printf("a\n");
	renderer->batch = ft_lstnew(new_model(parse_map(av[1]),
		ft_vec3f(0.0f, 0.0f, 2.0f), ft_vec3f(1.5707963268f, 0.0f, 0.0f),
		ft_vec3f(1.0f, 1.0f, 1.0f)), sizeof(t_model));
	/*ft_lstpushback(&renderer->batch, ft_lstnew(new_model(parse_map("fdf.fdf"),
		ft_vec3f(0.0f, 0.0f, 0.0f), ft_vec3f(0.5f, -0.4f, 0.f),
		ft_vec3f(5.0f, 5.0f, 5.0f)), sizeof(t_model)));*/
	instance_add_hook(instance, 1L << 0, 2, control_press_callback, instance);
	instance_add_hook(instance, 1L << 1, 3, control_release_callback, instance);
	instance_add_loop_callback(instance, loop_hook, instance);
	/*update_model_mesh(renderer);
	update_projection_mesh(renderer);*/
	//render(renderer);
	mlx_loop(instance->mlx);
}
