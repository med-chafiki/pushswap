/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchafiki <mchafiki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 02:59:48 by mchafiki          #+#    #+#             */
/*   Updated: 2025/04/11 03:04:39 by mchafiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_array(int *array, int ac, char **s)
{
	int	i;
	int	len;
	int	*sorted;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	array = malloc(len * sizeof(int));
	if (!array)
		return (NULL);
	while (s[i])
	{
		array[i] = ft_atoi(s[i], s, NULL);
		i++;
	}
	sorted = sort(array, ac - 1);
	return (sorted);
}

int	*sort(int *arr, int size)
{
	int	i;
	int	sorted;

	while (size-- > 0)
	{
		sorted = 1;
		i = 0;
		while (i < size)
		{
			if (arr[i] > arr[i + 1])
			{
				ft_swap(&arr[i], &arr[i + 1]);
				sorted = 0;
			}
			i++;
		}
		if (sorted)
			break ;
	}
	return (arr);
}

void	execute_algo(int size, t_stack **a, int *ar,
		t_stack **b)
{
	if (size == 1)
	{
		free(ar);
		return ;
	}
	else if (size == 2)
		algo_for2_elements(a);
	else if (size == 3)
		algo_for3_elements(a);
	else if (size == 4)
		algo_for4_elements(a, b);
	else if (size == 5)
		algo_for5_elements(a, b);
	else
		algo(a, ar, b);
	free(ar);
}

void	algo_for2_elements(t_stack **a)
{
	if (!*a || !(*a)->next)
		return ;
	if ((*a)->next == NULL)
		return ;
	if ((*a)->data > (*a)->next->data)
		sa(a);
}
