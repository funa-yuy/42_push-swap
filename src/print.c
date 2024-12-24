/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:18:41 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/25 03:37:04 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void print_error()
// {
//     write(STDERR_FILENO, "Error\n", 6);
// }

void	put_str(char *str)
{
	write(1, str, ft_strlen(str));
}
