/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:28:57 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/19 15:09:59 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	has_dup(t_stack **stack)
{
	t_stack	*now_nbr;
	t_stack	*next_nbr;

	now_nbr = *stack;
	while (now_nbr -> next != *stack)
	{
		next_nbr = now_nbr;
		while (next_nbr -> next != *stack)
		{
			next_nbr = next_nbr -> next;
			if (now_nbr -> nbr - next_nbr -> nbr == 0)
				return (true);
		}
		now_nbr = now_nbr -> next;
	}
	return (false);
}

t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	t_stack	*node;
	int		i;

	stack_a = NULL;
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (stack_a == NULL)
		return (NULL);
	stack_a -> nbr = ps_atoi(argv[1]);
	// stack_a -> prev = NULL;
	// stack_a -> next = NULL;

	if (argc == 2)
	{
		stack_a -> prev = stack_a;
		stack_a -> next = stack_a;
		return (stack_a);
	}
	else
	{
		tmp = stack_a;
		i = 2;
		while (argc - 1 >= i)
		{
			node = (t_stack *)malloc(sizeof(t_stack));
			if (node == NULL)
				return (NULL);
			node -> prev = tmp;
			tmp -> next = node;
			node -> nbr = ps_atoi(argv[i]);
			tmp = tmp -> next;
			i++;
		}
		stack_a -> prev = node;
		node -> next = stack_a;
	}
	return (stack_a);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*start;

	if (!stack)
		return;

	start = stack;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;

		if (stack == start)// 循環の終了条件
		{
			free(tmp);
			break;
		}
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return(0);
	if (error_check(argc, argv) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}

	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_stack(argc, argv);

	if (has_dup(&stack_a) == true)
	{
		write(2, "Error\n", 6);
		free_stack(stack_a);
		return (-1);
	}

	marge_sort(&stack_a, &stack_b);

	t_stack *tmp = stack_a;
    if (tmp != NULL)
    {
        do {
            printf("%d ", tmp->nbr);
            tmp = tmp->next;
        } while (tmp != stack_a);
    }
    printf("\n");

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
