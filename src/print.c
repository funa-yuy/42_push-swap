/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:18:41 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/17 00:07:25 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// int ft_strlen(char *str)
// {
//     int i;

//     i = 0;
//     while (*str != '\0')
//     {
//         str++;
//         i++;
//     }
//     return (i);
// }

// void print_error()
// {
//     write(STDERR_FILENO, "Error\n", 6);
// }

void put_str(char *str)
{
    write(1, str, ft_strlen(str));
}
