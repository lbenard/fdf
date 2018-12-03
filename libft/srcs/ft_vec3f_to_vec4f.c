/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3f_to_vec4f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:27:59 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/03 02:46:16 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec4f	ft_vec3f_to_vec4f(t_vec3f src)
{
	t_vec4f	dst;

	ft_memcpy(&dst, &src, sizeof(t_vec3f));
	dst.w = 1;
	return (dst);
}
