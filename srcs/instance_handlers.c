/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:22:55 by freezee           #+#    #+#             */
/*   Updated: 2018/11/29 15:26:47 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTANCE_HANDLERS_H
# define INSTANCE_HANDLERS_H

#include "instance.h"

int	key_callback_handler(int keycode, void *param)
{
	t_list		*list;
	t_callback	*callback;	

	list = (t_list*)param;
	while (list)
	{
		callback = (t_callback*)list->content;
		callback->callback(keycode, callback->params);
		list = list->next;
	}
	return (1);
}

int	mouse_callback_handler(int button, int x, int y, void *param)
{
	t_list		*list;
	t_callback	*callback;	

	list = (t_list*)param;
	while (list)
	{
		callback = (t_callback*)list->content;
		callback->callback(button, x, y, callback->params);
		list = list->next;
	}
	return (1);
}

int	expose_callback_handler(void *param)
{
	t_list		*list;
	t_callback	*callback;	

	list = (t_list*)param;
	while (list)
	{
		callback = (t_callback*)list->content;
		callback->callback(callback->params);
		list = list->next;
	}
	return (1);
}

int	loop_callback_handler(void *param)
{
	t_list		*list;
	t_callback	*callback;	

	list = (t_list*)param;
	while (list)
	{
		callback = (t_callback*)list->content;
		callback->callback(callback->params);
		list = list->next;
	}
	return (1);
}

#endif