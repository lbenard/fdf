/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:39:52 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/16 17:34:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define COLOR_BLACK	0x000000
# define COLOR_WHITE	0xFFFFFF
# define COLOR_RED		0xFF0000
# define COLOR_GREEN	0x00FF00
# define COLOR_BLUE		0x0000FF

typedef struct	s_color
{
	float	r;
	float	g;
	float	b;
}				t_color;

t_color			ft_color(float r, float g, float b);
int				color_to_int(t_color color);
t_color			int_to_color(int color);
void			color_add(t_color *color, t_color add);
void			color_multiply(t_color *color, t_color multiply);

#endif
