/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat3_identity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:18:54 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/27 18:22:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat3	ft_mat3_identity(void)
{
	t_mat3	retval;

	ft_bzero(&retval, sizeof(t_mat3));
	retval.m[0][0] = 1.0f;
	retval.m[1][1] = 1.0f;
	retval.m[2][2] = 1.0f;
	return (retval);
}
