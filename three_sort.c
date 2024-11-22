/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:37:49 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/22 00:07:59 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_highest(long index, t_numbers *numbers)
{
	return ((numbers->index < index)
		+ (numbers->next->index < index)
		+ (numbers->next->next->index < index) >= 2);
}

void	three_sort(t_numbers **a_stack)
{
	if (is_highest(a_stack[0]->index, a_stack[0]))
		ra(a_stack);
	else if (is_highest(a_stack[0]->next->index, a_stack[0]))
		rra(a_stack);
	if (a_stack[0]->index > a_stack[0]->next->index)
		sa(a_stack);
}
