/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batch.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:56:40 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/16 17:32:41 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BATCH_H
# define BATCH_H

# include "libft.h"

typedef struct	s_batch
{
	t_list	*batch;
	size_t	size;
}				t_batch;

t_batch			*new_batch(void);
int				batch_add(t_batch *self, const char *path, t_vec3f position,
	t_vec3f rotation);
void			free_batch(t_batch *self);

#endif
