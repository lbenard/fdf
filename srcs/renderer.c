/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:35:03 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/19 19:35:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "instance.h"
#include "errors.h"
#include <stdlib.h>
#include "batch.h"
#include "colors.h"
#include "libft.h"
#include "model.h"
#include "window.h"
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
		return (throw_error_str("error while creating renderer, "
			"no instance provided"));
	if (!(ret = (t_renderer*)malloc(sizeof(t_renderer))))
		return (throw_error());
	if (!(ret->batch = new_batch()))
	{
		free(ret);
		return (throw_error_str("error while creating batch"));
	}
	if (!(ret->camera = new_camera()))
	{
		free(ret->batch);
		free(ret);
		return (throw_error_str("error while creating camera"));
	}
	ret->clear = ft_color(0.2f, 0.0f, 0.0f);
	ret->instance = instance;
	return (ret);
}

static void	clear_buffer(int *framebuffer, t_color color, size_t size)
{
	size_t	i;
	int		color_cast;

	i = 0;
	color_cast = color_to_int(color);
	while (i < size)
		framebuffer[i++] = color_cast;
}

/*
** Makes pixels go colorful!
*/

void		renderer_render(t_renderer *self)
{
	t_list		*head;
	t_model		*cast;
	t_window	*window;

	head = self->batch->batch;
	window = self->instance->window;
	clear(self->instance);
	clear_buffer(window->framebuffer, self->clear, window->size.x
		* window->size.y);
	while (head)
	{
		cast = (t_model*)head->content;
		draw_mesh(self->instance, cast->projection_mesh);
		head = head->next;
	}
	mlx_put_image_to_window(self->instance->mlx, window->handle, window->image,
		0, 0);
}

void		free_renderer(t_renderer *self)
{
	free_camera(self->camera);
	free_batch(self->batch);
	free(self);
}
