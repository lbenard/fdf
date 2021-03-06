/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:54:46 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/19 17:13:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "libft.h"
# include "controls.h"
# include "instance.h"

typedef struct s_instance	t_instance;

typedef struct	s_window
{
	void	*handle;
	void	*image;
	int		*framebuffer;
	t_u8	keys[control_last];
	t_usize	size;
	char	*title;
}				t_window;

t_window		*new_window(void *mlx, t_usize size, char *window_title);
void			free_window(t_window *self, t_instance *instance);

#endif
