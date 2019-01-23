/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_shader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:23:32 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/23 16:23:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shaders.h"

t_color	no_shader(t_color input_color, t_vec3f raw, t_vec3f model,
	t_vec3f view)
{
	(void)raw;
	(void)model;
	(void)view;
	return (input_color);
}
