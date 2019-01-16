/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_release_callbacks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:59:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/16 16:46:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instance.h"
#include "libft.h"
#include "controls.h"
#include "keycodes.h"

static void	pre_release_callback(t_u8 *keys, int keycode)
{
	if (keycode == KEY_ESCAPE)
		keys[window_exit] = 0;
	if (keycode == KEY_CTRL_LEFT)
		keys[transform_smooth] = 0;
	if (keycode == KEY_EQUAL)
		keys[model_next] = 0;
	if (keycode == KEY_MINUS)
		keys[model_previous] = 0;
}

static void	translation_release_callback(t_u8 *keys, int keycode)
{
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
}

static void	rotation_release_callback(t_u8 *keys, int keycode)
{
	if (keycode == KEY_PAD_8)
		keys[rotation_nx] = 0;
	if (keycode == KEY_PAD_5)
		keys[rotation_px] = 0;
	if (keycode == KEY_PAD_4)
		keys[rotation_ny] = 0;
	if (keycode == KEY_PAD_6)
		keys[rotation_py] = 0;
}


static void	scale_release_callback(t_u8 *keys, int keycode)
{
	if (keycode == KEY_PAD_ADD)
		keys[scale_zoom] = 0;
	if (keycode == KEY_PAD_SUB)
		keys[scale_dezoom] = 0;
	if (keycode == KEY_PAGE_DOWN)
		keys[scale_flatten] = 0;
	if (keycode == KEY_PAGE_UP)
		keys[scale_stretch] = 0;
}

int			control_release_callback(int keycode, void *params)
{
	t_u8	*keys;

	keys = ((t_instance*)params)->window->keys;
	pre_release_callback(keys, keycode);
	translation_release_callback(keys, keycode);
	rotation_release_callback(keys, keycode);
	scale_release_callback(keys, keycode);
	return (1);
}
