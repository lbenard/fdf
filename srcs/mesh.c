/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:20:46 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/17 01:10:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"
#include <stdlib.h>
#include "errors.h"
#include <stdio.h>

t_mesh	*new_mesh(size_t vertices_count, size_t indices_count)
{
	t_mesh	*mesh;

	printf("new mesh\n");
	if (!(mesh = (t_mesh*)malloc(sizeof(t_mesh))))
		return (throw_error());
	mesh->vertices_count = vertices_count;
	(void)mesh->vertices;
	printf("malloc done (%lu %lu incoming)\n", vertices_count, indices_count);
	if (!(mesh->vertices = (t_vec3f*)malloc(sizeof(t_vec3f) * vertices_count)))
	{
		free(mesh);
		return (throw_error());
	}
	printf("malloc vertices\n");
	if (!(mesh->colors = (t_color*)malloc(sizeof(t_color) * vertices_count)))
	{
		free(mesh->vertices);
		free(mesh);
		return (throw_error());
	}
	printf("malloc colors\n");
	mesh->indices_count = indices_count;
	if (!(mesh->indices = (t_vec2i*)malloc(sizeof(t_vec2i) * indices_count)))
	{
		free(mesh->vertices);
		free(mesh);
		return (throw_error());
	}
	printf("malloc indices\n");
	return (mesh);
}

void	free_mesh(t_mesh **mesh)
{
	free((*mesh)->vertices);
	free((*mesh)->colors);
	free((*mesh)->indices);
	free(*mesh);
	*mesh = NULL;
}


t_mesh	*new_mesh_copy(t_mesh *src)
{
	t_mesh	*ret;

	printf("start mesh copy\n");
	if (!(ret = new_mesh(src->vertices_count, src->indices_count)))
		return (throw_error());
	printf("new mesh done\n");
	ft_memcpy(ret->vertices, src->vertices,
		sizeof(t_vec3f) * src->vertices_count);
	ft_memcpy(ret->colors, src->colors,
		sizeof(t_color) * src->vertices_count);
	ft_memcpy(ret->indices, src->indices,
		sizeof(t_vec2i) * src->indices_count);
	ret->vertices_count = src->vertices_count;
	ret->indices_count = src->indices_count;
	return (ret);
}
