/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:24:30 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/26 21:41:23 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*first;

	first = *stack_a;
	*stack_a = first->next;
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	rb(t_stack **stack_b)
{
	t_stack	*first;

	first = *stack_b;
	*stack_b = first->next;
	ft_putendl_fd("rb", STDOUT_FILENO);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_putendl_fd("rr", STDOUT_FILENO);
}
