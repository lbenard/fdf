/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_callbacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:29:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/10 16:36:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instance.h"
#include "controls.h"
#include "keycodes.h"

int	translation_press_callback(int keycode, void *params)
{
	t_u8	*keys;

	keys = ((t_instance*)params)->window->keys;
	if (keycode == KEY_A)
		keys[translation_nx] = (keys[transform_smooth] ?
			keys[translation_nx] : 0) + 1;
	if (keycode == KEY_D)
		keys[translation_px] = (keys[transform_smooth] ?
			keys[translation_px] : 0) + 1;
	if (keycode == KEY_SPACEBAR)
		keys[translation_ny] = (keys[transform_smooth] ?
			keys[translation_ny] : 0) + 1;
	if (keycode == KEY_SHIFT_LEFT)
		keys[translation_py] = (keys[transform_smooth] ?
			keys[translation_py] : 0) + 1;
	if (keycode == KEY_S)
		keys[translation_nz] = (keys[transform_smooth] ?
			keys[translation_nz] : 0) + 1;
	if (keycode == KEY_W)
		keys[translation_pz] = (keys[transform_smooth] ?
			keys[translation_pz] : 0) + 1;
	return (1);
}

int	translation_release_callback(int keycode, void *params)
{
	t_u8	*keys;

	keys = ((t_instance*)params)->window->keys;
	if (keycode == KEY_A)
		keys[translation_nx] = 0;
	if (keycode == KEY_D)
		keys[translation_px] = 0;
	if (keycode == KEY_SPACEBAR)
		keys[translation_ny] = 0;
	if (keycode == KEY_SHIFT_LEFT)
		keys[translation_py] = 0;
	if (keycode == KEY_S)
		keys[translation_nz] = 0;
	if (keycode == KEY_W)
		keys[translation_pz] = 0;
	return (1);
}
