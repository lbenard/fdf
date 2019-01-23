/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   water_shader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:24:26 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/23 16:24:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shaders.h"

t_color	water_shader(t_color input_color, t_vec3f raw, t_vec3f model,
	t_vec3f view)
{
	(void)input_color;
	(void)raw;
	(void)view;
	if (color_to_int(input_color) != 0xFFFFFF && model.y <= 0)
		return (input_color);
	if (model.y > 0)
		return (int_to_color(0x0000FF));
	return (int_to_color(0x00FF00));
}
