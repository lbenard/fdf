/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance_callbacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:42:01 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/23 15:44:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instance.h"
#include "mlx.h"

void		instance_add_key_callback(t_instance *self, int (*callback)(),
	void *params)
{
	t_callback	new;

	new.callback = callback;
	new.instance = self;
	new.params = params;
	ft_lstpushback(&self->key_callbacks,
		ft_lstnewcpy(&new, sizeof(t_callback)));
}

void		instance_add_mouse_callback(t_instance *self, int (*callback)(),
	void *params)
{
	t_callback	new;

	new.callback = callback;
	new.instance = self;
	new.params = params;
	ft_lstpushback(&self->mouse_callbacks,
		ft_lstnewcpy(&new, sizeof(t_callback)));
}

void		instance_add_expose_callback(t_instance *self, int (*callback)(),
	void *params)
{
	t_callback	new;

	new.callback = callback;
	new.instance = self;
	new.params = params;
	ft_lstpushback(&self->expose_callbacks,
		ft_lstnewcpy(&new, sizeof(t_callback)));
}

void		instance_add_loop_callback(t_instance *self, int (*callback)(),
	void *params)
{
	t_callback	new;

	new.callback = callback;
	new.instance = self;
	new.params = params;
	ft_lstpushback(&self->loop_callbacks, ft_lstnewcpy(&new,
		sizeof(t_callback)));
}

void		instance_add_hook(t_instance *self, int name,
	int (*callback)(), void *params)
{
	if (name == 2)
		mlx_hook(self->window->handle, name, 1L << 0, callback, params);
	if (name == 3)
		mlx_hook(self->window->handle, name, 1L << 1, callback, params);
}
