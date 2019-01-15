/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:56:09 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/15 18:23:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "mesh.h"

char	*get_file(const char *path);
t_isize	get_map_size(const char *map_path);
t_mesh	*parse_fdf(const char *path);
t_mesh	*parse_ply(const char *path);

#endif
