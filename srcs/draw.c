/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:31:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/23 17:53:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include "colors.h"
#include "libft.h"

static int	pixel_to_buffer(int *framebuffer, t_vec2i pixel, int color,
	t_usize window_size)
{
	if (pixel.x > 0 && pixel.x <= (int)window_size.x
		&& pixel.y > 0 && pixel.y <= (int)window_size.y)
	{
		framebuffer[(pixel.y - 1) * window_size.x + pixel.x - 1] = color;
		return (1);
	}
	return (0);
}

static void	update_bresenham(int *err, t_vec2i *a, t_vec2i d, t_vec2i s)
{
	int	e;

	e = *err;
	if (e > -d.x)
	{
		*err -= d.y;
		a->x += s.x;
	}
	if (e < d.y)
	{
		*err += d.x;
		a->y += s.y;
	}
}

void		draw_line(t_window *window, t_vec2i a, t_vec2i b, t_color ac,
	t_color bc)
{
	t_vec2i	d;
	t_vec2i	s;
	float	step;
	t_color	color_step;
	int		err;

	d = ft_vec2i(ft_abs(b.x - a.x), ft_abs(b.y - a.y));
	s = ft_vec2i(a.x < b.x ? 1 : -1, a.y < b.y ? 1 : -1);
	step = (d.x > d.y) ? d.x : d.y;
	color_step = ft_color((bc.r - ac.r) / step, (bc.g - ac.g) / step,
		(bc.b - ac.b) / step);
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (step--)
	{
		if (!pixel_to_buffer(window->framebuffer, a, color_to_int(ac),
			window->size))
			break ;
		color_add(&ac, color_step);
		update_bresenham(&err, &a, d, s);
	}
}

void	render(t_instance *instance, size_t i, t_model *mod, t_color shader())
{
	t_vec3f	a;
	t_vec3f	b;
	size_t	ia;
	size_t	ib;
	int		a_first;

	a = mod->view_mesh->vertices[mod->view_mesh->indices[i].x];
	b = mod->view_mesh->vertices[mod->view_mesh->indices[i].y];
	if (a.z > 0.0f && b.z > 0.0f)
	{
		if (instance->renderer->camera->perspective)
		{
			a = ft_vec3f_scalar(a, 1.0f / (a.z / 500.0f));
			b = ft_vec3f_scalar(b, 1.0f / (b.z / 500.0f));
		}
		a.x += instance->window->size.x / 2;
		b.x += instance->window->size.x / 2;
		a.y += instance->window->size.y / 2;
		b.y += instance->window->size.y / 2;
		a_first = (a.x >= -1.0f && a.x <= (int)instance->window->size.x)
			&& (a.y >= -1.0f && a.y <= (int)instance->window->size.y);
		ia = (a_first) ? mod->view_mesh->indices[i].x :
			mod->view_mesh->indices[i].y;
		ib = (!a_first) ? mod->view_mesh->indices[i].x :
			mod->view_mesh->indices[i].y;
		draw_line(instance->window, (a_first) ? ft_vec2i((int)a.x, (int)a.y) :
			ft_vec2i((int)b.x, (int)b.y), (a_first) ? ft_vec2i((int)b.x,
				(int)b.y) : ft_vec2i((int)a.x, (int)a.y),
			shader(mod->view_mesh->colors[ia], mod->raw_mesh->vertices[ia],
				mod->model_mesh->vertices[ia], mod->view_mesh->vertices[ia]),
			shader(mod->view_mesh->colors[ib], mod->raw_mesh->vertices[ib],
				mod->model_mesh->vertices[ib], mod->view_mesh->vertices[ib]));
	}
}

void	draw_mesh(t_instance *instance, t_model *model, t_color shader())
{
	size_t	i;

	i = 0;
	while (i < model->view_mesh->indices_count)
	{
		render(instance, i, model, shader);
		i++;
	}
}
