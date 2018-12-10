/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:12:30 by freezee           #+#    #+#             */
/*   Updated: 2018/12/10 19:35:43 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "libft.h"

char	g_error_encountered = 0;

void	*throw_error(void)
{
	if (errno && !g_error_encountered)
		perror("fdf");
	errno = 0;
	g_error_encountered = 1;
	return (NULL);
}

void	*throw_error_str(const char *cause)
{
	if (cause && !g_error_encountered)
	{
		ft_putstr("fdf: ");
		ft_putstr(cause);
		ft_putchar('\n');
	}
	g_error_encountered = 1;
	return (NULL);
}

void	*throw_error_errno(int err)
{
	if (err && !g_error_encountered)
	{
		errno = err;
		perror("fdf");
	}
	g_error_encountered = 1;
	return (NULL);
}