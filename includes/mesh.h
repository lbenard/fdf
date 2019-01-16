/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:40:13 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/16 19:34:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include "libft.h"
# include "colors.h"

typedef struct	s_mesh
{
	size_t		vertices_count;
	t_vec3f		*vertices;
	t_color		*colors;
	size_t		indices_count;
	t_vec2i		*indices;
}				t_mesh;

t_mesh			*new_mesh(size_t vertices_count, size_t indices_count);
t_mesh			*new_mesh_copy(t_mesh *src);
void			free_mesh(t_mesh **mesh);

#endif
