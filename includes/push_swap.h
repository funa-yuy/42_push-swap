/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:27:45 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/30 03:20:17 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
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

// mergesort
void		marge_sort(t_stack **stack_a, t_stack **stack_b);
int			sort_check(t_stack *stack);
void		marge_first_atob(t_stack **stack_a, t_stack **stack_b);
void		marge_first_btoa(t_stack **stack_a, t_stack **stack_b);
void		marge_sort_btoa(t_stack **stack_a, t_stack **stack_b);
void		marge_sort_atob(t_stack **stack_a, t_stack **stack_b);
int			descend_or_ascend(t_stack **stack_src, t_stack **stack_dest,
				int check);
void		marge_descend_atob(t_stack **stack_a, t_stack **stack_b);
void		marge_ascend_atob(t_stack **stack_a, t_stack **stack_b);
void		marge_descend_btoa(t_stack **stack_a, t_stack **stack_b);
void		marge_ascend_btoa(t_stack **stack_a, t_stack **stack_b);
int			calc_diff_ascend(int target, int first, int second, int last);
int			calc_diff_descend(int target, int first, int second, int last);
long long	safe_diff(long long int a, long long int b);

// 5 or less sort
void		sort_short(t_stack **stack_a, t_stack **stack_b);
void		sort_3size(t_stack **stack);
void		sort_4size(t_stack **stack_a, t_stack **stack_b);
void		sort_4size_pb(t_stack **stack_a, t_stack **stack_b, size_t min);
void		sort_5size(t_stack **stack_a, t_stack **stack_b);
void		sort_5size_pb(t_stack **stack_a, t_stack **stack_b, size_t min);
size_t		find_min_node(t_stack *stack);
size_t		ft_stacksize(t_stack *stack);

// operations
void		remove_targe_node(t_stack **s_dst, t_stack *node);
void		push_to_dst(t_stack **s_src, t_stack *node);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		swap_top_two(t_stack **stack);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

// create list
t_stack		*create_stack(int argc, char **argv);
t_stack		*create_node(int nbr);
void		add_node_to_stack(t_stack **stack, t_stack *new_node);

// new atoi
long int	ps_atoi_check(const char *str, int i, int sign);
long int	ps_atoi(const char *str);

// Error check
int			error_check(char **argv);
int			is_int(char *str);
int			is_intstr(char *str);
int			has_dup(t_stack **stack);

// free
void		free_stack(t_stack *stack);

#endif
