/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:55:24 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/14 23:56:42 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 2 - ft_strtoi - string too long
// 3 - ft_strtoi - number too large (negative or positive)
// 4 - ft_strlen - NULL param
// 5 - numbers_append - NULL param

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_numbers	*numbers;

	numbers = parse_args(argc, argv);
	print_numbers(numbers);
	write(1, "Hello push_swap! :)\n", 20);
}
