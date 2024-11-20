/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:24:48 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/20 22:46:32 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numbers	*numbers_new(long number)
{
	t_numbers	*new;

	new = safe_malloc(5, sizeof(t_numbers));
	new->next = NULL;
	new->number = number;
	new->index = 0;
	return (new);
}

t_numbers	*numbers_last(t_numbers *numbers)
{
	if (!numbers)
		panic(14);
	while (numbers->next)
		numbers = numbers->next;
	return (numbers);
}

void	numbers_append(t_numbers **numbers, t_numbers *new)
{
	if (!numbers || !new)
		panic(5);
	if (!numbers[0])
		numbers[0] = new;
	else
		numbers_last(numbers[0])->next = new;
	numbers_update_indexes(numbers[0]);
}

void	numbers_append_start(t_numbers **numbers, t_numbers *new)
{
	if (!numbers || !new)
		panic(13);
	if (numbers[0])
		new->next = numbers[0];
	numbers[0] = new;
	numbers_update_indexes(numbers[0]);
}

t_numbers	*numbers_find(t_numbers *numbers, long number)
{
	if (!numbers)
		panic(8);
	while (numbers)
	{
		if (numbers->number == number)
			return (numbers);
		numbers = numbers->next;
	}
	return (NULL);
}
