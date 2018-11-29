/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:20:46 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/29 22:43:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

t_mesh	*new_mesh(char *mesh_path)
{
	t_mesh	*ret;

	if (!(ret = (t_mesh*)malloc(sizeof(t_mesh))))
		return (NULL);
	if (!(ret->mesh = (t_face*)malloc(sizeof(t_mesh) * 3)))
		return (NULL);
	ret->mesh[0].v0 = ft_vec3f(0, 0, 0);
	ret->mesh[0].v1 = ft_vec3f(1, 0, 0);
	ret->mesh[0].v2 = ft_vec3f(0, 0, 1);
	ret->mesh[1].v0 = ft_vec3f(1, 0, 1);
	ret->mesh[1].v1 = ft_vec3f(1, 0, 0);
	ret->mesh[1].v2 = ft_vec3f(0, 0, 1);
	ret->mesh_size = 2;
	return (ret);
}
