/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:24:48 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/20 10:23:40 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	numbers_size(t_numbers *numbers)
{
	size_t	counter;

	if (!numbers)
		return (0);
	counter = 1;
	while (counter++ && numbers->next)
		numbers = numbers->next;
	return (counter - 1);
}

int	is_numbers_ordered(t_numbers *numbers)
{
	long	last;

	if (!numbers)
		panic(19);
	last = numbers->number;
	while (numbers)
	{
		if (last > numbers->number)
			return (0);
		last = numbers->number;
		numbers = numbers->next;
	}
	return (1);
}

long	numbers_min(t_numbers *numbers)
{
	long	min;

	if (!numbers)
		panic(24);
	min = numbers->number;
	while (numbers)
	{
		if (numbers->number < min)
			min = numbers->number;
		numbers = numbers->next;
	}
	return (min);
}
