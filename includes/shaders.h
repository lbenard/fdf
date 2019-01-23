/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:21:54 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/23 16:23:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADERS_H
# define SHADERS_H

# include "colors.h"
# include "libft.h"

t_color	no_shader(t_color input_color, t_vec3f raw, t_vec3f model,
	t_vec3f view);
t_color	water_shader(t_color input_color, t_vec3f raw, t_vec3f model,
	t_vec3f view);
t_color	disco_shader(t_color input_color, t_vec3f raw, t_vec3f model,
	t_vec3f view);

#endif
