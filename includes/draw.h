/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:11:00 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/07 17:54:02 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "libft.h"
# include "instance.h"
# include "mesh.h"

void	draw_line(t_instance *instance, t_vec2f x, t_vec2f y, int a_color,
	int b_color);
void	clear(t_instance *instance);
void	draw_mesh(t_instance *instance, t_mesh *mesh);

#endif
