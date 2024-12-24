/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:28:57 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/25 04:10:01 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	test_print(t_stack *stack, char *str)
{
	t_stack *tmp = stack;
	if (tmp != NULL)
	{
		do {
			printf("%s：%d ", str, tmp->nbr);
			tmp = tmp->next;
		} while (tmp != stack);
	}
	printf("\n");
}

void	test(t_stack *stack_a, t_stack *stack_b)
{
	pb(&stack_a, &stack_b);
	test_print(stack_a, "stack_a");
	test_print(stack_b, "stack_b");
	pb(&stack_a, &stack_b);
	test_print(stack_a, "stack_a");
	test_print(stack_b, "stack_b");
	pa(&stack_a, &stack_b);
	test_print(stack_a, "stack_a");
	test_print(stack_b, "stack_b");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	if (error_check(argc, argv) == -1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (-1);
	}

	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_stack(argc, argv);
	if (has_dup(&stack_a) == true)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		free_stack(stack_a);
		return (-1);
	}
	// marge_sort(&stack_a, &stack_b);
	test(stack_a, stack_b);

	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}


void	memo()
{

	// string s="123456789";
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
	// struct s_stack *p1,*p2,*p3;


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
}
