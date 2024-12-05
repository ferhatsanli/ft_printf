/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:54:53 by fsanli            #+#    #+#             */
/*   Updated: 2024/11/11 21:46:34 by fsanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isthere(char target, const char *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(set);
	while (i < len)
	{
		if (target == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	start;
	size_t	end;
	char	*res;

	len = ft_strlen(s1);
	i = 0;
	if (!s1)
		return (NULL);
	if (!set || !*set)
		return (ft_strdup(s1));
	while (s1[i] && isthere(s1[i], set))
		i++;
	start = i;
	i = len;
	while (i > 1 && isthere(s1[i - 1], set))
		i--;
	end = i;
	res = ft_substr(s1, start, end - start);
	return (res);
}
