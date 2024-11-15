/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:20:17 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/14 23:48:52 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		panic(4);
	while (s[count])
		count++;
	return (count);
}

int	ft_strtoi(char *str)
{
	int		sign;
	long	num;

	if (ft_strlen(str) > 11)
		panic(2);
	sign = 1;
	num = 0;
	if ((*str == '-' || *str == '+') && *str++ == '-')
		sign = -1;
	while (*str >= '0' && *str <= '9')
		num = (num * 10) + ((*str++ - '0'));
	if ((sign == 1 && num > 2147483647) || (sign == -1 && num > 2147483648))
		panic(3);
	return (num * sign);
}
