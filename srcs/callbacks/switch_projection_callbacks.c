/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_projection_callbacks.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:54:07 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/19 18:56:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "keycodes.h"

int	switch_projection_press_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_P)
		keys[switch_perspective] = 1;
	if (keycode == KEY_O)
		keys[switch_orthographic] = 1;
	return (1);
}

int	switch_projection_release_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_P)
		keys[switch_perspective] = 0;
	if (keycode == KEY_O)
		keys[switch_orthographic] = 0;
	return (1);
}
