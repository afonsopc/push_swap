/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:55:39 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/17 15:31:23 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void	push(t_numbers **stack_src, t_numbers **stack_dst)
{
	t_numbers	*tmp;

	if (!stack_src || !stack_dst)
		panic(12);
	if (!stack_src[0])
		return ;
	tmp = stack_src[0];
	stack_src[0] = tmp->next;
	numbers_append_start(stack_dst, tmp);
}

void	pa(t_numbers **a_stack, t_numbers **b_stack)
{
	push(b_stack, a_stack);
	write(1, "pa\n", 3);
}

void	pb(t_numbers **a_stack, t_numbers **b_stack)
{
	push(a_stack, b_stack);
	write(1, "pb\n", 3);
}
