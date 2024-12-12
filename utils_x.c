/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:25:45 by fsanli            #+#    #+#             */
/*   Updated: 2024/12/12 19:00:03 by fsanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static int	lendigit(unsigned long long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	addrwrite(uintptr_t addr, char *dict)
{
	if (addr == 0)
		return (write(1, "(nil)", 5));
	if (addr >= 16)
		addrwrite(addr / 16, dict);
	else
		write(1, "0x", 2);
	ft_putchar_fd(dict[addr % 16], 1);
	return (lendigit(addr) + 2);
}

int	hexwrite(unsigned int n, char *dict)
{
	if (n >= 16)
		hexwrite(n / 16, dict);
	ft_putchar_fd(dict[n % 16], 1);
	return (lendigit(n));
}
