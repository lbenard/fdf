/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_press_callbacks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:33:20 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/10 16:24:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instance.h"
#include "libft.h"
#include "controls.h"
#include "keycodes.h"

static void	pre_press_callback(t_u8 *keys, int keycode)
{
	if (keycode == KEY_ESCAPE)
		keys[window_exit] = 1;
	if (keycode == KEY_CTRL_LEFT)
		keys[transform_smooth] = 1;
}

static void	translation_press_callback(t_u8 *keys, int keycode)
{
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
}

static void	rotation_press_callback(t_u8 *keys, int keycode)
{
	if (keycode == KEY_PAD_8)
		keys[rotation_nx] = (keys[transform_smooth] ?
			keys[rotation_nx] : 0) + 1;
	if (keycode == KEY_PAD_5)
		keys[rotation_px] = (keys[transform_smooth] ?
			keys[rotation_px] : 0) + 1;
	if (keycode == KEY_PAD_4)
		keys[rotation_ny] = (keys[transform_smooth] ?
			keys[rotation_ny] : 0) + 1;
	if (keycode == KEY_PAD_6)
		keys[rotation_py] = (keys[transform_smooth] ?
			keys[rotation_py] : 0) + 1;
}


static void	scale_press_callback(t_u8 *keys, int keycode)
{
	if (keycode == KEY_PAD_ADD)
		keys[scale_zoom] = 1;
	if (keycode == KEY_PAD_SUB)
		keys[scale_dezoom] = 1;
	if (keycode == KEY_PAGE_DOWN)
		keys[scale_flatten] = 1;
	if (keycode == KEY_PAGE_UP)
		keys[scale_stretch] = 1;
}

int			control_press_callback(int keycode, void *params)
{
	t_u8	*keys;

	keys = ((t_instance*)params)->window->keys;
	pre_press_callback(keys, keycode);
	translation_press_callback(keys, keycode);
	rotation_press_callback(keys, keycode);
	scale_press_callback(keys, keycode);
	return (1);
}
