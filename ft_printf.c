/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:59:26 by fsanli            #+#    #+#             */
/*   Updated: 2024/12/04 19:40:54 by fsanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>
#include <string.h>

static int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		chcount;
	char	*str;

	va_start(args, fmt);
	while (!(*fmt))
	{
		if (*fmt == '%')
			if (*(++fmt) == 'c')
				write(1, va_arg(args, char), 1);
			else if (*(fmt) == 's')
			{
				str = va_arg(args, char*);
				write(1, str, ft_strlen(str));
			}
			else if (*(fmt) == 'p')
			{

			}
	}
	return (0);
}
int	main(void)
{
	char	*s;
	char	*p;
	s = malloc(7);
	strcpy(s, "ferhat");
	p = s;
	printf("p:%p | s:%s\n", s, s);
	free(s);
	printf("after free:%s\n", p);
	return (0);
}
