/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotation_callbacks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 01:49:17 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/20 17:26:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "keycodes.h"

int	camera_rotation_press_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_Q)
		keys[camera_rotation_ny] = 1;
	if (keycode == KEY_E)
		keys[camera_rotation_py] = 1;
	return (1);
}

int	camera_rotation_release_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_Q)
		keys[camera_rotation_ny] = 0;
	if (keycode == KEY_E)
		keys[camera_rotation_py] = 0;
	return (1);
}
