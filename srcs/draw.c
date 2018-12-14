/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:31:14 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/13 15:53:22 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include "colors.h"

#include <stdio.h>

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
	(void)b_color;
	while (42)
	{
		if (a.x > 0 && a.y > 0)
			mlx_pixel_put(instance->mlx, instance->window->handle, a.x, -a.y
				+ instance->window->size.y, color_to_int(a_color));
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

void	draw_mesh(t_instance *instance, t_mesh *mesh)
{
	size_t	i;
	t_vec2f	x;
	t_vec2f	y;
	t_color	x_color;
	t_color	y_color;

	i = 0;
	while (i < mesh->indices_count)
	{
		x = ft_vec3f_to_vec2f(mesh->vertices[mesh->indices[i].x]);
		y = ft_vec3f_to_vec2f(mesh->vertices[mesh->indices[i].y]);
		x.x += instance->window->size.x / 2;
		y.x += instance->window->size.x / 2;
		x.y += instance->window->size.y / 2;
		y.y += instance->window->size.y / 2;
		x_color = int_to_color(0xFFFFFF);
		y_color = int_to_color(0xFFFFFF);
		/*if (x.y > 10)
			x_color = int_to_color(0x440000);
		if (y.y > 10)
			y_color = int_to_color(0x440000);*/
		draw_line(instance, ft_vec2i((int)x.x, (int)x.y),
			ft_vec2i((int)y.x, (int)y.y),
			x_color, y_color);
		i++;
	}
}
