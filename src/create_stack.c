/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 04:09:55 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/30 01:43:24 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_node(int nbr)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->nbr = nbr;
	node->prev = node;
	node->next = node;
	return (node);
}

void	add_node_to_stack(t_stack **stack, t_stack *new_node)
{
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		new_node->prev = (*stack)->prev;
		new_node->next = *stack;
		(*stack)->prev->next = new_node;
		(*stack)->prev = new_node;
	}
}

t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		new_node = create_node(ps_atoi(argv[i]));
		if (new_node == NULL)
			return (NULL);
		add_node_to_stack(&stack, new_node);
		i++;
	}
	return (stack);
}
