/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:14:53 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/27 18:15:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat4	ft_mat4(void)
{
	t_mat4	retval;

	ft_bzero(&retval, sizeof(t_mat4));
	return (retval);
}
