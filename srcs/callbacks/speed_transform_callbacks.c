/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_transform_callbacks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:25:18 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/19 17:26:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "keycodes.h"

int	speed_transform_press_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_CTRL_LEFT)
		keys[speed_transform] = 1;
	return (1);
}

int	speed_transform_release_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_CTRL_LEFT)
		keys[speed_transform] = 0;
	return (1);
}
