/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:00:48 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/16 18:35:41 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H

# include "libft.h"
# include "mesh.h"
# include "batch.h"

typedef struct	s_batch t_batch;

typedef struct	s_model
{
	size_t		id;
	const char	*name;
	t_vec3f		position;
	t_vec3f		rotation;
	t_vec3f		scale;
	t_mesh		*raw_mesh;
	t_mesh		*model_mesh;
	t_mesh		*projection_mesh;
}				t_model;

t_model			*new_model(t_mesh *raw_mesh, t_vec3f position,
	t_vec3f rotation, t_vec3f scale);
void			update_model(t_model *self);
void			update_projection(t_model *self, t_mat4 projection_matrix);
t_model			*get_model_by_id(const t_batch *batch, size_t id);

#endif
