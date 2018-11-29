/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:28:24 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/29 19:18:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instance.h"
#include "mlx.h"
#include <stdlib.h>

t_instance	*new_instance(t_usize size, char *window_title)
{
	t_instance	*ret;

	if (!(ret = (t_instance*)malloc(sizeof(t_instance))))
		return (NULL);
	ft_bzero(ret, sizeof(t_instance));
	if (!(ret->mlx = mlx_init()))
		return (NULL);
	if (!(ret->window = mlx_new_window(ret->mlx, size.x, size.y, window_title)))
	{
		free(ret->mlx);
		free(ret);
		return (NULL);
	}
	mlx_key_hook(ret->window, key_callback_handler,
		&ret->key_callbacks);
	mlx_mouse_hook(ret->window, mouse_callback_handler,
		&ret->mouse_callbacks);
	mlx_expose_hook(ret->window, expose_callback_handler,
		&ret->expose_callbacks);
	mlx_loop_hook(ret->mlx, loop_callback_handler,
		&ret->loop_callbacks);
	return (ret);
}

void		instance_add_key_callback(t_instance *self, int (*callback)(),
	void *params)
{
	t_callback	new;

	new.callback = callback;
	new.params = params;
	ft_lstpushback(&self->key_callbacks,
		ft_lstnew(&new, sizeof(t_callback)));
}

void		instance_add_mouse_callback(t_instance *self, int (*callback)(),
	void *params)
{
	t_callback	new;

	new.callback = callback;
	new.params = params;
	ft_lstpushback(&self->mouse_callbacks,
		ft_lstnew(&new, sizeof(t_callback)));
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
	ft_lstpushback(&self->loop_callbacks,
		ft_lstnew(&new, sizeof(t_callback)));
}
