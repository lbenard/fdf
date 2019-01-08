/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:42:05 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/08 16:58:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

int				control_press_callback(int keycode, void *params);
int				control_release_callback(int keycode, void *params);

typedef enum	e_controls
{
	translation_nx,
	translation_px,
	translation_ny,
	translation_py,
	translation_nz,
	translation_pz,
	rotation_nx,
	rotation_px,
	rotation_ny,
	rotation_py,
	rotation_nz,
	rotation_pz,
	scale_zoom,
	scale_dezoom,
	scale_flatten,
	scale_stretch,
	transform_smooth,
	window_exit,
	control_last
}				t_controls;

#endif
