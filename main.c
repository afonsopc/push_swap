/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:55:24 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/20 10:15:39 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 3 - ft_strtoi - number too large (negative or positive)
// 4 - ft_strlen - NULL param
// 5 - numbers_append - NULL param
// 6 - ft_strtoi - NULL param
// 8 - numbers_find - NULL param
// 9 - parse_args - duplicate arguments
// 10 - ft_strtoi - string still has content after numbers
// 11 - swap - NULL param
// 12 - push - NULL param
// 13 - numbers_append_start - NULL param
// 14 - numbers_last - NULL param
// 15 - rotate - NULL param
// 16 - reverse_rotate - NULL param
// 17 - numbers_size - NULL param
// 18 - get_max_number - NULL return
// 19 - is_numbers_ordered - NULL param
// 20 - ft_split - NULL param
// 21 - ft_split - Array allocation failure
// 22 - ft_split - Item allocation failure
// 23 - ft_strlcpy - NULL param
// 24 - numbers_min - NULL param

// write(1, "Hello push_swap! :)\n", 20);

int	main(int argc, char **argv)
{
	t_numbers	*a_stack;
	t_numbers	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	a_stack = parse_args(argc, argv);
	if (is_numbers_ordered(a_stack))
		return (0);
	radix_sort(&a_stack, &b_stack);
}
