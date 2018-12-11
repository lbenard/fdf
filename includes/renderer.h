/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:38:12 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/11 15:15:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "mesh.h"
# include "camera.h"
# include "instance.h"

typedef struct	s_renderer
{
	t_mesh		*raw_mesh;
	t_mesh		*model_mesh;
	t_mesh		*projection_mesh;
	t_instance	*instance;
}				t_renderer;

t_renderer		*new_renderer(t_instance *instance, t_mesh *mesh,
	t_vec3f origin);
void			init_raw_mesh(t_renderer *self);
void			update_model_mesh(t_renderer *self);
void			update_projection_mesh(t_renderer *self);
void			render(t_renderer *self);

#endif
