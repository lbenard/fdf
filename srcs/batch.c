/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:02:01 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/17 16:46:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "batch.h"
#include <stdlib.h>
#include "errors.h"
#include "mesh.h"
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

t_model	*batch_add(t_batch *self, const char *path, t_vec3f position,
	t_vec3f rotation)
{
	t_mesh	*mesh;
	t_model	*model;

	if (ft_strcmp(path + ft_strlen(path) - 4, ".fdf") == 0)
	{
		if (!(mesh = parse_fdf(path)))
			return (throw_error_str("error while parsing fdf"));
	}
	else if (ft_strcmp(path + ft_strlen(path) - 4, ".ply") == 0)
	{
		if (!(mesh = parse_ply(path)))
			return (throw_error_str("error while parsing ply"));
	}
	else
		return (throw_error_str("unknown extension"));
	if (!(model = new_model(mesh, position, rotation,
		ft_vec3f(1.0f, 1.0f, 1.0f))))
		return (throw_error_str("error while creating model"));
	if (!self->batch)
		self->batch = ft_lstnew(model, sizeof(t_model));
	else
		ft_lstpushback(&self->batch, ft_lstnew(model, sizeof(t_model)));
	self->size++;
	return (model);
}
