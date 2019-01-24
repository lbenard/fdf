/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:54:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/24 17:10:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "mesh.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "errors.h"

/*
** Determines the amount of numbers and additional data in the `line` string.
*/

static ssize_t	numbers_count(const char *line)
{
	ssize_t	count;

	while (*line && *line != '\n' && *line == ' ')
		line++;
	count = 0;
	while (*line && *line != '\n')
	{
		while (*line && *line != '\n' && *line != ' ')
			line++;
		count++;
		while (*line && *line != '\n' && *line == ' ')
			line++;
	}
	return (count);
}

/*
** Open the file at `map_path` path and determines the map size. If the file
** is incorrect, the function return [-1, -1].
*/

static t_isize	get_map_size(const char *file)
{
	size_t	lines;
	size_t	i;
	t_isize	size;

	lines = ft_strcount(file, '\n');
	i = 0;
	size = ft_isize(-1, lines);
	while (i < lines)
	{
		if (size.x == -1)
			size.x = numbers_count(ft_getline(file, i));
		else if (numbers_count(ft_getline(file, i)) != size.x)
			return (ft_isize(-1, -1));
		i++;
	}
	return (size);
}

/*
** Parse the file using `get_next_line`. If the `fd` file descriptor is
** incorrect, the function will print a standard error then return NULL.
** Otherwise, the function will return the filled `mesh` argument.
** If the specified `map_size` argument is not correct, then the behavior is
** undefined.
*/

static t_mesh	*fill_mesh(const char *file, t_mesh *mesh,
	const t_isize map_size)
{
	t_isize		i;
	size_t		j;
	size_t		k;

	j = 0;
	k = 0;
	i.y = 0;
	while (i.y < map_size.y)
	{
		i.x = 0;
		while (i.x < map_size.x && (file = ft_skipchr(file, ' ')))
		{
			mesh->vertices[j] = ft_vec3f(i.x * 10, ft_atoi(file), i.y * 10);
			mesh->colors[j] = int_to_color(0xFFFFFF);
			if (i.x != map_size.x - 1 && (file = ft_strchr(file, ' ')))
				mesh->indices[k++] = ft_vec2i(j, j + 1);
			if (i.y != map_size.y - 1)
				mesh->indices[k++] = ft_vec2i(j, j + map_size.x);
			j++;
			i.x++;
		}
		file = ft_strchr(file, '\n') + 1;
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

static t_mesh	*create_mesh(const char *file, t_isize map_size)
{
	t_mesh	*map;

	if (map_size.x < 1 || map_size.y < 1)
		return (throw_error_str("incorrect fdf map"));
	if (!(map = new_mesh(map_size.x * map_size.y,
		(map_size.x - 1) * map_size.y + (map_size.y - 1) * map_size.x)))
		return (throw_error_str("error while creating mesh"));
	if (!(map = fill_mesh(file, map, map_size)))
	{
		free_mesh(map);
		return (throw_error_str("error while filling mesh"));
	}
	return (map);
}

t_mesh			*parse_fdf(const char *path)
{
	t_mesh		*map;
	t_isize		map_size;
	char		*file;
	size_t		i;
	t_mat4		origin;

	if (!(file = get_file(path)))
		return (throw_error_str("incorrect file"));
	map_size = get_map_size(file);
	if (!(map = create_mesh(file, map_size)))
	{
		free(file);
		return (throw_error_str("error while creating fdf mesh"));
	}
	i = 0;
	origin = ft_mat4_translation(ft_vec3f(-(map_size.x * 10 - 10) / 2.0f,
		0.0f, -(map_size.y * 10 - 10) / 2.0f));
	while (i < map->vertices_count)
	{
		map->vertices[i] = ft_vec4f_to_vec3f(ft_mat4_x_vec4(origin,
			ft_vec3f_to_vec4f(map->vertices[i])));
		i++;
	}
	free(file);
	return (map);
}
