/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchafiki <mchafiki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:07:25 by mchafiki          #+#    #+#             */
/*   Updated: 2025/04/10 16:07:26 by mchafiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*top;

	if (!*b)
		return ;
	top = *b;
	*b = (*b)->next;
	top->next = *a;
	*a = top;
	write(1, "pa\n", 3);
}

void	sa(t_stack **a)
{
	if (*a != NULL && (*a)->next != NULL)
	{
		ft_swap(&(*a)->data, &(*a)->next->data);
		write(1, "sa\n", 3);
	}
}

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (*a != NULL && (*a)->next != NULL)
	{
		last = ft_lstlast(*a);
		first = (*a)->next;
		last->next = *a;
		(*a)->next = NULL;
		*a = first;
		write(1, "ra\n", 3);
	}
}
