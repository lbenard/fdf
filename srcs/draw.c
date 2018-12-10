/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:31:14 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/10 16:00:08 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include "colors.h"

#include <stdio.h>

void	draw_line(t_instance *instance, t_vec2f af, t_vec2f bf, int a_color,
	int b_color)
{
	t_vec2f	d;
	t_vec2f	s;
	t_vec2i	a;
	t_vec2i	b;
	int		err;
	int		e;

	a = ft_vec2i((int)af.x, (int)af.y);
	b = ft_vec2i((int)bf.x, (int)bf.y);
	d = ft_vec2f(ft_abs(b.x - a.x), ft_abs(b.y - a.y));
	s = ft_vec2f(a.x < b.x ? 1 : -1, a.y < b.y ? 1 : -1);
	err = (d.x > d.y ? d.x : -d.y) / 2;
	//printf("draw_line: a: %f %f\ndraw_line: b: %f %f\n", a.x, a.y, b.x, b.y);
	(void)b_color;
	while (42)
	{
		if (a.x > 0 && a.y > 0)
			mlx_pixel_put(instance->mlx, instance->window->handle, a.x, -a.y
				+ instance->window->size.y, a_color);
		if (a.x == b.x && a.y == b.y)
			break ;
		e = err;
		if (e >- d.x)
		{
			err -= d.y;
			a.x += s.x;
			a_color += 42;
		}
		if (e < d.y)
		{
			err += d.x;
			a.y += s.y;
			a_color += 42;
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

	i = 0;
	while (i < mesh->indices_count)
	{
		x = ft_vec3f_to_vec2f(mesh->vertices[mesh->indices[i].x]);
		y = ft_vec3f_to_vec2f(mesh->vertices[mesh->indices[i].y]);
		/*x.x *= 10;
		x.y *= 10;
		y.x *= 10;
		y.y *= 10;*/
		x.x += 640;
		y.x += 640;
		x.y += 360;
		y.y += 360;
		draw_line(instance, x, y, COLOR_WHITE, COLOR_WHITE);
		/*printf("a: x %f y%f z%f\nb: x%f y%f z%f\n",
			mesh->vertices[mesh->indices[i].x].x,
			mesh->vertices[mesh->indices[i].x].y,
			mesh->vertices[mesh->indices[i].x].z,
			mesh->vertices[mesh->indices[i].y].x,
			mesh->vertices[mesh->indices[i].y].y,
			mesh->vertices[mesh->indices[i].y].z);*/
		i++;
	}
}
