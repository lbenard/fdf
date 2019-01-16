/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batch.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:56:40 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/16 18:36:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BATCH_H
# define BATCH_H

# include "libft.h"
# include "model.h"

typedef struct	s_model t_model;

typedef struct	s_batch
{
	t_list	*batch;
	size_t	size;
}				t_batch;

t_batch			*new_batch(void);
t_model			*batch_add(t_batch *self, const char *path, t_vec3f position,
	t_vec3f rotation);
void			free_batch(t_batch *self);

#endif
