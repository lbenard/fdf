/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:35:03 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/03 03:42:07 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include <stdlib.h>
#include "libft.h"

t_renderer	*new_renderer(t_instance *instance, t_mesh mesh, t_camera camera)
{
	t_renderer	*ret;

	if (!(ret = (t_renderer*)malloc(sizeof(t_renderer))))
		return (NULL);
	if (!(ret->raw_mesh = new_mesh_copy(mesh)).mesh ||
		!(ret->model_mesh = new_mesh_copy(mesh)).mesh ||
		!(ret->view_mesh = new_mesh_copy(mesh)).mesh ||
		!(ret->projection_mesh = new_mesh_copy(mesh)).mesh)
		return (NULL);
	ret->vertical_factor = 1.0f;
	ret->camera = camera;
	ret->instance = instance;
	update_model_mesh(ret);
	update_view_mesh(ret);
	//update_projection_mesh(ret);
	return (ret);
}

void			update_model_mesh(t_renderer *self)
{
	size_t	i;
	t_mat4	model_matrix;

	i = 0;
	model_matrix = ft_mat4_scaling(ft_vec3f(1.0f, self->vertical_factor, 1.0f));
	model_matrix = ft_mat4_x_mat4(ft_mat4_rotation(ft_vec3f(0.0f, 0.0f, 0.7853981634f)), model_matrix);
	model_matrix = ft_mat4_x_mat4(ft_mat4_translation(ft_vec3f(100.0f, 100.0f, 100.0f)), model_matrix);
	//ft_print_mat4(&model_matrix);
	while (i < self->raw_mesh.mesh_size)
	{
		self->model_mesh.mesh[i].v0 =
			ft_vec4f_to_vec3f(ft_mat4_x_vec4(model_matrix,
			ft_vec3f_to_vec4f(self->raw_mesh.mesh[i].v0)));
		self->model_mesh.mesh[i].v1 =
			ft_vec4f_to_vec3f(ft_mat4_x_vec4(model_matrix,
			ft_vec3f_to_vec4f(self->raw_mesh.mesh[i].v1)));
		self->model_mesh.mesh[i].v2 =
			ft_vec4f_to_vec3f(ft_mat4_x_vec4(model_matrix,
			ft_vec3f_to_vec4f(self->raw_mesh.mesh[i].v2)));
		i++;
	}
}

#include <stdio.h>

void			update_view_mesh(t_renderer *self)
{
	size_t	i;
	t_mat4	view_matrix;

	i = 0;
	view_matrix = ft_mat4_view(self->camera.position, self->camera.rotation);
	printf("camera: pos: x %f\ty %f\n        rot: x %f\t\ty %f\n", self->camera.position.x, self->camera.position.y, self->camera.rotation.x, self->camera.rotation.y);
	ft_print_mat4(&view_matrix);
	while (i < self->model_mesh.mesh_size)
	{
		self->view_mesh.mesh[i].v0 =
			ft_vec4f_to_vec3f(ft_mat4_x_vec4(view_matrix,
			ft_vec3f_to_vec4f(self->model_mesh.mesh[i].v0)));
		self->view_mesh.mesh[i].v1 =
			ft_vec4f_to_vec3f(ft_mat4_x_vec4(view_matrix,
			ft_vec3f_to_vec4f(self->model_mesh.mesh[i].v1)));
		self->view_mesh.mesh[i].v2 =
			ft_vec4f_to_vec3f(ft_mat4_x_vec4(view_matrix,
			ft_vec3f_to_vec4f(self->model_mesh.mesh[i].v2)));
		i++;
	}
}

void			update_projection_mesh(t_renderer *self)
{
	(void)self;
}

void			render(t_renderer *self)
{
	(void)self;
}
