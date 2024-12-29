/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:19:38 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/29 22:17:59 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_4size(t_stack **stack_a, t_stack **stack_b)
{
	size_t	min;

	min = find_min_node(*stack_a);
	sort_4size_pb(stack_a, stack_b, min);
	sort_3size(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5size(t_stack **stack_a, t_stack **stack_b)
{
	size_t	min;

	min = find_min_node(*stack_a);
	sort_5size_pb(stack_a, stack_b, min);
	min = find_min_node(*stack_a);
	sort_4size_pb(stack_a, stack_b, min);
	sort_3size(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_short(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) == 2)
		sa(stack_a);
	else if (ft_stacksize(*stack_a) == 3)
		sort_3size(stack_a);
	else if (ft_stacksize(*stack_a) == 4)
		sort_4size(stack_a, stack_b);
	else if (ft_stacksize(*stack_a) == 5)
		sort_5size(stack_a, stack_b);
}
