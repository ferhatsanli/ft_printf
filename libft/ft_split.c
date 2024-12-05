/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:31:15 by fsanli            #+#    #+#             */
/*   Updated: 2024/11/06 23:30:32 by fsanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	clusterlen(const char *s, char d)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != d)
		len++;
	return (len);
}

static size_t	clusteramount(const char *s, char d)
{
	size_t	res;
	short	clusterkey;

	res = 0;
	clusterkey = 0;
	if (!s || !*s)
		return (0);
	while (*s)
	{
		if (*s != d && !clusterkey)
		{
			res++;
			clusterkey = 1;
		}
		else if (*s == d)
		{
			clusterkey = 0;
		}
		s++;
	}
	return (res);
}

static char	**freematrix(char **matrix, size_t lencl)
{
	while (lencl > 0)
	{
		lencl--;
		free(matrix[lencl]);
	}
	free(matrix);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	clen;
	size_t	icluster;

	icluster = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc((clusteramount(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		clen = clusterlen(s, c);
		if (clen > 0)
		{
			res[icluster] = ft_substr(s, 0, clen);
			if (!res[icluster++])
				return (freematrix(res, --icluster));
			s += clen;
		}
	}
	res[icluster] = NULL;
	return (res);
}
