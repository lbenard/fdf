/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:12:30 by freezee           #+#    #+#             */
/*   Updated: 2019/01/07 16:49:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "libft.h"

void	*throw_error(void)
{
	if (errno)
		perror("fdf");
	errno = 0;
	return (NULL);
}

void	*throw_error_str(const char *cause)
{
	if (cause)
	{
		ft_putstr("fdf: ");
		ft_putstr(cause);
		ft_putchar('\n');
	}
	return (NULL);
}

void	*throw_error_errno(int err)
{
	if (err)
	{
		errno = err;
		perror("fdf");
	}
	return (NULL);
}
