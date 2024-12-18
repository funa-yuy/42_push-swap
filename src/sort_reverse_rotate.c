/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:25:36 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/16 23:42:23 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// OK
void	rra(t_stack **stack_a)
{
	t_stack	*first;

	first = *stack_a;
	*stack_a = first->prev;

	put_str("rra\n");
}

void	rrb(t_stack **stack_b)
{
	t_stack	*first;

	first = *stack_b;
	*stack_b = first->prev;
	put_str("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	put_str("rrr\n");
}
