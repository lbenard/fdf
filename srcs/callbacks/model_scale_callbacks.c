/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_scale_callbacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:40:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/19 01:33:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "keycodes.h"

int	model_scale_press_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_PAD_ADD)
		keys[model_scale_zoom] = 1;
	if (keycode == KEY_PAD_SUB)
		keys[model_scale_dezoom] = 1;
	if (keycode == KEY_PAGE_DOWN)
		keys[model_scale_flatten] = 1;
	if (keycode == KEY_PAGE_UP)
		keys[model_scale_stretch] = 1;
	return (1);
}

int	model_scale_release_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_PAD_ADD)
		keys[model_scale_zoom] = 0;
	if (keycode == KEY_PAD_SUB)
		keys[model_scale_dezoom] = 0;
	if (keycode == KEY_PAGE_DOWN)
		keys[model_scale_flatten] = 0;
	if (keycode == KEY_PAGE_UP)
		keys[model_scale_stretch] = 0;
	return (1);
}
