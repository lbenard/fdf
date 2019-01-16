/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:22:47 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/16 19:39:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"
#include <stdlib.h>
#include "libft.h"
#include "errors.h"

static size_t	get_new_id(void)
{
	static size_t	i = 0;

	return (i++);
}

t_model			*new_model(t_mesh *raw_mesh, t_vec3f position,
	t_vec3f rotation, t_vec3f scale)
{
	t_model	*ret;

	if (!(ret = (t_model*)malloc(sizeof(t_model))))
		return (throw_error());
	ft_bzero(ret, sizeof(t_model));
	ret->raw_mesh = raw_mesh;
	if (!(ret->model_mesh = new_mesh_copy(raw_mesh)))
	{
		free(ret->raw_mesh);
		free(ret);
		return (throw_error());
	}
	if (!(ret->projection_mesh = new_mesh_copy(raw_mesh)))
	{
		free(ret->raw_mesh);
		free(ret->model_mesh);
		free(ret);
		return (throw_error());
	}
	ret->name = "Unnamed model";
	ret->id = get_new_id();
	ret->position = position;
	ret->rotation = rotation;
	ret->scale = scale;
	return (ret);
}

void			update_model(t_model *self)
{
	size_t	i;
	t_mat4	model_matrix;

	i = 0;
	if (!self->model_mesh)
		if (!(self->model_mesh = new_mesh_copy(self->raw_mesh)))
			return ;
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

void			update_projection(t_model *self, t_mat4 projection_matrix)
{
	size_t	i;

	i = 0;
	if (!self->projection_mesh)
		if (!(self->projection_mesh = new_mesh_copy(self->model_mesh)))
			return ;
	while (i < self->projection_mesh->vertices_count)
	{
		self->projection_mesh->vertices[i] =
			ft_vec4f_to_vec3f(ft_mat4_x_vec4(projection_matrix,
			ft_vec3f_to_vec4f(self->model_mesh->vertices[i])));
		i++;
	}
}

t_model			*get_model_by_id(const t_batch *batch, size_t id)
{
	t_list	*head;
	t_model	*cast;

	if (!batch)
		return (NULL);
	head = batch->batch;
	while (head)
	{
		cast = (t_model*)head->content;
		if (cast->id == id)
			return (cast);
		head = head->next;
	}
	return (NULL);
}
