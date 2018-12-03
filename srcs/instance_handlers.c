/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:22:55 by freezee           #+#    #+#             */
/*   Updated: 2018/11/29 19:11:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTANCE_HANDLERS_H
# define INSTANCE_HANDLERS_H

#include "instance.h"

int	key_callback_handler(int keycode, void *param)
{
	t_list		*list;
	t_callback	*callback;

	if (!param)
		return (-1);
	list = *((t_list**)param);
	while (list)
	{
		callback = (t_callback*)list->content;
		callback->callback(keycode, *((void**)callback->params));
		list = list->next;
	}
	return (0);
}

#include <stdio.h>

int	mouse_callback_handler(int button, int x, int y, void *param)
{
	t_list		*list;
	t_callback	*callback;

	if (!param)
		return (-1);
	list = *((t_list**)param);
	while (list)
	{
		callback = (t_callback*)list->content;
		callback->callback(button, x, y, *((void**)callback->params));
		list = list->next;
	}
	return (0);
}

int	expose_callback_handler(void *param)
{
	t_list		*list;
	t_callback	*callback;

	if (!param)
		return (-1);
	list = *((t_list**)param);
	while (list)
	{
		callback = (t_callback*)list->content;
		callback->callback(callback->params);
		list = list->next;
	}
	return (0);
}

int	loop_callback_handler(void *param)
{
	t_list		*list;
	t_callback	*callback;

	if (!param)
		return (-1);
	list = *((t_list**)param);
	while (list)
	{
		callback = (t_callback*)list->content;
		callback->callback(*((void**)callback->params));
		list = list->next;
	}
	return (0);
}

#endif