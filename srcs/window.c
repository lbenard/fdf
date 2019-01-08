/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:56:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/07 17:02:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include <stdlib.h>
#include "errors.h"
#include "mlx.h"

t_window	*new_window(void *mlx, t_usize size, char *window_title)
{
	t_window	*ret;

	if (!(ret = (t_window*)malloc(sizeof(t_window))))
		return (throw_error());
	ret->size = size;
	ret->title = window_title;
	if (!(ret->image = mlx_new_image(mlx, size.x, size.y)))
	{
		free(ret);
		return (throw_error());
	}
	if (!(ret->handle = mlx_new_window(mlx, size.x, size.y,
		window_title)))
	{
		free(ret->image);
		free(ret);
		return (throw_error());
	}
	ft_bzero(ret->keys, control_last);
	return (ret);
}
