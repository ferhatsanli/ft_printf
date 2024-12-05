/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:12:47 by fsanli            #+#    #+#             */
/*   Updated: 2024/11/01 19:23:15 by fsanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*addr;

	i = 0;
	addr = (void *)s;
	while (i < n)
	{
		if (addr[i] == (char)c)
			return (&addr[i]);
		i++;
	}
	return (NULL);
}
