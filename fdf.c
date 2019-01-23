/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:58:33 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/23 17:34:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instance.h"
#include "renderer.h"
#include "model.h"
#include "errors.h"
#include <stdlib.h>
#include "mlx.h"

static int	args_to_batch(int ac, const char **av, t_batch *batch)
{
	size_t	i;
	t_model	*added_model;

	i = 1;
	while (i < (size_t)ac)
	{
		if (!(added_model = batch_add(batch, av[i],
			ft_vec3f(0.0f, 0.0f, 50.0f), ft_vec3f(-PI, 0.0f, 0.0f))))
		{
			throw_error_str("error while adding to batch");
			return (0);
		}
		free(added_model->name);
		added_model->name = (ft_strrchr(av[i], '/'))
			? ft_strdup(ft_strrchr(av[i], '/') + 1)
			: ft_strdup(av[i]);
		i++;
	}
	return (1);
}

/*
** Mac fullscreen resolution: 2560 * 1396
*/

int			main(int ac, const char **av)
{
	t_instance	*instance;
	t_renderer	*renderer;

	if (ac < 2)
		return (!throw_error_str("Missing file operand"));
	if (!(instance = new_instance(ft_usize(1280, 720), "fdf")))
		return (!throw_error_str("error while creating instance"));
	if (!(renderer = new_renderer(instance)))
	{
		free(instance);
		return (!throw_error_str("error while creating renderer"));
	}
	instance->renderer = renderer;
	if (!(args_to_batch(ac, av, renderer->batch)))
		return (!throw_error());
	instance_add_hook(instance, 2, press_callback, instance);
	instance_add_hook(instance, 3, release_callback, instance);
	instance_add_loop_callback(instance, gameloop, instance);
	mlx_loop(instance->mlx);
}
