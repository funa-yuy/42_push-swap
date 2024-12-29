/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:28:57 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/30 01:45:22 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	if (error_check(argv) == -1)
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
	marge_sort(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
