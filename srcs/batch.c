/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:02:01 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/16 18:11:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "batch.h"
#include <stdlib.h>
#include "errors.h"
#include "mesh.h"
#include "model.h"
#include "libft.h"
#include "parser.h"

t_batch	*new_batch(void)
{
	t_batch	*ret;

	if (!(ret = (t_batch*)malloc(sizeof(t_batch))))
		return (throw_error());
	ret->batch = NULL;
	ret->size = 0;
	return (ret);
}

#include <stdio.h>

int		batch_add(t_batch *self, const char *path, t_vec3f position,
	t_vec3f rotation)
{
	t_mesh	*mesh;
	t_model	*model;

	if (ft_strcmp(path + ft_strlen(path) - 4, ".fdf") == 0)
		mesh = parse_fdf(path);
	else if (ft_strcmp(path + ft_strlen(path) - 4, ".ply") == 0)
		mesh = parse_ply(path);
	else
		return (0);
	if (!(model = new_model(mesh, position, rotation,
		ft_vec3f(1.0f, 1.0f, 1.0f))))
		return (0);
	if (!self->batch)
		self->batch = ft_lstnew(model, sizeof(t_model));
	else
		ft_lstpushback(&self->batch, ft_lstnew(model, sizeof(t_model)));
	return (1);
}
