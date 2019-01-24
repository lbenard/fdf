/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ply_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:50:47 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/24 15:02:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "errors.h"
#include <stdlib.h>

static size_t	get_vertex_count(const char *file)
{
	if ((file = ft_strstr(file, "element vertex")))
		return ((size_t)ft_atoi(file + ft_strlen("element vertex")));
	return (0);
}

static size_t	get_indices_count(const char *file)
{
	size_t		face_count;
	size_t		indices_count;
	size_t		i;
	const char	*line;

	if ((file = ft_strstr(file, "element face")))
		face_count = (size_t)ft_atoi(file + ft_strlen("element face"));
	else
		return (0);
	i = 0;
	indices_count = 0;
	line = ft_getline(file, ft_strcount(file, '\n') - face_count);
	while (i < face_count)
	{
		indices_count += ft_atoi(line);
		line = ft_strchr(line, '\n') + 1;
		i++;
	}
	return (indices_count);
}

static void		fill_vertices(t_mesh *mesh, size_t vertex_count,
	const char *file)
{
	size_t	i;

	i = 0;
	while (i < vertex_count)
	{
		mesh->vertices[i].x = ft_atof(file);
		file = ft_strchr(file, ' ') + 1;
		mesh->vertices[i].y = ft_atof(file);
		file = ft_strchr(file, ' ') + 1;
		mesh->vertices[i].z = ft_atof(file);
		file = ft_strchr(file, ' ') + 1;
		mesh->colors[i].r = ft_atoi(file) / 255.0f;
		file = ft_strchr(file, ' ') + 1;
		mesh->colors[i].g = ft_atoi(file) / 255.0f;
		file = ft_strchr(file, ' ') + 1;
		mesh->colors[i].b = ft_atoi(file) / 255.0f;
		file = ft_strchr(file, '\n') + 1;
		i++;
	}
}

static void		fill_indices(t_mesh *mesh, size_t indices_count, char *file)
{
	size_t	i;
	size_t	j;
	size_t	count;
	int		first;

	i = 0;
	while (i < indices_count)
	{
		count = ft_atoi(file);
		file = ft_strchr(file, ' ') + 1;
		j = 0;
		while (j < count)
		{
			mesh->indices[i].x = ft_atoi(file);
			if (j == 0)
				first = mesh->indices[i].x;
			file = ft_strchr(file, (j != count - 1) ? ' ' : '\n') + 1;
			mesh->indices[i].y = (j++ != count - 1) ? ft_atoi(file) : first;
			i++;
		}
	}
}

t_mesh			*parse_ply(const char *path)
{
	char	*file;
	char	*tmp;
	t_mesh	*mesh;
	size_t	vertex_count;
	size_t	indices_count;

	if (!(file = get_file(path)))
		return (throw_error());
	tmp = file;
	if (!ft_strstr(file, "property float x\nproperty float y\nproperty float "
		"z\nproperty uchar red\nproperty uchar green\nproperty uchar blue"))
		return (throw_error_str("incorrect ply format"));
	if (!(vertex_count = get_vertex_count(file)))
		return (throw_error_str("incorrect ply vertex count"));
	if (!(indices_count = get_indices_count(file)))
		return (throw_error_str("incorrect ply indices count"));
	mesh = new_mesh(vertex_count, indices_count);
	file = ft_strstr(file, "end_header") + ft_strlen("end_header") + 1;
	fill_vertices(mesh, vertex_count, file);
	file = (char*)ft_getline(file, vertex_count);
	fill_indices(mesh, indices_count, file);
	free(tmp);
	return (mesh);
}
