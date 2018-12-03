/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3f_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 00:57:34 by freezee           #+#    #+#             */
/*   Updated: 2018/12/02 00:58:52 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_vec3f_dot(t_vec3f a, t_vec3f b)
{
	return (a.x * b.x +
		a.y * b.y +
		a.z * b.z);
}