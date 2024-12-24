/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 03:39:06 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/25 03:39:38 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*start;

	if (!stack)
		return ;

	start = stack;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;

		if (stack == start)
		{
			free(tmp);
			break ;
		}
		free(tmp);
	}
}
