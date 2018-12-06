/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:20:46 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/06 19:04:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"
#include <stdlib.h>

t_mesh	*new_mesh(t_mesh_type mesh_type, size_t vertices_count,
	size_t indices_count)
{
	t_mesh	*mesh;

	if (!(mesh = (t_mesh*)malloc(sizeof(t_mesh))))
		return (NULL);
	mesh->mesh_type = mesh_type;
	mesh->vertices_count = vertices_count;
	if (!(mesh->vertices = (t_vec3f*)malloc(sizeof(t_vec3f) * vertices_count)))
	{
		free(mesh);
		return (NULL);
	}
	mesh->indices_count = indices_count;
	if (!(mesh->indices = (size_t*)malloc(sizeof(size_t) * indices_count)))
	{
		free(mesh->vertices);
		free(mesh);
		return (NULL);
	}
	return (mesh);
}

void	free_mesh(t_mesh **mesh)
{
	free((*mesh)->vertices);
	free((*mesh)->indices);
	free(*mesh);
	*mesh = NULL;
}

/*t_mesh	*new_mesh(char *mesh_path)
{
	t_mesh	*ret;

	(void)mesh_path;
	if (!(ret = (t_mesh*)malloc(sizeof(t_mesh))))
		return (NULL);
	if (!(ret->mesh = (t_face*)malloc(sizeof(t_face) * 3)))
		return (NULL);
	ret.mesh[0].v0 = ft_vec3f(  0.0f,   0.0f, 0.0f);
	ret.mesh[0].v1 = ft_vec3f(100.0f,   0.0f, 0.0f);
	ret.mesh[0].v2 = ft_vec3f(  0.0f, 100.0f, 0.0f);
	ret.mesh[1].v0 = ft_vec3f(100.0f, 100.0f, 0.0f);
	ret.mesh[1].v1 = ft_vec3f(100.0f,   0.0f, 0.0f);
	ret.mesh[1].v2 = ft_vec3f(  0.0f, 100.0f, 0.0f);
	ret.mesh_size = 2;
	return (ret);
}

t_mesh	new_mesh_copy(t_mesh src)
{
	t_mesh	ret;

	if (!(ret.mesh = (t_face*)malloc(sizeof(t_face) * src.mesh_size)))
		return (ret);
	ret.mesh_size = src.mesh_size;
	ft_memcpy(ret.mesh, src.mesh, sizeof(t_face) * src.mesh_size);
	return (ret);
}*/
