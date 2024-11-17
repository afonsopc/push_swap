/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:21:39 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/15 21:28:51 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numbers	*parse_args(int argc, char **argv)
{
	int			i;
	int			number;
	t_numbers	*numbers;
	t_numbers	*curr;

	i = 1;
	numbers = NULL;
	while (i < argc)
	{
		number = ft_strtoi(argv[i++]);
		if (numbers && numbers_find(numbers, number))
			panic(9);
		numbers_append(&numbers, numbers_new(number));
	}
	return (numbers);
}
