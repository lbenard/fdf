/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:11:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/23 16:46:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "libft.h"
# include "instance.h"
# include "mesh.h"
# include "colors.h"

void	draw_line(t_window *window, t_vec2i x, t_vec2i y, t_color a_color,
	t_color b_color);
void	draw_mesh(t_instance *instance, t_model *model, t_color shader());

#endif
