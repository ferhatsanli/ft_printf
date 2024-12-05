/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:59:26 by fsanli            #+#    #+#             */
/*   Updated: 2024/12/05 21:19:46 by fsanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdio.h>
#include <string.h>

static char	*hextodec(uintptr_t addr, int capital)
{
	char	*res;
	short	i;
	char	*dict;

	i = 0;
	res = (char *)malloc(sizeof(char) * 17);
	if (capital == 0)
		dict = "0123456789abcdef";
	else
		dict = "0123456789ABCDEF";
	while (i < 16)
	{
		res[i++] = dict[addr % 16];
		addr /= 16;
	}
	return (res);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	void	*ptr;
	char	c;

	c = ' ';
	va_start(args, fmt);
	while ((*fmt) != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
			}
			else if (*(fmt) == 's')
			{
				ptr = va_arg(args, char *);
				write(1, ptr, ft_strlen((char *)ptr));
			}
			else if (*(fmt) == 'p')
			{
				ptr = (void *)hextodec(va_arg(args, void *), 0);
				write(1, (char *)ptr, 16);
				free(ptr);
			}
		}
		fmt++;
	}
	return (0);
}
int	main(void)
{
	char	a[] = "ferhat";
	ft_printf("%p", &a);
	return (0);
}
