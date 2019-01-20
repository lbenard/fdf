/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_translation_callbacks.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:29:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/20 17:01:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "keycodes.h"

int	model_translation_press_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_LEFT)
		keys[model_translation_nx] = (keys[speed_transform] ?
			keys[model_translation_nx] : 0) + 1;
	if (keycode == KEY_RIGHT)
		keys[model_translation_px] = (keys[speed_transform] ?
			keys[model_translation_px] : 0) + 1;
	if (keycode == KEY_HOME)
		keys[model_translation_ny] = (keys[speed_transform] ?
			keys[model_translation_py] : 0) + 1;
	if (keycode == KEY_END)
		keys[model_translation_py] = (keys[speed_transform] ?
			keys[model_translation_ny] : 0) + 1;
	if (keycode == KEY_DOWN)
		keys[model_translation_nz] = (keys[speed_transform] ?
			keys[model_translation_nz] : 0) + 1;
	if (keycode == KEY_UP)
		keys[model_translation_pz] = (keys[speed_transform] ?
			keys[model_translation_pz] : 0) + 1;
	return (1);
}

int	model_translation_release_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_LEFT)
		keys[model_translation_nx] = 0;
	if (keycode == KEY_RIGHT)
		keys[model_translation_px] = 0;
	if (keycode == KEY_HOME)
		keys[model_translation_ny] = 0;
	if (keycode == KEY_END)
		keys[model_translation_py] = 0;
	if (keycode == KEY_DOWN)
		keys[model_translation_nz] = 0;
	if (keycode == KEY_UP)
		keys[model_translation_pz] = 0;
	return (1);
}
