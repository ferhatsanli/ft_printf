/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:59:26 by fsanli            #+#    #+#             */
/*   Updated: 2024/12/18 13:05:18 by fsanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static int	parser(char c, va_list args)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (c == 's')
		return (strwrite(va_arg(args, char *)));
	else if (c == 'p')
		return (addrwrite((uintptr_t)va_arg(args, void *), "0123456789abcdef"));
	else if (c == 'd' || c == 'i')
		return (decwrite(va_arg(args, int)));
	else if (c == 'x')
		return (hexwrite(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (hexwrite(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'u')
		return (uintwrite(va_arg(args, unsigned int)));
	else if (c == '%')
	{
		ft_putchar_fd(37, 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		len;

	len = 0;
	if (!fmt)
		return (0);
	va_start(args, fmt);
	while ((*fmt) != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			len += parser((char)(*fmt), args);
		}
		else
			len += write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
	return (len);
}
