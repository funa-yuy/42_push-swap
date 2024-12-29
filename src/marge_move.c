/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marge_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:37:04 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/30 02:38:15 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	marge_descend_atob(t_stack **stack_a, t_stack **stack_b)
{
	int	first;
	int	second;
	int	last;
	int	b_first;
	int	diff;

	first = (*stack_a)->nbr;
	second = (*stack_a)->next->nbr;
	last = (*stack_a)->prev->nbr;
	b_first = (*stack_b)->nbr;
	diff = calc_diff_descend(b_first, first, second, last);
	if (diff == 0)
		pb(stack_a, stack_b);
	else if (diff == 1)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (diff == 2)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	marge_ascend_atob(t_stack **stack_a, t_stack **stack_b)
{
	int	first;
	int	second;
	int	last;
	int	b_first;
	int	diff;

	first = (*stack_a)->nbr;
	second = (*stack_a)->next->nbr;
	last = (*stack_a)->prev->nbr;
	b_first = (*stack_b)->nbr;
	diff = calc_diff_ascend(b_first, first, second, last);
	if (diff == 0)
		pb(stack_a, stack_b);
	else if (diff == 1)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (diff == 2)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	marge_descend_btoa(t_stack **stack_a, t_stack **stack_b)
{
	int	first;
	int	second;
	int	last;
	int	a_first;
	int	diff;

	first = (*stack_b)->nbr;
	second = (*stack_b)->next->nbr;
	last = (*stack_b)->prev->nbr;
	a_first = (*stack_a)->nbr;
	diff = calc_diff_descend(a_first, first, second, last);
	if (diff == 0)
		pa(stack_a, stack_b);
	else if (diff == 1)
	{
		sb(stack_b);
		pa(stack_a, stack_b);
	}
	else if (diff == 2)
	{
		rrb(stack_b);
		pa(stack_a, stack_b);
	}
}

void	marge_ascend_btoa(t_stack **stack_a, t_stack **stack_b)
{
	int	first;
	int	second;
	int	last;
	int	a_first;
	int	diff;

	first = (*stack_b)->nbr;
	second = (*stack_b)->next->nbr;
	last = (*stack_b)->prev->nbr;
	a_first = (*stack_a)->nbr;
	diff = calc_diff_ascend(a_first, first, second, last);
	if (diff == 0)
		pa(stack_a, stack_b);
	else if (diff == 1)
	{
		sb(stack_b);
		pa(stack_a, stack_b);
	}
	else if (diff == 2)
	{
		rrb(stack_b);
		pa(stack_a, stack_b);
	}
}
