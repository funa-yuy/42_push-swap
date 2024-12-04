/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:28:57 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/04 23:27:31 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	// string s="123456789";
	t_stack	*stack_a;
	t_stack	stack_b;
//	struct s_stack	*stack_b;
	// int i = 1000;
	// int *pi = &i;
	// char *pc = &i;

	// *pi;
    // *pc;
	// *
	// char *pc = &c;
	// char string[6] = "aiueo";
	// char c = 'a';
	struct s_stack *p1,*p2,*p3;


	stack_a = (t_stack *)malloc(sizeof(t_stack));
		if (stack_a == NULL)
			return(1);
	stack_a -> nbr = atoi(argv[1]);
	stack_a -> prev = NULL;
	stack_a -> next = NULL;

	struct s_stack *tmp;
	t_stack	*node;
	tmp = stack_a;
	int i = 2;
	while (argc - 1 >= i)
	{
		node = (t_stack *)malloc(sizeof(t_stack));
		if (node == NULL)
			return(1);
		node -> prev = tmp;
		tmp -> next = node;
		node -> nbr = atoi(argv[i]);
		tmp = tmp -> next;
		i++;
	}
	stack_a -> prev = node;
	node -> next = stack_a;



/*
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (stack_a == NULL);
		retuen(NULL);
	stack_a -> nbr = argc;


	p1 = (t_stack *)malloc(sizeof(t_stack));
	if (p1 == NULL);
		retuen(NULL);
	stack_a -> next  = &p1;
	p1 -> nbr = 2;


	p2 = (t_stack *)malloc(sizeof(t_stack));
	if (p2 == NULL);
		retuen(NULL);
	p1 -> next  = &p2;
	p2 -> nbr = 3;


	// if (argc == 1)
	// 	return (1);

≈

	p2 -> next  = &p3;


	// stack_b.nbr = p1.next;
*/
	return (0);
}
