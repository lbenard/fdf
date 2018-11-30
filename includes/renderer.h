/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:38:12 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/30 17:07:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "mesh.h"
# include "camera.h"
# include "instance.h"

typedef struct	s_renderer
{
	t_mesh		raw_mesh;
	t_mesh		model_mesh;
	t_mesh		view_mesh;
	t_mesh		projection_mesh;
	float		vertical_factor;
	t_camera	camera;
	t_instance	*instance;
}				t_renderer;

t_renderer		*new_renderer(t_instance *instance, t_mesh mesh,
	t_camera camera);
void			update_model_mesh(t_renderer *self);
void			update_view_mesh(t_renderer *self);
void			update_projection_mesh(t_renderer *self);
void			render(t_renderer *self);

#endif
