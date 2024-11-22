/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_five_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:08:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/22 14:27:32 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	real_four_five_sort(t_numbers **a_stack, t_numbers **b_stack)
{
	if (numbers_size(a_stack[0]) == 5)
		pb(a_stack, b_stack);
	(pb(a_stack, b_stack), three_sort(a_stack));
	while (b_stack[0])
	{
		if (b_stack[0]->number < a_stack[0]->number)
			pa(a_stack, b_stack);
		else if (b_stack[0]->number < a_stack[0]->next->number)
			(ra(a_stack), pa(a_stack, b_stack), rra(a_stack));
		else if (b_stack[0]->number < a_stack[0]->next->next->number)
		{
			if (numbers_size(a_stack[0]) == 4)
				rra(a_stack);
			(rra(a_stack), pa(a_stack, b_stack), ra(a_stack), ra(a_stack));
			if (numbers_size(a_stack[0]) == 5)
				ra(a_stack);
		}
		else if (numbers_size(a_stack[0]) == 4
			&& b_stack[0]->number < a_stack[0]->next->next->next->number)
			(rra(a_stack), pa(a_stack, b_stack), ra(a_stack), ra(a_stack));
		else
			(pa(a_stack, b_stack), ra(a_stack));
	}
}

#include <stdio.h>

void	specific_cases(t_numbers **a, t_numbers **b)
{
	int	fourth;
	int	fifth;

	fourth = a[0]->next->next->next->number;
	fifth = a[0]->next->next->next->next->number;
	if (a[0]->index != 2
		|| (a[0]->next->index != 3 && a[0]->next->index != 1))
		return ;
	if (a[0]->next->next->number == 2 && fourth == 1 && fifth == 5)
		(pb(a, b), pb(a, b), sa(a), rra(a),
			pa(a, b), pa(a, b), ra(a), ra(a), ra(a));
	if (a[0]->next->next->number == 5 && fourth == 1 && fifth == 2)
		(ra(a), ra(a), ra(a));
	if (a[0]->next->next->number == 1 && fourth == 5 && fifth == 2)
		(ra(a), ra(a), sa(a), ra(a));
	if (a[0]->next->next->number == 1 && fourth == 5 && fifth == 4)
		(pb(a, b), rra(a), pb(a, b), rra(a),
			pa(a, b), pa(a, b), rra(a), rra(a), sa(a));
	if (a[0]->next->next->number == 5 && fourth == 2 && fifth == 1)
		(rra(a), rra(a), sa(a));
	if (a[0]->next->next->number == 2 && fourth == 5 && fifth == 1)
		(pb(a, b), pb(a, b), rra(a), rra(a),
			pa(a, b), pa(a, b), ra(a), ra(a), ra(a));
	if (a[0]->next->next->number == 5 && fourth == 4 && fifth == 1)
		(sa(a), rra(a), rra(a), rra(a), sa(a), ra(a), ra(a));
}

void	four_five_sort(t_numbers **a_stack, t_numbers **b_stack)
{
	if (numbers_size(a_stack[0]) == 5)
		specific_cases(a_stack, b_stack);
	if (!is_numbers_ordered(a_stack[0]))
		real_four_five_sort(a_stack, b_stack);
}
