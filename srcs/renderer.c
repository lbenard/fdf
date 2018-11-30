/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:35:03 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/30 18:08:54 by lbenard          ###   ########.fr       */
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
	ret->vertical_factor = 2.0f;
	ret->camera = camera;
	ret->instance = instance;
	update_model_mesh(ret);
	update_view_mesh(ret);
	update_projection_mesh(ret);
	return (ret);
}

#include <stdio.h>

void			update_model_mesh(t_renderer *self)
{
	size_t	i;
	t_mat4	model_matrix;

	i = 0;
	model_matrix = ft_mat4_scale(ft_vec3f(1.0f, self->vertical_factor, 1.0f));
	ft_print_mat4(&model_matrix);
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

void			update_view_mesh(t_renderer *self)
{
	(void)self;
}

void			update_projection_mesh(t_renderer *self)
{
	(void)self;
}

void			render(t_renderer *self)
{
	(void)self;
}
