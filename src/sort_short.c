/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:19:38 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/29 22:11:50 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	find_min_node(t_stack *stack)
{
	t_stack	*current;
	int		min_nbr;
	size_t	pos;
	size_t	min_pos;

	if (!stack)
		return (0);
	current = stack;
	min_nbr = current->nbr;
	pos = 1;
	min_pos = 1;
	while (current -> next != stack)
	{
		current = current -> next;
		pos++;
		if (current -> nbr < min_nbr)
		{
			min_nbr = current -> nbr;
			min_pos = pos;
		}
	}
	return (min_pos);
}

void	sort_4size_pb(t_stack **stack_a, t_stack **stack_b, size_t min)
{
	if (min == 1)
		pb(stack_a, stack_b);
	else if (min == 2)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (min == 3)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (min == 4)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	sort_5size_pb(t_stack **stack_a, t_stack **stack_b, size_t min)
{
	if (min == 1)
		pb(stack_a, stack_b);
	else if (min == 2)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (min == 3)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (min == 4)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (min == 5)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}
