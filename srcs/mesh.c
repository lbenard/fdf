/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:20:46 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/08 19:19:14 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"
#include <stdlib.h>
#include "errors.h"

t_mesh	*new_mesh(t_mesh_type mesh_type, size_t vertices_count,
	size_t indices_count)
{
	t_mesh	*mesh;

	if (!(mesh = (t_mesh*)malloc(sizeof(t_mesh))))
		return (throw_error());
	mesh->mesh_type = mesh_type;
	mesh->vertices_count = vertices_count;
	if (!(mesh->vertices = (t_vec3f*)malloc(sizeof(t_vec3f) * vertices_count)))
	{
		free(mesh);
		return (throw_error());
	}
	mesh->indices_count = indices_count;
	if (!(mesh->indices = (t_vec2i*)malloc(sizeof(t_vec2i) * indices_count)))
	{
		free(mesh->vertices);
		free(mesh);
		return (throw_error());
	}
	mesh->position = ft_vec3f(0.0f, 0.0f, 0.0f);
	mesh->rotation = ft_vec3f(0.0f, 0.0f, 0.0f);
	mesh->scale = ft_vec3f(1.0f, 1.0f, 1.0f);
	return (mesh);
}

void	free_mesh(t_mesh **mesh)
{
	free((*mesh)->vertices);
	free((*mesh)->indices);
	free(*mesh);
	*mesh = NULL;
}

t_mesh	*new_mesh_copy(t_mesh *src)
{
	t_mesh	*ret;

	if (!(ret = (t_mesh*)malloc(sizeof(t_mesh))))
		return (throw_error());
	if (!(ret->vertices = (t_vec3f*)malloc(sizeof(t_vec3f)
		* src->vertices_count)) ||
		!(ret->indices = (t_vec2i*)malloc(sizeof(t_vec2i)
		* src->indices_count)))
		return (throw_error());
	ft_memcpy(ret->vertices, src->vertices,
		sizeof(t_vec3f) * src->vertices_count);
	ft_memcpy(ret->indices, src->indices,
		sizeof(t_vec2i) * src->indices_count);
	ret->mesh_type = src->mesh_type;
	ret->vertices_count = src->vertices_count;
	ret->indices_count = src->indices_count;
	ret->position = src->position;
	ret->rotation = src->rotation;
	ret->scale = src->scale;
	return (ret);
}
