/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchafiki <mchafiki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:33:33 by mchafiki          #+#    #+#             */
/*   Updated: 2025/04/09 18:29:00 by mchafiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_only_spaces(char *str)
{
	int	i;
	int	index;

	i = 0;
	index = 1;
	while (str[i])
	{
		if (str[i] != ' ')
			index = 0;
		i++;
	}
	return (index);
}

void	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0' || is_only_spaces(av[i]))
			print_error();
		i++;
	}
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*ptr;
	t_stack	*current;

	current = *lst;
	while (current != NULL)
	{
		ptr = current->next;
		free(current);
		current = ptr;
	}
	*lst = NULL;
}

t_stack	*fill_stack(char **av)
{
	t_stack	*new_node;
	t_stack	*stack;
	int		i;
	int		v;

	v = 0;
	i = 0;
	stack = NULL;
	while (av[i])
	{
		v = ft_atoi(av[i], av, &stack);
		new_node = ft_lstnew(v);
		if (!new_node)
			exit(1);
		ft_lstadd_back(&stack, new_node);
		i++;
	}
	if (check_duplicates(stack) == 0)
	{
		ft_lstclear(&stack);
		ft_free(av);
		print_error();
	}
	return (stack);
}
