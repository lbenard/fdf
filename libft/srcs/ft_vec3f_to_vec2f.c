/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3f_to_vec2f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:49:05 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/30 17:50:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec2f	ft_vec3f_to_vec2f(t_vec3f src)
{
	t_vec2f	dst;

	ft_memcpy(&dst, &src, sizeof(t_vec2f));
	return (dst);
}
