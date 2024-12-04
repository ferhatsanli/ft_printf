/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:36:41 by fsanli            #+#    #+#             */
/*   Updated: 2024/12/04 19:40:17 by fsanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

// ft_printf
int		ft_printf(const char *fmt, ...);

// parselib
void	writechar(char *c);

// parser
void	parse(char placeholder, void *ptr);

#endif
