/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:54:59 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/10 19:25:40 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "mesh.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "errors.h"

/*
** Determines the amount of numbers and additional data in the `line` string.
** If the line ends with unused space(s), the function returns -1.
*/

static ssize_t	numbers_count(const char *line)
{
	ssize_t	count;

	while (*line && *line == ' ')
		line++;
	count = 0;
	while (*line)
	{
		while (*line && *line != ' ')
			line++;
		count++;
		while (*line && *line == ' ')
			if (!*(++line))
				return (-1);
	}
	return (count);
}


/*
** Open the file at `map_path` path and determines the map size. If the file
** is incorrect, the function return [-1, -1].
*/

t_isize			get_map_size(const char *map_path)
{
	int		fd;
	char	*line;
	t_isize	size;
	int		ret;

	size.x = -1;
	size.y = -1;
	if ((fd = open(map_path, O_RDONLY)) < 0)
	{
		throw_error();
		return (size);
	}
	if (read(fd, NULL, 0) < 0)
	{
		throw_error();
		return (size);
	}
	size.y = 0;
	while ((ret = get_next_line(fd, &line) == LINE_READ))
	{
		if (size.x == -1)
			size.x = numbers_count(line);
		if (ret == READ_ERROR || (line && size.x > 0 && size.x != numbers_count(line)))
		{
			size.x = -1;
			size.y = -1;
			close(fd);
			throw_error_errno(79);
			return (size);
		}
		size.y++;
		free(line);
	}
	if (ret == READ_ERROR)
	{
		size.x = -2;
		size.y = -2;
		throw_error_str("Read error");
	}
	close(fd);
	return (size);
}

/*
** Parse the file using `get_next_line`. If the `fd` file descriptor is
** incorrect, the function will print a standard error then return NULL.
** Otherwise, the function will return the filled `mesh` argument.
** If the specified `map_size` argument is not correct, then the behavior is
** undefined.
*/

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
		if (get_next_line(fd, &line) == READ_ERROR)
			return (throw_error_str("Read error"));
		head = line;
		while (*head == ' ')
			head++;
		while (i.x < map_size.x)
		{
			mesh->vertices[j] = ft_vec3f(i.x * 10, ft_atoi(head), i.y * 10);
			if (i.x != map_size.x - 1)
			{
				while (*head != ' ')
					head++;
				while (!ft_isdigit(*head))
					head++;
				mesh->indices[k++] = ft_vec2i(j, j + 1);
			}
			if (i.y != map_size.y - 1)
				mesh->indices[k++] = ft_vec2i(j, j + map_size.x);
			j++;
			i.x++;
		}
		free(line);
		i.y++;
	}
	return (mesh);
}

/*
** Parse a .fdf map. This parser does not handle map errors or non-rectangular
** maps, but it does support padding, or by extension, any amount of space
** before and between numbers. The parsed numbers are treated as integers, if a
** specific number cannot be represented into an `int`, then the behavior is
** undefined.
** The map path is specified through the `path` argument. If incorrect or not
** accessible, a standard error will be printed and the function will return
** NULL.
** Non-digit characters can be present right after the digits so that additional
** informations can be added for a specific vertex.
*/

#include <errno.h>

t_mesh			*parse_map(const char *path)
{
	t_mesh		*map;
	t_isize		map_size;
	int			fd;

	map_size = get_map_size(path);
	if (map_size.x < 2 || map_size.y < 2)
		return (throw_error_str("Incorrect fdf map."));
	if (!(map = new_mesh(SQUARE, map_size.x * map_size.y,
		(map_size.x - 1) * map_size.y + (map_size.y - 1) * map_size.x)))
		return (throw_error());
	if ((fd = open(path, O_RDONLY)) < 0)
	{
		free_mesh(&map);
		return (throw_error());
	}
	if (!(map = fill_mesh(fd, map, map_size)))
	{
		free_mesh(&map);
		return (throw_error());
	}
	return (map);
}