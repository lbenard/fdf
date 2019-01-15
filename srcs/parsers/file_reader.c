/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:53:09 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/15 18:10:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

char	*get_file(const char *path)
{
	int		fd;
	char	*file;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	ssize_t	rd;

	if (!path)
		return (throw_error_str("file_reader: NULL path."));
	if ((fd = open(path, O_RDONLY)) < 0 || read(fd, NULL, 0) < 0)
		return (throw_error());
	file = NULL;
	while ((rd = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rd] = 0;
		tmp = file;
		if (file)
			file = ft_strjoin(file, buffer);
		else
			file = ft_strdup(buffer);
		if (tmp)
			free(tmp);
	}
	close(fd);
	return (file);
}
