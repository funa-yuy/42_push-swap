/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:35:16 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/26 20:37:20 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ascend_or_descend(t_stack **s_src, t_stack **s_dst, int check)
{
	int	first;
	int	second;
	int	last;
	int	target;

	first = (*s_src)->nbr;
	second = (*s_src)->next->nbr;
	last = (*s_src)->prev->nbr;
	target = (*s_dst)->nbr;

	if (target > first && target > second && target > last)
		return (1);
	else if (target < first && target < second && target < last)
		return (2);
	return (check);
}

void	marge_sort_atob(t_stack **stack_a, t_stack **stack_b)
{
	int	check;

	check = 1;
	while (*stack_a != NULL)
	{
		if ((*stack_a) == (*stack_a)->next)
		{
			pb(stack_a, stack_b);
			break ;
		}
		check = ascend_or_descend(stack_a, stack_b, check);

		if (check == 1)
			marge_descend_atob(stack_a, stack_b);
		else if (check == 2)
			marge_ascend_atob(stack_a, stack_b);

		if (*stack_a == NULL)
			break ;
	}
}

void	marge_sort_btoa(t_stack **stack_a, t_stack **stack_b)
{
	int	check;

	check = 1;
	while (*stack_b != NULL)
	{
		if ((*stack_b) == (*stack_b)->next)
		{
			pa(stack_a, stack_b);
			break ;
		}
		check = ascend_or_descend(stack_b, stack_a, check);

		if (check == 1)
			marge_descend_btoa(stack_a, stack_b);
		else if (check == 2)
			marge_ascend_btoa(stack_a, stack_b);

		if (*stack_b == NULL)
			break ;
	}
}
