/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:20:46 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/30 06:19:14 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"
#include <stdlib.h>

t_mesh	new_mesh(char *mesh_path)
{
	t_mesh	ret;

	(void)mesh_path;
	if (!(ret.mesh = (t_face*)malloc(sizeof(t_face) * 3)))
		return (ret);
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
}
