/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:44:48 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/21 15:09:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POS_H
# define POS_H

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

t_pos			pos(int x, int y);
void			pos_add(t_pos *self, int x, int y);

#endif
