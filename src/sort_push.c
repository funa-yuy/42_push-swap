/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:09:46 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/25 03:32:04 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	remove_targe_node(t_stack **s_dst, t_stack *node)
{
	if (*s_dst == NULL)
		exit (1);
	node = *s_dst;

	if (node->next == node)
		*s_dst = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*s_dst = node->next;
	}
}

void	push_to_dst(t_stack **s_src, t_stack *node)
{
	if (*s_src == NULL)
	{
		*s_src = node;
		node->prev = node;
		node->next = node;
	}
	else
	{
		node->next = *s_src;
		node->prev = (*s_src)->prev;
		(*s_src)->prev->next = node;
		(*s_src)->prev = node;
		*s_src = node;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (*stack_a == NULL)
		exit (1);
	node = *stack_a;

	remove_targe_node(stack_a, node);
	push_to_dst(stack_b, node);
	ft_putendl_fd("pb", STDOUT_FILENO);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (*stack_b == NULL)
		exit (1);
	node = *stack_b;

	remove_targe_node(stack_b, node);
	push_to_dst(stack_a, node);
	ft_putendl_fd("pa", STDOUT_FILENO);
}


// void	pb(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*node;

// 	if (*stack_a == NULL)
// 		exit (1);
// 	node = *stack_a;

// 	if (node->next == node)
// 		*stack_a = NULL;
// 	else
// 	{
// 		node->prev->next = node->next;
// 		node->next->prev = node->prev;
// 		*stack_a = node->next;
// 	}

// 	if (*stack_b == NULL)
// 	{
// 		*stack_b = node;
// 		node->prev = node;
// 		node->next = node;
// 	}
// 	else
// 	{
// 		node->next = *stack_b;
// 		node->prev = (*stack_b)->prev;
// 		(*stack_b)->prev->next = node;
// 		(*stack_b)->prev = node;
// 		*stack_b = node;
// 	}
// 	ft_putendl_fd("pb", STDOUT_FILENO);
// }

// void	pa(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*node;

// 	if (*stack_b == NULL)
// 		exit (1);
// 	node = *stack_b;
// 	if (node->next == node)
// 		*stack_b = NULL;
// 	else
// 	{
// 		node->prev->next = node->next;
// 		node->next->prev = node->prev;
// 		*stack_b = node->next;
// 	}
// 	// stack_aに挿入
// 	if (*stack_a == NULL)
// 	{
// 		*stack_a = node;
// 		node->prev = node;
// 		node->next = node;
// 	}
// 	else
// 	{
// 		node->next = *stack_a;
// 		node->prev = (*stack_a)->prev;
// 		(*stack_a)->prev->next = node;
// 		(*stack_a)->prev = node;
// 		*stack_a = node;
// 	}
// 	ft_putendl_fd("pa", STDOUT_FILENO);
// }
