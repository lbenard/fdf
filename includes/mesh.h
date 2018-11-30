/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:40:13 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/30 16:59:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include "libft.h"

typedef struct	s_face
{
	t_vec3f	v0;
	t_vec3f	v1;
	t_vec3f	v2;
}				t_face;

typedef struct	s_mesh
{
	size_t	mesh_size;
	t_face	*mesh;
}				t_mesh;

t_mesh	new_mesh(char *mesh_path);
t_mesh	new_mesh_copy(t_mesh src);

#endif
