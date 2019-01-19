/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:42:05 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/19 01:25:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# include "libft.h"

typedef enum	e_controls
{
	camera_translation_nx,
	camera_translation_px,
	camera_translation_ny,
	camera_translation_py,
	camera_translation_nz,
	camera_translation_pz,
	camera_rotation_nx,
	camera_rotation_px,
	camera_rotation_ny,
	camera_rotation_py,
	model_translation_nx,
	model_translation_px,
	model_translation_ny,
	model_translation_py,
	model_translation_nz,
	model_translation_pz,
	model_rotation_nx,
	model_rotation_px,
	model_rotation_ny,
	model_rotation_py,
	model_rotation_nz,
	model_rotation_pz,
	model_scale_zoom,
	model_scale_dezoom,
	model_scale_flatten,
	model_scale_stretch,
	model_transform_smooth,
	model_previous,
	model_next,
	window_exit,
	control_last
}				t_controls;

int				press_callback(int keycode, void *params);
int				release_callback(int keycode, void *params);

int				camera_translation_press_callback(int keycode,
	t_u8 keys[control_last]);
int				camera_translation_release_callback(int keycode,
	t_u8 keys[control_last]);

int				camera_rotation_press_callback(int keycode,
	t_u8 keys[control_last]);
int				camera_rotation_release_callback(int keycode,
	t_u8 keys[control_last]);

int				model_translation_press_callback(int keycode,
	t_u8 keys[control_last]);
int				model_translation_release_callback(int keycode,
	t_u8 keys[control_last]);

int				model_rotation_press_callback(int keycode,
	t_u8 keys[control_last]);
int				model_rotation_release_callback(int keycode,
	t_u8 keys[control_last]);

int				model_scale_press_callback(int keycode,
	t_u8 keys[control_last]);
int				model_scale_release_callback(int keycode,
	t_u8 keys[control_last]);

int				model_list_press_callback(int keycode,
	t_u8 keys[control_last]);
int				model_list_release_callback(int keycode,
	t_u8 keys[control_last]);

#endif
