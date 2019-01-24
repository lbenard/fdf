/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:31:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/24 17:24:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include "colors.h"
#include "libft.h"

static void	viewport(t_vec3f *a, t_vec3f *b, t_usize window_size,
	t_camera *camera)
{
	if (camera->perspective)
	{
		*a = ft_vec3f_scalar(*a, 1.0f / (a->z / 500.0f));
		*b = ft_vec3f_scalar(*b, 1.0f / (b->z / 500.0f));
	}
	a->x += window_size.x / 2;
	b->x += window_size.x / 2;
	a->y += window_size.y / 2;
	b->y += window_size.y / 2;
}

static void	draw_order(t_instance *instance, t_model *model, size_t i,
	t_color shader())
{
	t_vec3f	a;
	t_vec3f	b;
	size_t	ia;
	size_t	ib;
	int		a_first;

	a = model->view_mesh->vertices[model->view_mesh->indices[i].x];
	b = model->view_mesh->vertices[model->view_mesh->indices[i].y];
	viewport(&a, &b, instance->window->size, instance->renderer->camera);
	a_first = (a.x >= 0.0f && a.x <= (int)instance->window->size.x)
		&& (a.y >= 0.0f && a.y <= (int)instance->window->size.y);
	ia = (a_first) ? model->view_mesh->indices[i].x :
		model->view_mesh->indices[i].y;
	ib = (!a_first) ? model->view_mesh->indices[i].x :
		model->view_mesh->indices[i].y;
	draw_line(instance->window, new_line((a_first) ? a : b, (a_first) ? b : a,
		shader(model->view_mesh->colors[ia], model->raw_mesh->vertices[ia],
			model->model_mesh->vertices[ia], model->view_mesh->vertices[ia]),
		shader(model->view_mesh->colors[ib], model->raw_mesh->vertices[ib],
			model->model_mesh->vertices[ib], model->view_mesh->vertices[ib])));
}

void		draw_mesh(t_instance *instance, t_model *model, t_color shader())
{
	size_t	i;
	t_vec3f	a;
	t_vec3f	b;

	i = 0;
	while (i < model->view_mesh->indices_count)
	{
		a = model->view_mesh->vertices[model->view_mesh->indices[i].x];
		b = model->view_mesh->vertices[model->view_mesh->indices[i].y];
		if (a.z > 0.0f && b.z > 0.0f)
			draw_order(instance, model, i, shader);
		i++;
	}
}
