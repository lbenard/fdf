/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_exit_callbacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:52:37 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/19 18:58:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "keycodes.h"

int	window_exit_release_callback(int keycode, t_u8 keys[control_last])
{
	if (keycode == KEY_ESCAPE)
		keys[window_exit] = 1;
	return (1);
}
