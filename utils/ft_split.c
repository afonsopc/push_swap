/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:44:09 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/18 11:00:24 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_all(char **strs, size_t index)
{
	while (index-- > 0)
		free(strs[index]);
	free(strs);
}

static int	count_items(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		i++;
	}
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen((char *)src);
	if (dstsize == 0)
		return (src_len);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
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
		{
			free_all(strs, i);
			return (0);
		}
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
		return (NULL);
	strs = malloc((count_items(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	if (!split(s, c, strs))
		return (NULL);
	return (strs);
}
