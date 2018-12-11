/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:39:52 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/11 15:22:48 by lbenard          ###   ########.fr       */
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
	char	padding;
	char	r;
	char	g;
	char	b;
}				t_color;

#endif
