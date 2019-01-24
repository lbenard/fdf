/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:11:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/24 16:45:05 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "libft.h"
# include "instance.h"
# include "mesh.h"
# include "colors.h"

typedef struct	s_line
{
	t_vec2i	a;
	t_color	a_color;
	t_vec2i	b;
	t_color	b_color;
}				t_line;

t_line			new_line(t_vec3f a, t_vec3f b, t_color a_color,
	t_color b_color);
void			draw_line(t_window *window, t_line line);
void			draw_mesh(t_instance *instance, t_model *model,
	t_color shader());

#endif
