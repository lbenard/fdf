/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:28:24 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/11 15:05:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instance.h"
#include "mlx.h"
#include <stdlib.h>
#include "errors.h"

static void	add_hooks(t_instance *instance)
{
	mlx_key_hook(instance->window->handle, key_callback_handler,
		&instance->key_callbacks);
	mlx_mouse_hook(instance->window->handle, mouse_callback_handler,
		&instance->mouse_callbacks);
	mlx_expose_hook(instance->window->handle, expose_callback_handler,
		&instance->expose_callbacks);
	mlx_loop_hook(instance->mlx, loop_callback_handler,
		&instance->loop_callbacks);
}

#include <stdio.h>
#include <errno.h>

t_instance	*new_instance(t_usize size, char *window_title)
{
	t_instance	*ret;

	if (!(ret = (t_instance*)malloc(sizeof(t_instance))))
		return (throw_error());
	ft_bzero(ret, sizeof(t_instance));
	if (!(ret->mlx = mlx_init()))
	{
		free(ret);
		return (throw_error());
	}
	if (!(ret->window = (t_window*)malloc(sizeof(t_window))))
	{
		free(ret->mlx);
		free(ret);
		return (throw_error());
	}
	if (!(ret->window->handle = mlx_new_window(ret->mlx, size.x, size.y,
		window_title)))
	{
		free(ret->mlx);
		free(ret->window);
		free(ret);
		return (throw_error());
	}
	errno = 0;
	ret->window->size = size;
	ret->window->title = window_title;
	add_hooks(ret);
	return (ret);
}

void		instance_add_key_callback(t_instance *self, int (*callback)(),
	void *params)
{
	t_callback	new;

	new.callback = callback;
	new.instance = self;
	new.params = params;
	ft_lstpushback(&self->key_callbacks,
		ft_lstnew(&new, sizeof(t_callback)));
}

void		instance_add_mouse_callback(t_instance *self, int (*callback)(),
	void *params)
{
	t_callback	new;

	new.callback = callback;
	new.instance = self;
	new.params = params;
	ft_lstpushback(&self->mouse_callbacks,
		ft_lstnew(&new, sizeof(t_callback)));
}

void		instance_add_expose_callback(t_instance *self, int (*callback)(),
	void *params)
{
	t_callback	new;

	new.callback = callback;
	new.instance = self;
	new.params = params;
	ft_lstpushback(&self->expose_callbacks,
		ft_lstnew(&new, sizeof(t_callback)));
}
void		instance_add_loop_callback(t_instance *self, int (*callback)(),
	void *params)
{
	t_callback	new;

	new.callback = callback;
	new.instance = self;
	new.params = params;
	ft_lstpushback(&self->loop_callbacks,
		ft_lstnew(&new, sizeof(t_callback)));
}
