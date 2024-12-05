/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:59:22 by fsanli            #+#    #+#             */
/*   Updated: 2024/11/06 19:08:01 by fsanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!n || dest == src)
		return (dest);
	if (src < dest)
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
