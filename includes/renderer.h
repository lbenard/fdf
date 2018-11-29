/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:38:12 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/29 23:58:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "mesh.h"
# include "camera.h"

typedef struct	s_renderer
{
	t_mesh		*raw_mesh;
	t_mesh		*model_mesh;
	t_mesh		*view_mesh;
	t_mesh		*projection_mesh;
	float		vertical_factor;
	t_camera	camera;
}				t_renderer;

t_renderer		*new_renderer(t_mesh *mesh, t_camera camera);
void			update_model_matrix(void);
void			update_view_matrix(void);
void			update_projection_matrix(void);

#endif
