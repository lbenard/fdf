/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:35:03 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/29 22:49:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "renderer.h"

t_renderer	*new_renderer(t_mesh *mesh, t_camera camera)
{
	t_renderer	*ret;

	if (!(ret = (t_renderer*)malloc(sizeof(t_renderer))))
		return (NULL);
	if (!(ret->model_mesh = (t_mesh*)ft_memcpy(ret->model_mesh, mesh,
		mesh->mesh_size)))
		return (NULL);
}

