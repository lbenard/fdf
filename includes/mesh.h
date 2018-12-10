/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:40:13 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/08 19:18:30 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include "libft.h"

typedef enum	e_mesh_type
{
	NONE		=	0x00,
	SEGMENTS	=	0x01,
	TRIANGLES	=	0x02,
	SQUARE		=	0x03
}				t_mesh_type;

typedef struct	s_mesh
{
	t_vec3f		position;
	t_vec3f		rotation;
	t_vec3f		scale;
	t_mesh_type	mesh_type;
	size_t		vertices_count;
	t_vec3f		*vertices;
	size_t		indices_count;
	t_vec2i		*indices;
}				t_mesh;

t_mesh	*new_mesh(t_mesh_type mesh_type, size_t vertices_count,
	size_t indices_count);
t_mesh	*new_mesh_copy(t_mesh *src);
void	free_mesh(t_mesh **mesh);

#endif
