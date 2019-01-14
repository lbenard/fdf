/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:56:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/11 17:07:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include <stdlib.h>
#include "errors.h"
#include "mlx.h"

t_window	*new_window(void *mlx, t_usize size, char *window_title)
{
	t_window	*ret;
	int			trash;

	if (!(ret = (t_window*)malloc(sizeof(t_window))))
		return (throw_error());
	ret->size = size;
	ret->title = window_title;
	if (!(ret->handle = mlx_new_window(mlx, size.x, size.y,
		window_title)))
	{
		free(ret);
		return (throw_error());
	}
	if (!(ret->image = mlx_new_image(mlx, size.x, size.y)))
	{
		mlx_destroy_window(mlx, ret->handle);
		free(ret);
		return (throw_error());
	}
	if (!(ret->framebuffer = (int*)mlx_get_data_addr(ret->image, &trash, &trash,
		&trash)))
	{
		mlx_destroy_window(mlx, ret->handle);
		mlx_destroy_image(mlx, ret->image);
		free(ret);
		return (throw_error());
	}
	ft_bzero(ret->keys, control_last);
	return (ret);
}
