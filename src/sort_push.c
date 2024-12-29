/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:09:46 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/30 02:40:18 by miyuu            ###   ########.fr       */
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
