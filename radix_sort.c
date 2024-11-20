/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:28:17 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/20 23:18:52 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numbers	*get_max_number(t_numbers *stack)
{
	t_numbers	*max;

	max = NULL;
	while (stack)
	{
		if (!max || max->index < stack->index)
			max = stack;
		stack = stack->next;
	}
	if (!max)
		panic(18);
	return (max);
}

void	radix_sort(t_numbers **a_stack, t_numbers **b_stack)
{
	size_t	size;
	int		max_bit_len;
	int		i;

	size = get_max_number(a_stack[0])->index;
	max_bit_len = 0;
	while (size >> max_bit_len)
		max_bit_len++;
	i = 0;
	while (i < max_bit_len && !is_numbers_ordered(a_stack[0]))
	{
		size = numbers_size(a_stack[0]);
		while (size--)
		{
			if ((a_stack[0]->index >> i) & 1)
				ra(a_stack);
			else
				pb(a_stack, b_stack);
		}
		while (numbers_size(b_stack[0]))
			pa(a_stack, b_stack);
		i++;
	}
}
