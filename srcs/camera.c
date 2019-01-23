/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:46:48 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/23 14:27:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <stdlib.h>
#include "errors.h"
#include "libft.h"
#include <math.h>

t_camera	*new_camera(void)
{
	t_camera	*ret;

	if (!(ret = (t_camera*)malloc(sizeof(t_camera))))
		return (throw_error());
	ret->position = ft_vec3f(0.0f, 0.0f, 0.0f);
	ret->rotation = ft_vec2f(0.0f, 0.0f);
	ret->perspective = 0;
	return (ret);
}

void		camera_rotate(t_camera *self, t_vec2f delta)
{
	self->rotation.x += delta.x;
	self->rotation.y += delta.y;
	if (self->rotation.x > PI / 2)
		self->rotation.x = PI / 2;
	else if (self->rotation.x < -PI / 2)
		self->rotation.x = -PI / 2;
}

void		camera_translate(t_camera *self, t_vec3f delta)
{
	delta = ft_vec4f_to_vec3f(ft_mat4_x_vec4(ft_mat4_rotation(
		ft_vec3f(0, self->rotation.y, 0)), ft_vec3f_to_vec4f(delta)));
	self->position.x += delta.x;
	self->position.y += delta.y;
	self->position.z += delta.z;
}

void		free_camera(t_camera *self)
{
	free(self);
}
