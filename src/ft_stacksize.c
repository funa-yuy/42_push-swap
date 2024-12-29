/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:39:07 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/29 16:41:09 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_stacksize(t_stack *stack)
{
	size_t	count;
	t_stack	*current;

	if (!stack)
		return (0);
	count = 1;
	current = stack -> next;
	while (current != stack)
	{
		count++;
		current = current->next;
	}
	return (count);
}
