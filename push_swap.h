/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:55:45 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/17 17:30:00 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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
t_numbers	*numbers_find(t_numbers *numbers, int number);
void		numbers_append_start(t_numbers **numbers, t_numbers *new);
t_numbers	*numbers_last(t_numbers *numbers);

void		sa(t_numbers **a_stack);
void		sb(t_numbers **b_stack);
void		ss(t_numbers **a_stack, t_numbers **b_stack);
void		pa(t_numbers **a_stack, t_numbers **b_stack);
void		pb(t_numbers **a_stack, t_numbers **b_stack);
void		ra(t_numbers **a_stack);
void		rb(t_numbers **b_stack);
void		rr(t_numbers **a_stack, t_numbers **b_stack);
void		rra(t_numbers **a_stack);
void		rrb(t_numbers **b_stack);
void		rrr(t_numbers **a_stack, t_numbers **b_stack);

#endif