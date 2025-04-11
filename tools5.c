/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchafiki <mchafiki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:47:48 by mchafiki          #+#    #+#             */
/*   Updated: 2025/04/11 12:11:18 by mchafiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_for5_elements(t_stack **a, t_stack **b)
{
	int	index;

	if (!*a || !(*a)->next)
		return ;
	index = get_min(a);
	if (index <= 2)
	{
		while (index-- > 0)
			ra(a);
	}
	else
	{
		while (index < 5)
			rra(a);
	}
	pb(a, b);
	algo_for4_elements(a, b);
	pa(a, b);
}

void	error(t_stack **stack, char **str)
{
	ft_lstclear(stack);
	free_split(str);
	exit(0);
}

void	big_algo(t_stack **a, int *sorted_array, t_stack **b)
{
	int	size;
	int	end;

	size = ft_lstsize(*a);
	if (size <= 100)
		end = size / 6;
	else
		end = size / 14;
	compare_and_pb(a, sorted_array, b, end);
	push_back_sorted(a, b);
}

void	adjust_segment(int *start, int *end, int size)
{
	if (*end < size - 1)
		(*end)++;
	if (*start < size - 2)
		(*start)++;
}
