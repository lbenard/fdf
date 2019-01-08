/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:38:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/08 17:03:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "mesh.h"
# include "instance.h"

typedef struct s_instance t_instance;

typedef struct	s_renderer
{
	t_instance	*instance;
	t_list		*batch;
}				t_renderer;

t_renderer		*new_renderer(t_instance *instance);
void			init_raw_mesh(t_renderer *self);
void			update_model_mesh(t_renderer *self);
void			update_projection_mesh(t_renderer *self);
void			render(t_renderer *self);

#endif
