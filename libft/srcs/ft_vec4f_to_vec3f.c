/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec4f_to_vec3f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:32:03 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/30 16:33:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3f	ft_vec4f_to_vec3f(t_vec4f src)
{
	t_vec3f	dst;

	ft_memcpy(&dst, &src, sizeof(t_vec3f));
	return (dst);
}
