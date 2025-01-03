/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:40:24 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/28 13:30:24 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	has_dup(t_stack **stack)
{
	t_stack	*now_nbr;
	t_stack	*next_nbr;

	now_nbr = *stack;
	while (now_nbr -> next != *stack)
	{
		next_nbr = now_nbr;
		while (next_nbr -> next != *stack)
		{
			next_nbr = next_nbr -> next;
			if (now_nbr -> nbr - next_nbr -> nbr == 0)
				return (true);
		}
		now_nbr = now_nbr -> next;
	}
	return (false);
}

int	is_intstr(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (ft_isdigit(*str) == false)
			return (false);
		str++;
	}
	return (true);
}

int	is_int(char *str)
{
	long int	li;

	if (is_intstr(str) == false)
		return (false);
	li = 0;
	li = ps_atoi(str);
	if (li > INT_MAX || li < INT_MIN)
		return (false);
	return (true);
}

int	error_check(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (is_int(argv[i]) == false)
			return (-1);
		i++;
	}
	return (0);
}
