/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:35:03 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/10 02:51:09 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "draw.h"
#include "mesh.h"
#include <stdlib.h>
#include "libft.h"
#include "errors.h"

/*
** Creates a new `t_renderer` instance.
** The rendering system is composed of 3 meshs: the original `raw_mesh` one,
** whose origin is specified in its position member, the `model_mesh` which
** represents the mesh after all transformations, and the `projection_mesh`
** which represents the final mesh projection onto the screen.
*/

t_renderer	*new_renderer(t_instance *instance, t_mesh *mesh)
{
	t_renderer	*ret;

	if (!instance || !mesh)
		return (throw_error());
	if (!(ret = (t_renderer*)malloc(sizeof(t_renderer))))
		return (throw_error());
	if (!(ret->raw_mesh = new_mesh_copy(mesh)) ||
		!(ret->model_mesh = new_mesh_copy(mesh)) ||
		!(ret->projection_mesh = new_mesh_copy(mesh)))
		return (throw_error());
	ret->instance = instance;
	init_raw_mesh(ret);
	update_model_mesh(ret);
	update_projection_mesh(ret);
	return (ret);
}

/*
** Initialize the `raw_mesh` by shifting it to its origin point.
*/

void			init_raw_mesh(t_renderer *self)
{
	size_t	i;
	t_mat4	raw_matrix;

	i = 0;
	raw_matrix = ft_mat4_scaling(self->raw_mesh->scale);
	raw_matrix = ft_mat4_x_mat4(ft_mat4_rotation(self->raw_mesh->rotation),
		raw_matrix);
	raw_matrix = ft_mat4_x_mat4(ft_mat4_translation(self->raw_mesh->position),
		raw_matrix);
	while (i < self->raw_mesh->vertices_count)
	{
		self->raw_mesh->vertices[i] =
			ft_vec4f_to_vec3f(ft_mat4_x_vec4(raw_matrix,
			ft_vec3f_to_vec4f(self->raw_mesh->vertices[i])));
		i++;
	}
}

/*
** Updates the `model_mesh` by computing every applied transformation. This is
** the only transformation process that should used by the user wanting to
** regularly apply transformations to a mesh.
*/

void			update_model_mesh(t_renderer *self)
{
	size_t	i;
	t_mat4	model_matrix;

	i = 0;
	model_matrix = ft_mat4_scaling(self->model_mesh->scale);
	model_matrix = ft_mat4_x_mat4(ft_mat4_rotation(self->model_mesh->rotation),
		model_matrix);
	model_matrix = ft_mat4_x_mat4(ft_mat4_translation(self->model_mesh->position),
		model_matrix);
	while (i < self->model_mesh->vertices_count)
	{
		self->model_mesh->vertices[i] =
			ft_vec4f_to_vec3f(ft_mat4_x_vec4(model_matrix,
			ft_vec3f_to_vec4f(self->raw_mesh->vertices[i])));
		i++;
	}
}

/*
** Updates the projection mesh. The projection matrix is specified when
** creating the renderer instance and can be modified by accessing the
** `projection_matrix` member.
*/

void			update_projection_mesh(t_renderer *self)
{
	(void)self;
	/*size_t			i;
	t_projection	projection_matrix;

	i = 0;
	projection_matrix = self->camera->projection;
	while (i < self->model_mesh->vertices_count)
	{
		self->projection_mesh->vertices[i] =
			ft_vec4f_to_vec3f(ft_mat4_x_vec4(projection_matrix.projection,
			ft_vec3f_to_vec4f(self->model_mesh->vertices[i])));
		i++;
	}*/
}

/*
** Makes pixels go colorful!
*/

void			render(t_renderer *self)
{
	clear(self->instance);
	draw_mesh(self->instance, self->model_mesh);
}
