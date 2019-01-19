/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:00:48 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/19 17:09:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H

# include "libft.h"
# include "mesh.h"
# include "camera.h"
# include "batch.h"

typedef struct s_batch	t_batch;

typedef struct	s_model
{
	size_t	id;
	char	*name;
	t_vec3f	position;
	t_vec3f	rotation;
	t_vec3f	scale;
	t_mesh	*raw_mesh;
	t_mesh	*model_mesh;
	t_mesh	*view_mesh;
	t_mesh	*projection_mesh;
}				t_model;

t_model			*new_model(t_mesh *raw_mesh, t_vec3f position,
	t_vec3f rotation, t_vec3f scale);
size_t			model_get_new_id(void);
void			model_update_model(t_model *self);
void			model_update_view(t_model *self, t_camera *camera);
void			model_update_projection(t_model *self,
	t_mat4 projection_matrix);
void			free_model(t_model *self);

#endif
