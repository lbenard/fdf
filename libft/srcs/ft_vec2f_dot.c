/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2f_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 01:00:06 by freezee           #+#    #+#             */
/*   Updated: 2018/12/02 01:00:24 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_vec2f_dot(t_vec2f a, t_vec2f b)
{
	return (a.x * b.x +
		a.y * b.y);
}