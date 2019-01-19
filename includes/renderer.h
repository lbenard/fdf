/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:38:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/19 18:52:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "instance.h"
# include "colors.h"
# include "camera.h"
# include "batch.h"

typedef struct s_instance	t_instance;

typedef struct	s_renderer
{
	t_instance	*instance;
	t_color		clear;
	t_camera	*camera;
	t_batch		*batch;
}				t_renderer;

t_renderer		*new_renderer(t_instance *instance);
void			renderer_render(t_renderer *self, int perspective);
void			free_renderer(t_renderer *self);

#endif
