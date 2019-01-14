/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_callbacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:40:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/10 16:40:59 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instance.h"
#include "controls.h"
#include "keycodes.h"

int	scale_press_callback(int keycode, void *params)
{
	t_u8	*keys;

	keys = ((t_instance*)params)->window->keys;
	if (keycode == KEY_PAD_ADD)
		keys[scale_zoom] = 1;
	if (keycode == KEY_PAD_SUB)
		keys[scale_dezoom] = 1;
	if (keycode == KEY_PAGE_DOWN)
		keys[scale_flatten] = 1;
	if (keycode == KEY_PAGE_UP)
		keys[scale_stretch] = 1;
	return (1);
}

int	scale_release_callback(int keycode, void *params)
{
	t_u8	*keys;

	keys = ((t_instance*)params)->window->keys;
	if (keycode == KEY_PAD_ADD)
		keys[scale_zoom] = 0;
	if (keycode == KEY_PAD_SUB)
		keys[scale_dezoom] = 0;
	if (keycode == KEY_PAGE_DOWN)
		keys[scale_flatten] = 0;
	if (keycode == KEY_PAGE_UP)
		keys[scale_stretch] = 0;
	return (1);
}
