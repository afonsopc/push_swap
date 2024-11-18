/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:24:48 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/18 11:00:15 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_numbers	*numbers_new(int number)
{
	t_numbers	*new;

	new = safe_malloc(5, sizeof(t_numbers));
	new->next = NULL;
	new->number = number;
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
	t_numbers	*curr;

	if (!numbers || !new)
		panic(5);
	if (!numbers[0])
	{
		numbers[0] = new;
		return ;
	}
	numbers_last(numbers[0])->next = new;
}

void	numbers_append_start(t_numbers **numbers, t_numbers *new)
{
	if (!numbers || !new)
		panic(13);
	if (numbers[0])
		new->next = numbers[0];
	numbers[0] = new;
}

t_numbers	*numbers_find(t_numbers *numbers, int number)
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
