/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:55:45 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/15 00:05:13 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

// TODO: TO REMOVE (DEBUG)
# include <stdio.h>

typedef struct s_numbers
{
	int					number;
	struct s_numbers	*next;
}	t_numbers;

void		panic(int code);
size_t		ft_strlen(char *s);
int			ft_strtoi(char *str);
void		*safe_malloc(int code, size_t size);
t_numbers	*numbers_new(int number);
void		numbers_append(t_numbers **lst, t_numbers *new);
t_numbers	*parse_args(int argc, char **argv);

void		print_numbers(t_numbers *numbers);

#endif