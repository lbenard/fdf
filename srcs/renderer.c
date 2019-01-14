/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:35:03 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/14 18:10:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "instance.h"
#include "errors.h"
#include <stdlib.h>
#include "model.h"
#include "draw.h"
#include "mlx.h"

/*
** Creates a new `t_renderer` instance.
** The rendering system is composed of 3 meshs: the original `raw_mesh` one,
** whose origin is specified in its position member, the `model_mesh` which
** represents the mesh after all transformations, and the `projection_mesh`
** which represents the final mesh projection onto the screen.
*/

t_renderer	*new_renderer(t_instance *instance)
{
	t_renderer	*ret;

	if (!instance)
		return (throw_error());
	if (!(ret = (t_renderer*)malloc(sizeof(t_renderer))))
		return (throw_error());
	ret->batch = NULL;
	ret->instance = instance;
	return (ret);
}

/*
** Makes pixels go colorful!
*/

void		render(t_renderer *self)
{
	t_list		*head;
	t_model		*cast;
	t_window	*window;

	head = self->batch;
	window = self->instance->window;
	clear(self->instance);
	ft_bzero(window->framebuffer, sizeof(int) * window->size.x
		* window->size.y);
	while (head)
	{
		cast = (t_model*)head->content;
		draw_mesh(self->instance, cast->model_mesh);
		head = head->next;
	}
	mlx_put_image_to_window(self->instance->mlx, window->handle, window->image,
		0, 0);
}
