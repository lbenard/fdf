/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_rotation_callbacks.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:35:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/19 01:33:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "keycodes.h"

int	model_rotation_press_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_PAD_8)
		keys[model_rotation_nx] = (keys[model_transform_smooth] ?
			keys[model_rotation_nx] : 0) + 1;
	if (keycode == KEY_PAD_5)
		keys[model_rotation_px] = (keys[model_transform_smooth] ?
			keys[model_rotation_px] : 0) + 1;
	if (keycode == KEY_PAD_4)
		keys[model_rotation_ny] = (keys[model_transform_smooth] ?
			keys[model_rotation_ny] : 0) + 1;
	if (keycode == KEY_PAD_6)
		keys[model_rotation_py] = (keys[model_transform_smooth] ?
			keys[model_rotation_py] : 0) + 1;
	return (1);
}

int	model_rotation_release_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_PAD_8)
		keys[model_rotation_nx] = 0;
	if (keycode == KEY_PAD_5)
		keys[model_rotation_px] = 0;
	if (keycode == KEY_PAD_4)
		keys[model_rotation_ny] = 0;
	if (keycode == KEY_PAD_6)
		keys[model_rotation_py] = 0;
	return (1);
}
