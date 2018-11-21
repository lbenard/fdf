/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:06:24 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/21 15:09:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pos.h"

t_pos	pos(int x, int y)
{
	t_pos	retval;

	retval.x = x;
	retval.y = y;
	return (retval);
}

void	pos_add(t_pos *self, int x, int y)
{
	self->x += x;
	self->y += y;
}
