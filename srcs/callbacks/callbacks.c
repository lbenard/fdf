/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 01:19:23 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/20 17:04:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "instance.h"

int	press_callback(int keycode, void *params)
{
	t_u8	*keys;

	keys = ((t_instance*)params)->window->keys;
	camera_translation_press_callback(keycode, keys);
	camera_rotation_press_callback(keycode, keys);
	model_translation_press_callback(keycode, keys);
	model_rotation_press_callback(keycode, keys);
	model_scale_press_callback(keycode, keys);
	model_list_press_callback(keycode, keys);
	speed_transform_press_callback(keycode, keys);
	switch_projection_press_callback(keycode, keys);
	return (1);
}

int	release_callback(int keycode, void *params)
{
	t_u8	*keys;

	keys = ((t_instance*)params)->window->keys;
	camera_translation_release_callback(keycode, keys);
	camera_rotation_release_callback(keycode, keys);
	model_translation_release_callback(keycode, keys);
	model_rotation_release_callback(keycode, keys);
	model_scale_release_callback(keycode, keys);
	model_list_release_callback(keycode, keys);
	speed_transform_release_callback(keycode, keys);
	switch_projection_release_callback(keycode, keys);
	window_exit_release_callback(keycode, keys);
	return (1);
}
