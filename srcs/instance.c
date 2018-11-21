/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:28:24 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/21 19:50:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instance.h"
#include "mlx.h"

t_instance	new_instance(int x, int y, char *window_title)
{
	t_instance	instance;

	instance.mlx_handle = mlx_init();
	instance.mlx_window_handle = mlx_new_window(instance.mlx_handle, x, y,
		window_title);
	return (instance);
}

/*void		instance_add_key_callback(int (*callback)(), void *params);
void		instance_add_mouse_callback(int (*callback)(), void *params);
void		instance_add_expose_callback(int (*callback)(), void *params);
void		instance_add_loop_callback(int (*callback)(), void *params);*/
