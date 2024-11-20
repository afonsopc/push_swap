/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:28:17 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/20 16:23:56 by afpachec         ###   ########.fr       */
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

int	bit_len(long number)
{
	int	len;

	len = 0;
	while (number >> len)
		len++;
	return (len);
}

void	normalize_numbers(t_numbers *stack)
{
	long		min;

	min = numbers_min(stack);
	while (min < 0 && stack)
	{
		stack->number = stack->number + -min;
		stack = stack->next;
	}
}

void	radix_sort(t_numbers **a_stack, t_numbers **b_stack)
{
	size_t	size;
	long	max_bit_len;
	int		i;

	normalize_numbers(a_stack[0]);
	max_bit_len = bit_len(get_max_number(a_stack[0])->number);
	i = 0;
	while (i < max_bit_len)
	{
		size = numbers_size(a_stack[0]);
		while (size--)
		{
			if ((a_stack[0]->number >> i) & 1)
				ra(a_stack);
			else
				pb(a_stack, b_stack);
		}
		while (numbers_size(b_stack[0]))
			pa(a_stack, b_stack);
		i++;
	}
}
