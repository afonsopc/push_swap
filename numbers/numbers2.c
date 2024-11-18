/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:24:48 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/18 11:00:19 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	numbers_size(t_numbers *numbers)
{
	size_t	counter;

	if (!numbers)
		panic(14);
	counter = 1;
	while (counter++ && numbers->next)
		numbers = numbers->next;
	return (counter - 1);
}
