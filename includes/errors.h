/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freezee <freezee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:14:59 by freezee           #+#    #+#             */
/*   Updated: 2018/12/07 18:15:23 by freezee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

void	*throw_error(void);
void	*throw_error_str(const char *cause);
void	*throw_error_errno(int err);

#endif