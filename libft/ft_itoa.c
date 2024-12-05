/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:55:00 by fsanli            #+#    #+#             */
/*   Updated: 2024/11/05 19:11:54 by fsanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digitcount(int n)
{
	size_t	res;
	int		nmb;

	res = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		res++;
	nmb = n;
	while (nmb != 0)
	{
		nmb /= 10;
		res++;
	}
	return (res);
}

static int	sign(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	dcount;
	int		i;
	int		nmb;

	nmb = n;
	dcount = digitcount(n);
	res = (char *)ft_calloc((dcount + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = dcount - 1;
	while (i >= 0)
	{
		if (i == 0 && sign(nmb) == -1)
			res[0] = '-';
		else
		{
			res[i] = (char)(sign(nmb) * (n % 10) + '0');
			n /= 10;
		}
		i--;
	}
	res[dcount] = '\0';
	return (res);
}
