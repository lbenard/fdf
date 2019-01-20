/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_translation_callbacks.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 01:32:40 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/20 18:08:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "keycodes.h"

int	camera_translation_press_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_W)
		keys[camera_translation_pz] = (keys[speed_transform] ?
			keys[camera_translation_pz] : 0) + 1;
	if (keycode == KEY_A)
		keys[camera_translation_nx] = (keys[speed_transform] ?
			keys[camera_translation_nx] : 0) + 1;
	if (keycode == KEY_S)
		keys[camera_translation_nz] = (keys[speed_transform] ?
			keys[camera_translation_nz] : 0) + 1;
	if (keycode == KEY_D)
		keys[camera_translation_px] = (keys[speed_transform] ?
			keys[camera_translation_px] : 0) + 1;
	if (keycode == KEY_SPACEBAR)
		keys[camera_translation_ny] = (keys[speed_transform] ?
			keys[camera_translation_ny] : 0) + 1;
	if (keycode == KEY_SHIFT_LEFT)
		keys[camera_translation_py] = (keys[speed_transform] ?
			keys[camera_translation_py] : 0) + 1;
	return (1);
}

int	camera_translation_release_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_W)
		keys[camera_translation_pz] = 0;
	if (keycode == KEY_A)
		keys[camera_translation_nx] = 0;
	if (keycode == KEY_S)
		keys[camera_translation_nz] = 0;
	if (keycode == KEY_D)
		keys[camera_translation_px] = 0;
	if (keycode == KEY_SPACEBAR)
		keys[camera_translation_ny] = 0;
	if (keycode == KEY_SHIFT_LEFT)
		keys[camera_translation_py] = 0;
	return (1);
}
