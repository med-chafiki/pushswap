/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchafiki <mchafiki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:44:36 by mchafiki          #+#    #+#             */
/*   Updated: 2025/04/11 12:10:36 by mchafiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack **stack)
{
	t_stack	*tmp;
	int		max_value;
	int		big_index;
	int		i;

	i = 0;
	tmp = *stack;
	big_index = 0;
	max_value = tmp->data;
	while (tmp)
	{
		if (tmp->data > max_value)
		{
			max_value = tmp->data;
			big_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (big_index);
}

int	get_min(t_stack **stack)
{
	t_stack	*tmp;
	int		min_val;
	int		idx;
	int		i;

	i = 0;
	tmp = *stack;
	min_val = tmp->data;
	idx = 0;
	while (tmp)
	{
		if (tmp->data < min_val)
		{
			min_val = tmp->data;
			idx = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (idx);
}

void	algo_for4_elements(t_stack **a, t_stack **b)
{
	int	index;

	if (!*a || !(*a)->next)
		return ;
	index = get_min(a);
	if (index == 1)
		sa(a);
	else if (index == 2)
	{
		ra(a);
		ra(a);
	}
	else if (index == 3)
		rra(a);
	pb(a, b);
	algo_for3_elements(a);
	pa(a, b);
}

void	compare_and_pb(t_stack **a, int *arr_sorted, t_stack **b, int end)
{
	int	start;
	int	size;

	if (!*a)
		return ;
	start = 0;
	size = ft_lstsize(*a);
	while (end < size && *a)
	{
		if ((*a)->data <= arr_sorted[start])
		{
			pb(a, b);
			rb(b);
			adjust_segment(&start, &end, size);
		}
		else if ((*a)->data <= arr_sorted[end])
		{
			pb(a, b);
			if (*b && (*b)->next && (*b)->data < (*b)->next->data)
				sb(b);
            adjust_segment(&start, &end, size);
		}
		else if ((*a)->data > arr_sorted[end])
			ra(a);
	}
}

void	push_back_sorted(t_stack **a, t_stack **b)
{
	int	biggest;

	while (*b)
	{
		biggest = get_max(b);
		while (biggest != 0 && biggest != ft_lstsize(*b))
		{
			if (biggest < ft_lstsize(*b) / 2)
			{
				rb(b);
				biggest--;
			}
			else
			{
				rrb(b);
				biggest++;
			}
		}
		pa(a, b);
	}
}