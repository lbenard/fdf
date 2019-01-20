/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:22:47 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/20 18:07:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"
#include <stdlib.h>
#include "libft.h"
#include "errors.h"

t_model			*new_model(t_mesh *raw_mesh, t_vec3f position,
	t_vec3f rotation, t_vec3f scale)
{
	t_model	*ret;

	if (!(ret = (t_model*)malloc(sizeof(t_model))))
		return (throw_error());
	ret->raw_mesh = raw_mesh;
	if (!(ret->model_mesh = new_mesh_copy(raw_mesh)))
	{
		free(ret->raw_mesh);
		free(ret);
		return (throw_error());
	}
	if (!(ret->view_mesh = new_mesh_copy(raw_mesh)))
	{
		free(ret->model_mesh);
		free(ret->raw_mesh);
		free(ret);
		return (throw_error());
	}
	ret->id = model_get_new_id();
	ret->name = ft_strdup("Unnamed model");
	ret->position = position;
	ret->rotation = rotation;
	ret->scale = scale;
	model_update_model(ret);
	return (ret);
}

void			model_update_model(t_model *self)
{
	size_t	i;
	t_mat4	model_matrix;

	i = 0;
	model_matrix = ft_mat4_scaling(self->scale);
	model_matrix = ft_mat4_x_mat4(ft_mat4_rotation(self->rotation),
		model_matrix);
	model_matrix = ft_mat4_x_mat4(ft_mat4_translation(self->position),
		model_matrix);
	while (i < self->model_mesh->vertices_count)
	{
		self->model_mesh->vertices[i] =
			ft_vec4f_to_vec3f(ft_mat4_x_vec4(model_matrix,
			ft_vec3f_to_vec4f(self->raw_mesh->vertices[i])));
		i++;
	}
}

void			model_update_view(t_model *self, t_camera *camera)
{
	size_t	i;
	t_mat4	view_matrix;

	i = 0;
	view_matrix = ft_mat4_translation(ft_vec3f(-camera->position.x,
		-camera->position.y, -camera->position.z));
	view_matrix = ft_mat4_x_mat4(ft_mat4_rotation(ft_vec3f(-camera->rotation.x,
		-camera->rotation.y, 0)), view_matrix);
	while (i < self->view_mesh->vertices_count)
	{
		self->view_mesh->vertices[i] =
			ft_vec4f_to_vec3f(ft_mat4_x_vec4(view_matrix,
			ft_vec3f_to_vec4f(self->model_mesh->vertices[i])));
		i++;
	}
}

void			free_model(t_model *self)
{
	free(self->name);
	free_mesh(self->raw_mesh);
	free_mesh(self->model_mesh);
	free_mesh(self->view_mesh);
	free(self);
}
