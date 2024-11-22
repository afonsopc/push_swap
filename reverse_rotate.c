/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:32:30 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/21 21:24:14 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_numbers **stack)
{
	t_numbers	*last;
	t_numbers	*second_last;

	if (!stack)
		panic(16);
	if (!stack[0] || !stack[0]->next)
		return ;
	second_last = stack[0];
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack[0];
	stack[0] = last;
}

void	rra(t_numbers **a_stack)
{
	reverse_rotate(a_stack);
	write(1, "rra\n", 4);
}

void	rrb(t_numbers **b_stack)
{
	reverse_rotate(b_stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_numbers **a_stack, t_numbers **b_stack)
{
	reverse_rotate(a_stack);
	reverse_rotate(b_stack);
	write(1, "rrr\n", 4);
}
