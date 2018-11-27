/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mat3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:28:58 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/27 19:21:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_max_nblen(t_mat3 *mat)
{
	size_t	max_nb_len;
	size_t	i;
	size_t	j;

	max_nb_len = 0;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			max_nb_len = ft_max((int)ft_nblen(((int)mat->m[j][i])),
				(int)max_nb_len);
			j++;
		}
		i++;
	}
	return (max_nb_len);
}

void			ft_print_mat3(t_mat3 *mat)
{
	size_t	max_nb_len;
	size_t	i;
	size_t	j;
	size_t	k;

	max_nb_len = get_max_nblen(mat);
	i = 0;
	while (i < 3)
	{
		ft_putstr("[ ");
		j = 0;
		while (j < 3)
		{
			k = 0;
			while (k++ < max_nb_len - (int)ft_nblen((int)mat->m[i][j]))
				ft_putchar(' ');
			ft_putnbr((int)mat->m[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putstr("]\n");
		i++;
	}
}