/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:05:13 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/26 21:41:45 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	marge_first_atob(t_stack **stack_a, t_stack **stack_b)
{
	int	first;
	int	second;
	int	last;

	first = (*stack_a)-> nbr;
	second = (*stack_a)-> next-> nbr;
	last = (*stack_a)-> prev-> nbr;
	if (first >= second && first >= last)
	{
		pb(stack_a, stack_b);
	}
	else if (second >= first && second >= last)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	marge_first_btoa(t_stack **stack_a, t_stack **stack_b)
{
	int	first;
	int	second;
	int	last;

	first = (*stack_b)-> nbr;
	second = (*stack_b)-> next-> nbr;
	last = (*stack_b)-> prev-> nbr;
	if (first >= second && first >= last)
	{
		pa(stack_a, stack_b);
	}
	else if (second >= first && second >= last)
	{
		sb(stack_b);
		pa(stack_a, stack_b);
	}
	else
	{
		rrb(stack_b);
		pa(stack_a, stack_b);
	}
}

int	sort_check(t_stack *stack)
{
	t_stack	*now_nbr;
	t_stack	*next_nbr;

	now_nbr = stack;
	while (now_nbr -> next != stack)
	{
		next_nbr = now_nbr;
		while (next_nbr -> next != stack)
		{
			next_nbr = next_nbr -> next;
			if (now_nbr -> nbr > next_nbr -> nbr)
				return (0);
		}
		now_nbr = now_nbr -> next;
	}
	return (1);
}

void	marge_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	check;

	check = -1;
	while (check == -1)
	{
		if (*stack_a == NULL)
		{
			marge_first_btoa(stack_a, stack_b);
			marge_sort_btoa(stack_a, stack_b);
			if (sort_check(*stack_a) == 1)
				break ;
		}
		else if (*stack_b == NULL)
		{
			marge_first_atob(stack_a, stack_b);
			marge_sort_atob(stack_a, stack_b);
		}
	}
}
// メモ：else if (second >= first && second >= last)ないのsa・sbはra・rbでもよき？
