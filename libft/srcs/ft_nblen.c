/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:17:09 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/08 20:17:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nblen(int n)
{
	size_t	size;

	size = (n < 0);
	while (42)
	{
		size++;
		n /= 10;
		if (!n)
			break ;
	}
	return (size);
}
