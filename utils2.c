/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:44:09 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/19 21:12:23 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(char **strs, size_t i)
{
	while (i--)
		free(strs[i]);
	free(strs);
}

static int	count_items(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		panic(23);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static int	split(char const *s, char c, char **strs)
{
	size_t		i;
	const char	*start;

	i = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		start = s;
		while (*s && *s != c)
			s++;
		strs[i] = malloc(s - start + 1);
		if (!strs[i])
			return (free_all(strs, i), 0);
		ft_strlcpy(strs[i], start, s - start + 1);
		while (*s && *s == c)
			s++;
		i++;
	}
	strs[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**strs;

	if (!s)
		panic(20);
	strs = safe_malloc(21, (count_items(s, c) + 1) * sizeof(char *));
	if (!split(s, c, strs))
		panic(22);
	return (strs);
}
