/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:23:01 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/27 17:42:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_handles
{
	void	*mlx;
	void	*window;
}				t_handles;

typedef struct	s_args
{
	char	*map_path;
}				t_args;

#endif
