/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:23:45 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/30 02:40:34 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_top_two(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == *stack)
		exit (1);
	first = *stack;
	second = first->next;
	first->prev->next = second;
	second->prev = first->prev;
	first->next = second->next;
	second->next->prev = first;
	first->prev = second;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	swap_top_two(stack_a);
	ft_putendl_fd("sa", STDOUT_FILENO);
}

void	sb(t_stack **stack_b)
{
	swap_top_two(stack_b);
	ft_putendl_fd("sb", STDOUT_FILENO);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_putendl_fd("ss", STDOUT_FILENO);
}
