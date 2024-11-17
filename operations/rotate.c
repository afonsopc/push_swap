/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:32:30 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/17 17:11:13 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void	rotate(t_numbers **stack)
{
	t_numbers	*tmp;

	if (!stack)
		panic(15);
	if (!stack[0] || !stack[0]->next)
		return ;
	tmp = stack[0];
	numbers_last(tmp)->next = tmp;
	stack[0] = tmp->next;
	tmp->next = NULL;
}

void	ra(t_numbers **a_stack)
{
	rotate(a_stack);
	write(1, "ra\n", 3);
}

void	rb(t_numbers **b_stack)
{
	rotate(b_stack);
	write(1, "rb\n", 3);
}

void	rr(t_numbers **a_stack, t_numbers **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
	write(1, "rr\n", 3);
}
