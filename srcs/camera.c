/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:48:01 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/30 06:18:11 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <stdlib.h>

t_camera	new_camera(t_vec3f position, t_vec2f rotation,
	t_projection projection)
{
	t_camera	ret;

	ret.projection = projection;
	ret.position = position;
	ret.rotation = rotation;
	return (ret);
}