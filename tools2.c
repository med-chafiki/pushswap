/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchafiki <mchafiki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:31:41 by mchafiki          #+#    #+#             */
/*   Updated: 2025/04/10 18:42:22 by mchafiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_stack *stack)
{
	t_stack	*node;
	t_stack	*compare_node;

	node = stack;
	while (node)
	{
		compare_node = node->next;
		while (compare_node)
		{
			if (node->data == compare_node->data)
				return (0);
			compare_node = compare_node->next;
		}
		node = node->next;
	}
	return (1);
}

int	check_if_args_empty(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!av[i] || av[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	check_sort(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_split(char **str)
{
	int	j;

	if (!str)
		return ;
	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free(str);
}

int	count(char **sp)
{
	int	count;

	count = 0;
	while (sp[count])
	{
		count++;
	}
	return (count);
}
