/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:05:13 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/10 19:30:44 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	marge_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	first = *stack_a;
	second = first -> next;
	last = first -> prev;

	if (first >= second && first >= last)
	{
		pb(stack_a, stack_b);
	}
	else if (second >= first && second >= last)
	{
		sa(stack_a);//raでもよき？
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	marge_operation(t_stack **stack_a, t_stack **stack_b)
{
	int	first;
	int	second;
	int	last;
	int	b_first;

	while (*stack_a != NULL)
	{
		first = (*stack_a) -> nbr;
		second = (*stack_a) -> next -> nbr;
		last = (*stack_a) -> prev -> nbr;
		b_first = (*stack_b) -> nbr;

		if ((b_first - first >= 0) && ((b_first - second < 0) || b_first - first <= b_first - second) && ((b_first - last < 0) || b_first - first <= b_first - last))
		{
			pb(stack_a, stack_b);
		}
		else if ((b_first - second >= 0) && ((b_first - first < 0) || b_first - second <= b_first - first) && ((b_first - last < 0) || b_first - second <= b_first - last))
		{
			sa(stack_a);//raでもよき？
			pb(stack_a, stack_b);
		}
		else  if ((b_first - last >= 0) && ((b_first - first < 0) || b_first - last <= b_first - first) && ((b_first - second < 0) || b_first - last <= b_first - second))
		{
			rra(stack_a);
			pb(stack_a, stack_b);
		}
		else if ((b_first - first < 0) && ((b_first - second >= 0) || b_first - first >= b_first - second) && ((b_first - last < 0) || b_first - first >= b_first - last))
		{
			pb(stack_a, stack_b);
		}
		else if ((b_first - second < 0) && ((b_first - first >= 0) || b_first - second >= b_first - first) && ((b_first - last >= 0) || b_first - second >= b_first - last))
		{
			sa(stack_a);//raでもよき？
			pb(stack_a, stack_b);
		}
		else  if ((b_first - last < 0) && ((b_first - first >= 0) || b_first - last >= b_first - first) && ((b_first - second >= 0) || b_first - last >= b_first - second))
		{
			rra(stack_a);
			pb(stack_a, stack_b);
		}
	}
}

