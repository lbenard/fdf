/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:28:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/17 16:48:40 by lbenard          ###   ########.fr       */
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

t_instance	*new_instance(t_usize size, char *window_title)
{
	t_instance	*ret;

	if (!(ret = (t_instance*)malloc(sizeof(t_instance))))
		return (throw_error());
	ft_bzero(ret, sizeof(t_instance));
	if (!(ret->mlx = mlx_init()))
	{
		free(ret);
		return (throw_error_str("error while initializing mlx"));
	}
	if (!(ret->window = new_window(ret->mlx, size, window_title)))
	{
		free(ret->mlx);
		free(ret);
		return (throw_error_str("error while creating window"));
	}
	add_hooks(ret);
	return (ret);
}
