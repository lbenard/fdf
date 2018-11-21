/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:25:10 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/21 19:50:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTANCE_H
# define INSTANCE_H

typedef struct	s_instance
{
	void	*mlx_handle;
	void	*mlx_window_handle;
}				t_instance;

t_instance	new_instance(int x, int y, char *window_title);
void		instance_add_key_callback(int (*callback)(), void *params);
void		instance_add_mouse_callback(int (*callback)(), void *params);
void		instance_add_expose_callback(int (*callback)(), void *params);
void		instance_add_loop_callback(int (*callback)(), void *params);

#endif
