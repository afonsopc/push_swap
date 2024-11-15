/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:24:48 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/14 23:56:39 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numbers	*numbers_new(int number)
{
	t_numbers	*new;

	new = safe_malloc(5, sizeof(t_numbers));
	new->next = NULL;
	new->number = number;
	return (new);
}

void	numbers_append(t_numbers **lst, t_numbers *new)
{
	t_numbers	*curr;

	if (!lst || !new)
		panic(5);
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	curr = lst[0];
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}
