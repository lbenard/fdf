/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:48:01 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/30 16:47:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <stdlib.h>

t_camera	new_camera(t_vec3f position, t_projection projection)
{
	t_camera	ret;

	ret.projection = projection;
	ret.position = position;
	return (ret);
}
