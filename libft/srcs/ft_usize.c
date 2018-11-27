/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:01:11 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/27 18:03:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_usize	ft_usize(size_t x, size_t y)
{
	t_usize retval;

	retval.x = x;
	retval.y = y;
	return (retval);
}
