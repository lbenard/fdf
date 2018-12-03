/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec4f_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 00:59:02 by freezee           #+#    #+#             */
/*   Updated: 2018/12/02 00:59:36 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_vec4f_dot(t_vec4f a, t_vec4f b)
{
	return (a.x * b.x +
		a.y * b.y +
		a.z * b.z +
		a.w * b.w);
}