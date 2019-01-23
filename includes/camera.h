/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:33:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/23 14:05:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "libft.h"

/*
** FPS camera (two rotation degrees of freedom)
*/

typedef struct	s_camera
{
	t_vec3f	position;
	t_vec2f	rotation;
	int		perspective;
}				t_camera;

t_camera		*new_camera(void);
void			camera_rotate(t_camera *self, t_vec2f delta);
void			camera_translate(t_camera *self, t_vec3f delta);
void			free_camera(t_camera *self);

#endif
