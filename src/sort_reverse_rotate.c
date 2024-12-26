/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:25:36 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/26 21:41:18 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*first;

	first = *stack_a;
	*stack_a = first->prev;
	ft_putendl_fd("rra", STDOUT_FILENO);
}

void	rrb(t_stack **stack_b)
{
	t_stack	*first;

	first = *stack_b;
	*stack_b = first->prev;
	ft_putendl_fd("rrb", STDOUT_FILENO);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_putendl_fd("rrr", STDOUT_FILENO);
}
