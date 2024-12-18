/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:23:45 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/16 23:42:23 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>


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

	put_str("sa\n");
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

	put_str("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);

	put_str("ss\n");
}
