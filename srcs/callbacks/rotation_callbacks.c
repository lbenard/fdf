/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_callbacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:35:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/10 16:38:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instance.h"
#include "controls.h"
#include "keycodes.h"

int	rotation_press_callback(int keycode, void *params)
{
	t_u8	*keys;

	keys = ((t_instance*)params)->window->keys;
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
	return (1);
}

int	rotation_release_callback(int keycode, void *params)
{
	t_u8	*keys;

	keys = ((t_instance*)params)->window->keys;
	if (keycode == KEY_PAD_8)
		keys[rotation_nx] = 0;
	if (keycode == KEY_PAD_5)
		keys[rotation_px] = 0;
	if (keycode == KEY_PAD_4)
		keys[rotation_ny] = 0;
	if (keycode == KEY_PAD_6)
		keys[rotation_py] = 0;
	return (1);
}
