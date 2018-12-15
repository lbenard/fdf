/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:25:10 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/15 18:14:54 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTANCE_H
# define INSTANCE_H

# include "libft.h"

typedef struct	s_window
{
	void	*handle;
	void	*image;
	t_usize	size;
	char	*title;
}				t_window;

typedef struct	s_instance
{
	void		*mlx;
	t_window	*window;
	t_list		*key_callbacks;
	t_list		*mouse_callbacks;
	t_list		*expose_callbacks;
	t_list		*loop_callbacks;
}				t_instance;

typedef struct	s_callback
{
	int			(*callback)();
	t_instance	*instance;
	void		*params;
}				t_callback;

t_instance		*new_instance(t_usize size, char *window_title);
void			instance_add_key_callback(t_instance *self,
	int (*callback)(), void *params);
void			instance_add_mouse_callback(t_instance *self,
	int (*callback)(), void *params);
void			instance_add_expose_callback(t_instance *self,
	int (*callback)(), void *params);
void			instance_add_loop_callback(t_instance *self,
	int (*callback)(), void *params);

int			key_callback_handler(int keycode, void *param);
int			mouse_callback_handler(int button, int x, int y, void *param);
int			expose_callback_handler(void *param);
int			loop_callback_handler(void *param);

#endif
