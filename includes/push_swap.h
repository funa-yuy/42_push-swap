/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:27:45 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/15 15:31:45 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void	put_str(char *str);
int		ft_strlen(char *str);
void	marge_sort(t_stack **stack_a, t_stack **stack_b);
void	marge_first_atob(t_stack **stack_a, t_stack **stack_b);
void	marge_first_btoa(t_stack **stack_a, t_stack **stack_b);
void	marge_operation_atob(t_stack **stack_a, t_stack **stack_b);
int		marge_operation_btoa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// チェック
long int	ft_atoi(const char *str);
int	ft_isdigit(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
// int	ft_strcmp(char *s1, char *s2);
int	error_check(int argc, char **argv);
static int	is_int(char *str);
static int	is_intstr(char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
static int	has_dup(t_stack **stack);

#endif
