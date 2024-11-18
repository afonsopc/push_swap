/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:21:39 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/18 11:00:08 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_both_cases(int *argc, char ***argv)
{
	int		i;
	char	**split_argv;

	if (*argc == 2)
	{
		split_argv = ft_split((*argv)[1], ' ');
		i = 0;
		while (split_argv[i])
			i++;
		*argc = i;
		*argv = split_argv;
	}
	else
	{
		*argv = *argv + 1;
		*argc = *argc - 1;
	}
}

t_numbers	*parse_args(int argc, char **argv)
{
	int			i;
	int			number;
	t_numbers	*numbers;
	t_numbers	*curr;

	handle_both_cases(&argc, &argv);
	i = 0;
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