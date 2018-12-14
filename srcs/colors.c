/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 03:16:39 by freezee           #+#    #+#             */
/*   Updated: 2018/12/13 15:45:42 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "libft.h"

t_color	ft_color(float r, float g, float b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

int		color_to_int(t_color color)
{
	int	result;
	int	cast;
	
	cast = (int)(color.r * 255.0f);
	result = (cast > 255) ? 0 : (t_u8)cast;
	result <<= 8;
	cast = (int)(color.g * 255.0f);
	result += (cast > 255) ? 0 : (t_u8)cast;
	result <<= 8;
	cast = (int)(color.b * 255.0f);
	result += (cast > 255) ? 0 : (t_u8)cast;
	return (result);
}

#include <stdio.h>

t_color	int_to_color(int color)
{
	t_color	result;

	result.b = (t_u8)color / 255.0f;
	result.g = (t_u8)(color >> 8) / 255.0f;
	result.r = (t_u8)(color >> 16) / 255.0f;
	return (result);
}

void	color_add(t_color *color, t_color add)
{
	color->r += add.r;
	color->g += add.g;
	color->b += add.b;
}