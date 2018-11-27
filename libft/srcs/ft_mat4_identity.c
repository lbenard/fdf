/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_identity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:22:53 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/27 18:23:54 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat4	ft_mat4_identity(void)
{
	t_mat4	retval;

	ft_bzero(&retval, sizeof(t_mat4));
	retval.m[0][0] = 1.0f;
	retval.m[1][1] = 1.0f;
	retval.m[2][2] = 1.0f;
	retval.m[3][3] = 1.0f;
	return (retval);
}
