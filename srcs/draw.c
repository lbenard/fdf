/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:31:14 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/29 19:57:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include "colors.h"

void	draw_line(t_instance *instance, t_vec2f a, t_vec2f b, int a_color,
	int b_color)
{
	t_vec2f	d;
	t_vec2f	s;
	int		err;
	int		e;

	d = ft_vec2f(ft_abs((int)b.x - a.x), ft_abs((int)b.y - a.y));
	s = ft_vec2f(a.x < b.x ? 1 : -1, a.y < b.y ? 1 : -1);
	err = (d.x > d.y ? d.x : -d.y) / 2;
	(void)b_color;
	while (42)
	{
		mlx_pixel_put(instance->mlx, instance->window, (int)a.x, (int)a.y,
			a_color);
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
