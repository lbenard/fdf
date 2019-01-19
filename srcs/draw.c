/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:31:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/19 18:47:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include "colors.h"

void	draw_line(t_instance *instance, t_vec2i a, t_vec2i b, t_color a_color,
	t_color b_color)
{
	t_vec2f	d;
	t_vec2f	s;
	float	step;
	t_color	color_step;
	int		err;
	int		e;

	d = ft_vec2f(ft_abs(b.x - a.x), ft_abs(b.y - a.y));
	s = ft_vec2f(a.x < b.x ? 1 : -1, a.y < b.y ? 1 : -1);
	step = (d.x > d.y) ? d.x : d.y;
	color_step = ft_color((b_color.r - a_color.r) / step,
		(b_color.g - a_color.g) / step,
		(b_color.b - a_color.b) / step);
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (42)
	{
		if (a.x > 0 && a.x <= (int)instance->window->size.x
			&& a.y > 0 && a.y <= (int)instance->window->size.y)
			instance->window->framebuffer[(a.y - 1) * instance->window->size.x
				+ a.x - 1] = color_to_int(a_color);
		else
			break ;
		if (a.x == b.x && a.y == b.y)
			break ;
		e = err;
		color_add(&a_color, color_step);
		if (e > -d.x)
		{
			err -= d.y;
			a.x += s.x;
		}
		if (e < d.y)
		{
			err += d.x;
			a.y += s.y;
		}
	}
}

void	clear(t_instance *instance)
{
	mlx_clear_window(instance->mlx, instance->window->handle);
}

void	draw_mesh(t_instance *instance, t_mesh *mesh, int perspective)
{
	size_t	i;
	t_vec3f	a;
	t_vec3f	b;

	i = 0;
	while (i < mesh->indices_count)
	{
		a = mesh->vertices[mesh->indices[i].x];
		b = mesh->vertices[mesh->indices[i].y];
		if (a.z > 0.0f && b.z > 0.0f)
		{
			if (perspective)
			{
				a = ft_vec3f_scalar(a, 1.0f / (a.z / 500.0f));
				b = ft_vec3f_scalar(b, 1.0f / (b.z / 500.0f));
			}
			a.x += instance->window->size.x / 2;
			b.x += instance->window->size.x / 2;
			a.y += instance->window->size.y / 2;
			b.y += instance->window->size.y / 2;
			if ((a.x >= -1.0f && a.x <= (int)instance->window->size.x)
				&& (a.y >= -1.0f && a.y <= (int)instance->window->size.y))
				draw_line(instance, ft_vec2i((int)a.x, (int)a.y),
					ft_vec2i((int)b.x, (int)b.y),
					mesh->colors[mesh->indices[i].x],
					mesh->colors[mesh->indices[i].y]);
			else
				draw_line(instance, ft_vec2i((int)b.x, (int)b.y),
					ft_vec2i((int)a.x, (int)a.y),
					mesh->colors[mesh->indices[i].y],
					mesh->colors[mesh->indices[i].x]);
		}
		i++;
	}
}
