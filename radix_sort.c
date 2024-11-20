/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:28:17 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/20 01:06:33 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numbers	*get_max_number(t_numbers *stack)
{
	t_numbers	*max;

	max = NULL;
	while (stack)
	{
		if (!max || max->number < stack->number)
			max = stack;
		stack = stack->next;
	}
	if (!max)
		panic(18);
	return (max);
}

unsigned int	absolute(int number)
{
	unsigned int	n;

	n = number;
	if (number < 0)
		n = -number;
	return (n);
}

int	bit_len(int number)
{
	int	len;

	len = 0;
	while (absolute(number) >> len)
		len++;
	return (len);
}

void	radix_sort(t_numbers **a_stack, t_numbers **b_stack)
{
	size_t		size;
	int			max_bit_len;
	int			i;

	max_bit_len = bit_len(get_max_number(a_stack[0])->number);
	i = 0;
	while (i < max_bit_len && !is_numbers_ordered(a_stack[0]))
	{
		size = numbers_size(a_stack[0]);
		while (size-- && !is_numbers_ordered(a_stack[0]))
		{
			if ((absolute(a_stack[0]->number) >> i) & 1)
				ra(a_stack);
			else
				pb(a_stack, b_stack);
		}
		size = numbers_size(b_stack[0]);
		while (numbers_size(b_stack[0]))
			pa(a_stack, b_stack);
		i++;
	}
}
