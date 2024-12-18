/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:40:24 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/17 00:12:07 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	ft_strcmp(char *s1, char *s2)
// {
// 	unsigned char	*s1_ptr;
// 	unsigned char	*s2_ptr;

// 	s1_ptr = (unsigned char *)s1;
// 	s2_ptr = (unsigned char *)s2;
// 	while (*s1_ptr != '\0' && *s1_ptr == *s2_ptr)
// 	{
// 		s1_ptr++;
// 		s2_ptr++;
// 	}
// 	return (*s1_ptr - *s2_ptr);
// }

int	is_intstr(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (true);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

int	is_int(char *str)
{
	long int	li;

	if (is_intstr(str) == false)
		return (false);
	li = 0;
	li = ps_atoi(str);
	if (li > INT_MAX || li < INT_MIN)
		return (false);
	return (true);
}

// static int	has_dup(char **str_arr)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*word;

// 	i = 0;
// 	word = NULL;
// 	while (str_arr[i])
// 	{
// 		word = str_arr[i];
// 		j = i + 1;
// 		while (str_arr[j])
// 		{
// 			if (ft_strcmp(word, str_arr[j]) == 0)
// 				return (true);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (false);
// }

int	error_check(int argc, char **argv)
{
	int	i;

	if (argc == 2)
		argv[1] = *ft_split(argv[1], ' ');
	i = 1;
	while (argv[i] != NULL)
	{
		if (is_int(argv[i]) == false)
			return (-1);
		i++;
	}
	// if (has_dup(++argv) == true)
	// 	return (-1);
	// else
	// 	return (0);
	return (0);
}
// 文字が入っていないか
// ↓
// atoiでint型に入れる
// ↓
// INT_MAX || INT_MINを超えてないか
