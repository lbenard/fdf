/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:56:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/19 19:06:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include <stdlib.h>
#include "errors.h"
#include "mlx.h"

static t_window	*new_window_2(t_usize size, char *window_title)
{
	t_window	*ret;

	if (!(ret = (t_window*)malloc(sizeof(t_window))))
		return (throw_error());
	ret->size = size;
	ret->title = ft_strdup(window_title);
	ft_bzero(ret->keys, control_last);
	return (ret);
}

t_window		*new_window(void *mlx, t_usize size, char *window_title)
{
	t_window	*ret;
	int			trash;

	if (!(ret = new_window_2(size, window_title)))
		return (throw_error());
	if (!(ret->handle = mlx_new_window(mlx, size.x, size.y, window_title)))
	{
		free(ret);
		return (throw_error_str("error while creating mlx window"));
	}
	if (!(ret->image = mlx_new_image(mlx, size.x, size.y)))
	{
		mlx_destroy_window(mlx, ret->handle);
		free(ret);
		return (throw_error_str("error while getting mlx image"));
	}
	if (!(ret->framebuffer = (int*)mlx_get_data_addr(ret->image, &trash, &trash,
		&trash)))
	{
		mlx_destroy_window(mlx, ret->handle);
		mlx_destroy_image(mlx, ret->image);
		free(ret);
		return (throw_error_str("error while getting mlx framebuffer"));
	}
	return (ret);
}

void			free_window(t_window *self, t_instance *instance)
{
	(void)instance;
	mlx_destroy_image(instance->mlx, self->image);
	mlx_destroy_window(instance->mlx, self->handle);
	free(self->title);
	free(self);
}
