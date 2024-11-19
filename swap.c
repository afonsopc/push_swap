/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:08:11 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/18 23:55:41 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_numbers **stack)
{
	t_numbers	*tmp;

	if (!stack)
		panic(11);
	if (!stack[0] || !stack[0]->next)
		return ;
	tmp = stack[0]->next;
	stack[0]->next = tmp->next;
	tmp->next = stack[0];
	stack[0] = tmp;
}

void	sa(t_numbers **a_stack)
{
	swap(a_stack);
	write(1, "sa\n", 3);
}

void	sb(t_numbers **b_stack)
{
	swap(b_stack);
	write(1, "sb\n", 3);
}

void	ss(t_numbers **a_stack, t_numbers **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	write(1, "ss\n", 3);
}
