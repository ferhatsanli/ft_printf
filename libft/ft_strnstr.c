/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:30:00 by fsanli            #+#    #+#             */
/*   Updated: 2024/11/05 19:07:10 by fsanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	score;
	size_t	len_little;

	i = 0;
	score = 0;
	len_little = ft_strlen(little);
	if (!len_little)
		return ((char *)big);
	while (i < len && big[i])
	{
		if (!(big[i] == little[score]))
			i = i - score + 1;
		score *= (big[i] == little[score]);
		score += (big[i] == little[score]);
		if (score == len_little)
			return ((char *)&big[i - len_little + 1]);
		i++;
	}
	return (NULL);
}
