/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:44:21 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/15 00:04:27 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_numbers(t_numbers *numbers)
{
	while (numbers)
	{
		printf("%d\n", numbers->number);
		numbers = numbers->next;
	}
}
