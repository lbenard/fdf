/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_translation_callbacks.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:29:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/19 01:44:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "keycodes.h"

int	model_translation_press_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_LEFT)
		keys[model_translation_nx] = (keys[model_transform_smooth] ?
			keys[model_translation_nx] : 0) + 1;
	if (keycode == KEY_RIGHT)
		keys[model_translation_px] = (keys[model_transform_smooth] ?
			keys[model_translation_px] : 0) + 1;
	if (keycode == KEY_INSERT)
		keys[model_translation_py] = (keys[model_transform_smooth] ?
			keys[model_translation_py] : 0) + 1;
	if (keycode == KEY_DEL)
		keys[model_translation_ny] = (keys[model_transform_smooth] ?
			keys[model_translation_ny] : 0) + 1;
	if (keycode == KEY_DOWN)
		keys[model_translation_nz] = (keys[model_transform_smooth] ?
			keys[model_translation_nz] : 0) + 1;
	if (keycode == KEY_UP)
		keys[model_translation_pz] = (keys[model_transform_smooth] ?
			keys[model_translation_pz] : 0) + 1;
	return (1);
}

int	model_translation_release_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_LEFT)
		keys[model_translation_nx] = 0;
	if (keycode == KEY_RIGHT)
		keys[model_translation_px] = 0;
	if (keycode == KEY_INSERT)
		keys[model_translation_py] = 0;
	if (keycode == KEY_DEL)
		keys[model_translation_ny] = 0;
	if (keycode == KEY_DOWN)
		keys[model_translation_nz] = 0;
	if (keycode == KEY_UP)
		keys[model_translation_pz] = 0;
	return (1);
}
