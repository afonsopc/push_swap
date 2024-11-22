/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_five_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:08:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/22 00:10:35 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	four_five_sort(t_numbers **a_stack, t_numbers **b_stack)
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
			(rra(a_stack), pa(a_stack, b_stack),
				ra(a_stack), ra(a_stack));
			if (numbers_size(a_stack[0]) == 5)
				ra(a_stack);
		}
		else if (numbers_size(a_stack[0]) == 4
			&& b_stack[0]->number < a_stack[0]->next->next->next->number)
			(rra(a_stack), pa(a_stack, b_stack),
				ra(a_stack), ra(a_stack));
		else
			(pa(a_stack, b_stack), ra(a_stack));
	}
}
