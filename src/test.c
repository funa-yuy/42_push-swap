/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:35:16 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/19 21:32:41 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// void	marge_ascend_atob(t_stack **stack_a, t_stack **stack_b)
// {
// 	while (*stack_a != NULL)
// 	{
// 	if(b_first < first && b_first < second && b_first < last)
// 		marge_ascend_atob(stack_a, stack_b);

// }

void	marge_descend_atob(t_stack **stack_a, t_stack **stack_b)
{
	long long int	first;
	long long int	second;
	long long int	last;
	long long int	b_first;
	long long int	first_diff;
	long long int	second_diff;
	long long int	last_diff;

	while (*stack_a != NULL)
	{
		first = (*stack_a) -> nbr;
		second = (*stack_a) -> next -> nbr;
		last = (*stack_a) -> prev -> nbr;
		b_first = (*stack_b) -> nbr;
		first_diff = b_first - first;
		second_diff = b_first - second;
		last_diff = b_first - last;

		if ((*stack_a) == (*stack_a) -> next)
		{
			pb(stack_a, stack_b);
			break;
		}
		if (b_first < first && b_first < second && b_first < last)
			marge_ascend_atob(stack_a, stack_b);

		if ((b_first > first) && (first_diff <= second_diff || b_first < second) && (first_diff <= last_diff || b_first < last))
		{
			pb(stack_a, stack_b);
		}
		else if ((b_first > second) && (second_diff <= first_diff || b_first < first) && (second_diff <= last_diff || b_first < last))
		{
			sa(stack_a);//raでもよき？
			pb(stack_a, stack_b);
		}
		else  if ((b_first > last) && (last_diff <= first_diff || b_first < first) && (last_diff <= second_diff || b_first < second))
		{
			rra(stack_a);
			pb(stack_a, stack_b);
		}
	}
}



void	marge_ascend_atob(t_stack **stack_a, t_stack **stack_b)
{
	long long int	first;
	long long int	second;
	long long int	last;
	long long int	b_first;
	long long int	first_diff;
	long long int	second_diff;
	long long int	last_diff;

	while (*stack_a != NULL)
	{
		first = (*stack_a) -> nbr;
		second = (*stack_a) -> next -> nbr;
		last = (*stack_a) -> prev -> nbr;
		b_first = (*stack_b) -> nbr;
		first_diff = b_first + first;
		second_diff = b_first + second;
		last_diff = b_first + last;

		if ((*stack_a) == (*stack_a) -> next)
		{
			pb(stack_a, stack_b);
			break;
		}

		if (b_first > first && b_first > second && b_first > last)
			marge_descend_atob(stack_a, stack_b);

		if ((b_first < first) && (first_diff <= second_diff || b_first > second) && (first_diff <= last_diff || b_first > last))
		{
			pb(stack_a, stack_b);
		}
		else if ((b_first < second) && (second_diff <= first_diff || b_first > first) && (second_diff <= last_diff || b_first > last))
		{
			sa(stack_a);//raでもよき？
			pb(stack_a, stack_b);
		}
		else  if ((b_first < last) && (last_diff <= first_diff || b_first > first) && (last_diff <= second_diff || b_first > second))
		{
			rra(stack_a);
			pb(stack_a, stack_b);
		}
	}
}



void	marge_descend_btoa(t_stack **stack_a, t_stack **stack_b)
{
	long long int	first;
	long long int	second;
	long long int	last;
	long long int	a_first;
	long long int	first_diff;
	long long int	second_diff;
	long long int	last_diff;

	while (*stack_b != NULL)
	{
		first = (*stack_b) -> nbr;
		second = (*stack_b) -> next -> nbr;
		last = (*stack_b) -> prev -> nbr;
		a_first = (*stack_a) -> nbr;
		first_diff = a_first - first;
		second_diff = a_first - second;
		last_diff = a_first - last;

		if ((*stack_b) == (*stack_b) -> next)
		{
			pa(stack_a, stack_b);
			break;
		}
		if(a_first < first && a_first < second && a_first < last)
			marge_ascend_btoa(stack_a, stack_b);

		if ((a_first > first) && (first_diff <= second_diff || a_first < second) && (first_diff <= last_diff || a_first < last))
		{
			pa(stack_a, stack_b);
		}
		else if ((a_first > second) && (second_diff <= first_diff || a_first < first) && (second_diff <= last_diff || a_first < last))
		{
			sb(stack_b);//raでもよき？
			pa(stack_a, stack_b);
		}
		else  if ((a_first > last) && (last_diff <= first_diff || a_first < first) && (last_diff <= second_diff || a_first < second))
		{
			rrb(stack_b);
			pa(stack_a, stack_b);
		}
	}
}

