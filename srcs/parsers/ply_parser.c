/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ply_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:50:47 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/15 20:08:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "errors.h"

static size_t	get_vertex_count(const char *file)
{
	if ((file = ft_strstr(file, "element vertex")))
		return ((size_t)ft_atoi(file + ft_strlen("element vertex")));
	return (0);
}

static size_t	get_indices_count(const char *file)
{
	size_t	face_count;
	size_t	indices_count;
	size_t	i;

	if ((file = ft_strstr(file, "element face")))
		face_count = (size_t)ft_atoi(file + ft_strlen("element face"));
	else
		return (0);
	i = 0;
	indices_count = 0;
	while (i < face_count)
		indices_count += ft_atoi(ft_getline(file, ft_strcount(file, '\n')
			- face_count + i++));
	return (indices_count);
}

#include <stdio.h>

t_mesh	*parse_ply(const char *path)
{
	char	*file;
	t_mesh	*mesh;
	size_t	vertex_count;
	size_t	indices_count;
	size_t	i;

	if (!(file = get_file(path)))
		return (throw_error());
	if (!ft_strstr(file, "property float x\nproperty float y\nproperty float "
		"z\nproperty uchar red\nproperty uchar green\nproperty uchar blue")
		|| !(vertex_count = get_vertex_count(file))
		|| !(indices_count = get_indices_count(file)))
		return (throw_error_str("incorrect ply format"));
	printf("%lu %lu\n", vertex_count, indices_count);
	mesh = new_mesh(vertex_count, indices_count);
	file = ft_strstr(file, "end_header") + ft_strlen("end_header") + 1;
	i = 0;
	while (i < vertex_count)
	{
		mesh->vertices[i].x = ft_atof(file);
		while (!ft_isspace(*file))
			file++;
		mesh->vertices[i].y = ft_atof(++file);
		while (!ft_isspace(*file))
			file++;
		mesh->vertices[i].z = ft_atof(++file);
		while (!ft_isspace(*file))
			file++;
		printf("%s\n", file);
		mesh->colors[i].r = ft_atoi(++file) / 255.0f;
		while (!ft_isspace(*file))
			file++;
		printf("lol%s\n", file);
		mesh->colors[i].g = ft_atoi(++file) / 255.0f;
		while (!ft_isspace(*file))
			file++;
		mesh->colors[i].b = ft_atoi(++file) / 255.0f;
		printf("%f %f %f %f %f %f\n", mesh->vertices[i].x, mesh->vertices[i].y,
			mesh->vertices[i].z, mesh->colors[i].r, mesh->colors[i].g,
			mesh->colors[i].b);
		i++;
	}
	return (NULL);
}
