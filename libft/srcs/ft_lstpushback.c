/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:45:59 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/29 15:37:17 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpushback(t_list **list, t_list *new)
{
	t_list	*head;

	if (!list)
		return (NULL);
	if (!*list)
	{
		*list = new;
		return (new);
	}
	head = *list;
	while (head->next)
		head = head->next;
	head->next = new;
	return (head->next);
}
