/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_diff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:35:16 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/25 03:32:52 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	safe_diff(long long int a, long long int b)
{
	return ((long long)a - (long long)b);
}

int	calc_diff_descend(int target, int first, int second, int last)
{
	long long int	diff_f;
	long long int	diff_s;
	long long int	diff_l;

	diff_f = safe_diff(target, first);
	diff_s = safe_diff(target, second);
	diff_l = safe_diff(target, last);

	if ((target > first) && (diff_f <= diff_s || target < second) \
		&& (diff_f <= diff_l || target < last))
	{
		return (0);
	}
	if ((target > second) && (diff_s <= diff_f || target < first) \
		&& (diff_s <= diff_l || target < last))
		return (1);
	return (2);
}

int	calc_diff_ascend(int target, int first, int second, int last)
{
	long long int	diff_f;
	long long int	diff_s;
	long long int	diff_l;

	diff_f = safe_diff(target, first);
	diff_s = safe_diff(target, second);
	diff_l = safe_diff(target, last);

	if ((target < first) && (diff_f >= diff_s || target > second) \
		&& (diff_f >= diff_l || target > last))
	{
		return (0);
	}
	if ((target < second) && (diff_s >= diff_f || target > first) \
		&& (diff_s >= diff_l || target > last))
		return (1);
	return (2);
}
