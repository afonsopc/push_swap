/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:28:44 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/18 11:00:12 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	panic(int code)
{
	write(2, "Error\n", 6);
	exit(code);
}

void	*safe_malloc(int code, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		panic(code);
	return (ptr);
}
