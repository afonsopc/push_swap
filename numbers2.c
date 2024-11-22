/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:24:48 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/22 16:03:42 by afpachec         ###   ########.fr       */
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

void	numbers_update_indexes(t_numbers *numbers)
{
	t_numbers	*curr1;
	t_numbers	*curr2;
	long		index;

	curr1 = numbers;
	while (curr1)
	{
		curr2 = numbers;
		index = 0;
		while (curr2)
		{
			if (curr2->number < curr1->number)
				index++;
			curr2 = curr2->next;
		}
		curr1->index = index;
		curr1 = curr1->next;
	}
}

void	delete_all_numbers(t_numbers *numbers)
{
	t_numbers	*next;

	while (numbers)
	{
		next = numbers->next;
		free(numbers);
		numbers = next;
	}
}
