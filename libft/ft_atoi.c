/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:24:28 by fsanli            #+#    #+#             */
/*   Updated: 2024/11/14 15:53:09 by fsanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == '\n' || c == ' ' || c == '\f' || c == '\t' || c == '\r'
		|| c == '\v');
}

static int	ft_check_overflow(int res, int sign, char digit)
{
	if (res > (INT_MAX - (digit - '0')) / 10)
	{
		if (sign == 1)
			return (INT_MAX);
		else
			return (INT_MIN);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		res;
	int		sign;
	int		overflow;
	size_t	i;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		overflow = ft_check_overflow(res, sign, nptr[i]);
		if (overflow)
			return (overflow);
		res = res * 10 + (nptr[i++] - '0');
	}
	return (res * sign);
}
