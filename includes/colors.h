/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:39:52 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/13 02:41:11 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define COLOR_BLACK	0x00000000
# define COLOR_WHITE	0x00FFFFFF
# define COLOR_RED		0x00FF0000
# define COLOR_GREEN	0x0000FF00
# define COLOR_BLUE		0x000000FF

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
