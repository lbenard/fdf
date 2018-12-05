/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:54:59 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/05 19:03:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <fcntl.h>
#include <stdio.h>
#include "errno.h"

static t_isize	get_map_size(const char *map_path)
{
	int		fd;
	char	*line;
	t_isize	size;

	size.x = -1;
	size.y = -1;
	if ((fd = open(map_path, O_RDONLY) < 0))
	{
		perror("fdf");
		return (size);
	}
	size.y = 0;
	while (get_next_line(fd, &line))
	{
		if (line && size.x > 0)
			if (size.x != (size.x = ft_strcount(line, ' ') + 1))
			{
				size.x = -1;
				size.y = -1;
				return (size);
			}
		size.y++;
		free(line);
	}
	return (size);
}

t_mesh	*parse_map(const char *path)
{
	t_mesh	*map;
	t_isize	map_size;

	map_size = get_map_size(path);
	if (map_size.x < 0 || map_size.y < 0)
		return (NULL);
	if (!(map = new_mesh(SQUARE, map_size.x * map_size.y,
		(map_size.x - 1) * 2 * (map_size.y - 1) + map_size.x - 1)
}
