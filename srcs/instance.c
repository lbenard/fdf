/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:28:24 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/29 15:28:53 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instance.h"
#include "mlx.h"
#include <stdlib.h>

t_instance	*new_instance(t_usize size, char *window_title)
{
	t_instance	*instance;

	if (!(instance = (t_instance*)malloc(sizeof(t_instance))))
		return (NULL);
	if (!(instance->mlx = mlx_init()))
	{
		free(instance);
		return (NULL);
	}
	if (!(instance->window = mlx_new_window(instance->mlx, size.x, size.y,
		window_title)))
	{
		free(instance->mlx);
		free(instance);
		return (NULL);
	}
	mlx_key_hook(instance->window, key_callback_handler,
		instance->key_callbacks);
	mlx_mouse_hook(instance->window, mouse_callback_handler,
		instance->mouse_callbacks);
	mlx_expose_hook(instance->window, expose_callback_handler,
		instance->expose_callbacks);
	mlx_loop_hook(instance->window, loop_callback_handler,
		instance->loop_callbacks);
	return (instance);
}

#include <stdio.h>

void		instance_add_key_callback(t_instance *self, int (*callback)(),
	void *params)
{
	t_callback	new;

	new.callback = callback;
	new.params = params;
	ft_lstpushback(&self->key_callbacks, ft_lstnew(&new, sizeof(t_callback)));
}

void		instance_add_mouse_callback(t_instance *self, int (*callback)(),
	void *params)
{
	t_callback	new;

	new.callback = callback;
	new.params = params;
	ft_lstpushback(&self->mouse_callbacks, ft_lstnew(&new, sizeof(t_callback)));
	printf("added new callback\n");
}

void		instance_add_expose_callback(t_instance *self, int (*callback)(),
	void *params)
{
	t_callback	new;

	new.callback = callback;
	new.params = params;
	ft_lstpushback(&self->expose_callbacks,
		ft_lstnew(&new, sizeof(t_callback)));
}
void		instance_add_loop_callback(t_instance *self, int (*callback)(),
	void *params)
{
	t_callback	new;

	new.callback = callback;
	new.params = params;
	ft_lstpushback(&self->loop_callbacks, ft_lstnew(&new, sizeof(t_callback)));
}
