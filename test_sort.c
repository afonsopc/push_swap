/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:12:32 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/18 23:55:41 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_numbers **a_stack, t_numbers **b_stack)
{
	t_numbers	*a_curr;
	t_numbers	*curr_highest;

	a_curr = a_stack[0];
	curr_highest = NULL;
	while (a_curr)
	{
		if (!curr_highest)
			curr_highest = a_curr;
		else if (a_curr->number > curr_highest->number)
			curr_highest = a_curr;
		a_curr = a_curr->next;
	}
	while (a_stack[0] != curr_highest)
		ra(a_stack);
	pb(a_stack, b_stack);
}

void	test_sort(t_numbers **a_stack, t_numbers **b_stack)
{
	size_t	length;

	length = numbers_size(a_stack[0]);
	while (length--)
		sort(a_stack, b_stack);
	length = numbers_size(b_stack[0]);
	while (length--)
	{
		rrb(b_stack);
		pa(a_stack, b_stack);
	}
}
