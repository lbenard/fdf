/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:45:20 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/05 18:41:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "libft.h"

typedef struct	s_projection
{
	t_mat4	projection;
}				t_projection;

typedef struct	s_camera
{
	t_projection	projection;
	t_vec3f			position;
	t_vec2f			rotation;
}				t_camera;

t_camera	*new_camera(t_vec3f position, t_vec2f rotation,
	t_projection projection);

#endif
