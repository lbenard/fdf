/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_list_callbacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 02:09:47 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/19 02:33:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "keycodes.h"

int	model_list_press_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_MINUS)
		keys[model_previous] = 0;
	if (keycode == KEY_EQUAL)
		keys[model_next] = 0;
	return (1);
}

int	model_list_release_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_MINUS)
		keys[model_previous] = 1;
	if (keycode == KEY_EQUAL)
		keys[model_next] = 1;
	return (1);
}
