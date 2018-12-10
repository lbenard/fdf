/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:56:09 by lbenard           #+#    #+#             */
/*   Updated: 2018/12/10 00:35:33 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "mesh.h"
t_isize	get_map_size(const char *map_path);
t_mesh	*parse_map(const char *path);

#endif
