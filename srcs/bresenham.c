/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:43:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/24 17:23:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"
#include "colors.h"
#include "window.h"

t_line		new_line(t_vec3f a, t_vec3f b, t_color a_color, t_color b_color)
{
	t_line	line;

	line.a = ft_vec2i(a.x, a.y);
	line.b = ft_vec2i(b.x, b.y);
	line.a_color = a_color;
	line.b_color = b_color;
	return (line);
}

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

void		draw_line(t_window *window, t_line line)
{
	t_vec2i	d;
	t_vec2i	s;
	float	step;
	t_color	color_step;
	int		err;

	d = ft_vec2i(ft_abs(line.b.x - line.a.x), ft_abs(line.b.y - line.a.y));
	s = ft_vec2i(line.a.x < line.b.x ? 1 : -1, line.a.y < line.b.y ? 1 : -1);
	step = (d.x > d.y) ? d.x : d.y;
	color_step = ft_color((line.b_color.r - line.a_color.r) / step,
		(line.b_color.g - line.a_color.g) / step,
		(line.b_color.b - line.a_color.b) / step);
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (step--)
	{
		if (!pixel_to_buffer(window->framebuffer, line.a,
			color_to_int(line.a_color), window->size))
			break ;
		color_add(&line.a_color, color_step);
		update_bresenham(&err, &line.a, d, s);
	}
}
