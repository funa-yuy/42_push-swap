/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 04:09:55 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/26 21:37:41 by miyuu            ###   ########.fr       */
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

// t_stack	*create_stack(int argc, char **argv)
// {
// 	t_stack	*s_new;
// 	t_stack	*tmp;
// 	t_stack	*node;
// 	int		i;

// 	s_new = NULL;
// 	s_new = (t_stack *)malloc(sizeof(t_stack));
// 	if (s_new == NULL)
// 		return (NULL);
// 	s_new -> nbr = ps_atoi(argv[1]);

// 	if (argc == 2)
// 	{
// 		s_new -> prev = s_new;
// 		s_new -> next = s_new;
// 		return (s_new);
// 	}
// 	else
// 	{
// 		tmp = s_new;
// 		i = 2;
// 		while (argc - 1 >= i)
// 		{
// 			node = (t_stack *)malloc(sizeof(t_stack));
// 			if (node == NULL)
// 				return (NULL);
// 			node -> prev = tmp;
// 			tmp -> next = node;
// 			node -> nbr = ps_atoi(argv[i]);
// 			tmp = tmp -> next;
// 			i++;
// 		}
// 		s_new -> prev = node;
// 		node -> next = s_new;
// 	}
// 	return (s_new);
// }
