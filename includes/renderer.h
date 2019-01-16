/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:38:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/16 19:22:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "mesh.h"
# include "instance.h"
# include "batch.h"

typedef struct s_instance t_instance;

typedef struct	s_renderer
{
	t_instance	*instance;
	t_color		clear;
	t_batch		*batch;
}				t_renderer;

t_renderer		*new_renderer(t_instance *instance);
void			render(t_renderer *self);
void			free_renderer(void);

#endif
