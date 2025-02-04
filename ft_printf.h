/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:36:41 by fsanli            #+#    #+#             */
/*   Updated: 2025/01/10 21:35:15 by fsanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	addrwrite(uintptr_t addr, char *dict);
int	hexwrite(unsigned int n, char *dict);
int	strwrite(char *s);
int	decwrite(int n);
int	uintwrite(unsigned int n);
void	test_u(void);

#endif