void	marge_ascend_btoa(t_stack **stack_a, t_stack **stack_b)
{
	long long int	first;
	long long int	second;
	long long int	last;
	long long int	a_first;
	long long int	first_diff;
	long long int	second_diff;
	long long int	last_diff;

	while (*stack_b != NULL)
	{
		first = (*stack_b) -> nbr;
		second = (*stack_b) -> next -> nbr;
		last = (*stack_b) -> prev -> nbr;
		a_first = (*stack_a) -> nbr;
		first_diff = a_first + first;
		second_diff = a_first + second;
		last_diff = a_first + last;

		if ((*stack_b) == (*stack_b) -> next)
		{
			pa(stack_a, stack_b);
			break;
		}
		if (a_first > first && a_first > second && a_first > last)
			marge_descend_btoa(stack_a, stack_b);

		if ((a_first < first) && (first_diff <= second_diff || a_first > second) && (first_diff <= last_diff || a_first > last))
		{
			pa(stack_a, stack_b);
		}
		else if ((a_first < second) && (second_diff <= first_diff || a_first > first) && (second_diff <= last_diff || a_first > last))
		{
			sb(stack_b);//raでもよき？
			pa(stack_a, stack_b);
		}
		else  if ((a_first < last) && (last_diff <= first_diff || a_first > first) && (last_diff <= second_diff || a_first > second))
		{
			rrb(stack_b);
			pa(stack_a, stack_b);
		}
	}
}



// void	marge_descend_btoa(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	first;
// 	int	second;
// 	int	last;
// 	int	a_first;

// 	while (*stack_b != NULL)
// 	{
// 		first = (*stack_b) -> nbr;
// 		second = (*stack_b) -> next -> nbr;
// 		last = (*stack_b) -> prev -> nbr;
// 		a_first = (*stack_a) -> nbr;

// 		if ((*stack_b) == (*stack_b) -> next)
// 		{
// 			pa(stack_a, stack_b);
// 			break;
// 		}
// 		if(a_first < first && a_first < second && a_first < last)
// 			marge_ascend_btoa(stack_a, stack_b);

// 		if (a_first - first < a_first - second && a_first - first < a_first - last)
// 		{
// 			pa(stack_a, stack_b);
// 		}
// 		else if (a_first - second < a_first - first && a_first - second < a_first - last)
// 		{
// 			sb(stack_b);//raでもよき？
// 			pa(stack_a, stack_b);
// 		}
// 		else  if (a_first - last < a_first - first && a_first - last < a_first - second)
// 		{
// 			rrb(stack_b);
// 			pa(stack_a, stack_b);
// 		}
// 	}
// }

// void	marge_ascend_btoa(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	first;
// 	int	second;
// 	int	last;
// 	int	a_first;

// 	while (*stack_b != NULL)
// 	{
// 		first = (*stack_b) -> nbr;
// 		second = (*stack_b) -> next -> nbr;
// 		last = (*stack_b) -> prev -> nbr;
// 		a_first = (*stack_a) -> nbr;

// 		if ((*stack_b) == (*stack_b) -> next)
// 		{
// 			pa(stack_a, stack_b);
// 			break;
// 		}
// 		if (a_first > first && a_first > second && a_first > last)
// 			marge_descend_btoa(stack_a, stack_b);

// 		if (a_first + first < a_first + second && a_first + first < a_first + last)
// 		{
// 			pa(stack_a, stack_b);
// 		}
// 		else if (a_first + second < a_first + first && a_first + second < a_first + last)
// 		{
// 			sb(stack_b);//raでもよき？
// 			pa(stack_a, stack_b);
// 		}
// 		else  if (a_first + last < a_first + first && a_first + last < a_first + second)
// 		{
// 			rrb(stack_b);
// 			pa(stack_a, stack_b);
// 		}
// 	}
// }
