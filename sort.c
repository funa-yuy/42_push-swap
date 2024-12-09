/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:09:46 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/09 23:01:32 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// OKstack_aの先頭ノードをstack_bの先頭に移動
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (*stack_a == NULL)
		exit (1);
	node = *stack_a;
	// stack_aから取り外し
	if (node->next == node) // stack_aに1つのノードしかない場合
	{
		*stack_a = NULL;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*stack_a = node->next;
	}

	if (*stack_b == NULL)
	{
		*stack_b = node;
		node->prev = node;
		node->next = node;
	}
	else
	{
		node->next = *stack_b;
		node->prev = (*stack_b)->prev;
		(*stack_b)->prev->next = node;
		(*stack_b)->prev = node;
		*stack_b = node;
	}
}

// stack_bの先頭ノードをstack_aの先頭に移動
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (*stack_b == NULL)
		exit (1);
	node = *stack_b;
	// stack_bから取り外し
	if (node->next == node) // stack_bに1つのノードしかない場合
	{
		*stack_b = NULL;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*stack_b = node->next;
	}
	// stack_aに挿入
	if (*stack_a == NULL)
	{
		*stack_a = node;
		node->prev = node;
		node->next = node;
	}
	else
	{
		node->next = *stack_a;
		node->prev = (*stack_a)->prev;
		(*stack_a)->prev->next = node;
		(*stack_a)->prev = node;
		*stack_a = node;
	}
}

// stack_aの先頭2つのノードを交換
void	sa(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_a == NULL || (*stack_a)->next == *stack_a)
		exit (1);
	first = *stack_a;
	second = first->next;

	// リンクの更新
	first->prev->next = second;
	second->prev = first->prev;
	first->next = second->next;
	second->next->prev = first;
	first->prev = second;
	second->next = first;

	*stack_a = second;
}

// stack_bの先頭2つのノードを交換
void	sb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_b == NULL || (*stack_b)->next == *stack_b)
		exit (1);
	first = *stack_b;
	second = first->next;

	// リンクの更新
	first->prev->next = second;
	second->prev = first->prev;
	first->next = second->next;
	second->next->prev = first;
	first->prev = second;
	second->next = first;

	*stack_b = second;
}

// OK
void	ra(t_stack **stack_a)
{
	t_stack	*first;

	first = *stack_a;
	*stack_a = first->next;
}

// OK
void	rra(t_stack **stack_a)
{
	t_stack	*first;

	first = *stack_a;
	*stack_a = first->prev;
}
