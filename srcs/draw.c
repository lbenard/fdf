/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:31:14 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/03 18:16:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include "colors.h"

#include <stdio.h>

typedef struct	s_vec2i
{
	int	x;
	int	y;
}				t_vec2i;

void	draw_line(t_instance *instance, t_vec2f af, t_vec2f bf, int a_color,
	int b_color)
{
	t_vec2f	d;
	t_vec2f	s;
	t_vec2i	a;
	t_vec2i	b;
	int		err;
	int		e;

	a.x = (int)af.x;
	a.y = (int)af.y;
	b.x = (int)bf.x;
	b.y = (int)bf.y;
	d = ft_vec2f(ft_abs(b.x - a.x), ft_abs(b.y - a.y));
	s = ft_vec2f(a.x < b.x ? 1 : -1, a.y < b.y ? 1 : -1);
	err = (d.x > d.y ? d.x : -d.y) / 2;
	//printf("draw_line: a: %f %f\ndraw_line: b: %f %f\n", a.x, a.y, b.x, b.y);
	(void)b_color;
	while (42)
	{
		if (a.x > 0 && a.y > 0)
			mlx_pixel_put(instance->mlx, instance->window, a.x, a.y,
				a_color);
		if (a.x == b.x && a.y == b.y)
			break ;
		e = err;
		if (e >- d.x)
		{
			err -= d.y;
			a.x += s.x;
			//a_color += 42;
		}
		if (e < d.y)
		{
			err += d.x;
			a.y += s.y;
			//a_color += 42;
		}
	}
}

void	clear(t_instance *instance)
{
	mlx_clear_window(instance->mlx, instance->window);
}

void	draw_mesh(t_instance *instance, t_mesh mesh)
{
	size_t	i;
	t_vec2f	x;
	t_vec2f	y;
	t_vec2f	z;

	i = 0;
	while (i < mesh.mesh_size)
	{
		x = ft_vec3f_to_vec2f(mesh.mesh[i].v0);
		y = ft_vec3f_to_vec2f(mesh.mesh[i].v1);
		z = ft_vec3f_to_vec2f(mesh.mesh[i].v2);
		draw_line(instance, x, y, COLOR_WHITE, COLOR_WHITE);
		draw_line(instance, y, z, COLOR_WHITE, COLOR_WHITE);
		draw_line(instance, z, x, COLOR_WHITE, COLOR_WHITE);
		i++;
	}
}
