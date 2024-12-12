/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:07:59 by fsanli            #+#    #+#             */
/*   Updated: 2024/12/12 18:12:03 by fsanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	strwrite(char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}
int	decwrite(int n)
{
	int	len;

	len =  0;
	if (n == INT_MIN)
		return ((write(1, "-2147483648", 11)));
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		len++;
		n *= -1;
	}
	len += write(1, ft_itoa(n), ft_strlen(ft_itoa(n)));
	return (len);
}
int	uintwrite(unsigned int n)
{
	return (write(1, ft_itoa(n), ft_strlen(ft_itoa(n))));
}
