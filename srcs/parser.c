/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:54:59 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/06 19:04:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "mesh.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "errno.h"

static t_isize	get_map_size(const char *map_path)
{
	int		fd;
	char	*line;
	t_isize	size;

	size.x = -1;
	size.y = -1;
	if ((fd = open(map_path, O_RDONLY)) < 0)
	{
		perror("fdf");
		return (size);
	}
	size.y = 0;
	while (get_next_line(fd, &line) == LINE_READ)
	{
		if (size.x == -1)
			size.x = ft_strcount(line, ' ') + 1;
		printf("%s\n", line);
		if (line && size.x > 0)
			if (size.x != (size.x = ft_strcount(line, ' ') + 1))
			{
				size.x = -1;
				size.y = -1;
				close(fd);
				return (size);
			}
		size.y++;
		free(line);
	}
	printf("%ld %ld\n", size.x, size.y);
	close(fd);
	return (size);
}

static t_mesh	*fill_mesh(const int fd, t_mesh *mesh, const t_isize map_size)
{
	t_isize	i;
	size_t	j;
	size_t	k;
	char	*line;
	char	*head;

	j = 0;
	k = 0;
	i.y = 0;
	while (i.y < map_size.y)
	{
		i.x = 0;
		if (get_next_line(fd, &line) != LINE_READ)
			return (NULL);
		head = line;
		while (i.x < map_size.x)
		{
			mesh->vertices[j] = ft_vec3f(i.x, ft_atoi(head), i.y);
			if (i.x != map_size.x - 1)
			{
				while (*head++ != ' ')
					;
				mesh->indices[k++] = j;
				mesh->indices[k++] = j + 1;
			}
			if (i.x != map_size.y - 1)
			{
				mesh->indices[k++] = j;
				mesh->indices[k++] = j + map_size.x;
			}
			j++;
			i.x++;
		}
		free(line);
		i.y++;
	}
	return (mesh);
}

t_mesh			*parse_map(const char *path)
{
	t_mesh		*map;
	t_isize		map_size;
	int			fd;

	map_size = get_map_size(path);
	if (map_size.x < 2 || map_size.y < 2)
		return (NULL);
	if (!(map = new_mesh(SQUARE, map_size.x * map_size.y,
		2 * (map_size.x - 1) * (map_size.y - 1) + map_size.x - 1)))
		return (NULL);
	if ((fd = open(path, O_RDONLY) < 0))
	{
		perror("fdf");
		free_mesh(&map);
		return (NULL);
	}
	if (!(map = fill_mesh(fd, map, map_size)))
		free_mesh(&map);
	return (map);
}
