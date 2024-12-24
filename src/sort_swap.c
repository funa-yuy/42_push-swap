/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:23:45 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/24 13:15:50 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_a == NULL || (*stack_a)->next == *stack_a)
		exit (1);
	first = *stack_a;
	second = first->next;

	first->prev->next = second;
	second->prev = first->prev;
	first->next = second->next;
	second->next->prev = first;
	first->prev = second;
	second->next = first;

	*stack_a = second;

	ft_putendl_fd("sa", STDOUT_FILENO);
}

void	sb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_b == NULL || (*stack_b)->next == *stack_b)
		exit (1);
	first = *stack_b;
	second = first->next;

	first->prev->next = second;
	second->prev = first->prev;
	first->next = second->next;
	second->next->prev = first;
	first->prev = second;
	second->next = first;

	*stack_b = second;

	ft_putendl_fd("sb", STDOUT_FILENO);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);

	ft_putendl_fd("ss", STDOUT_FILENO);
}
