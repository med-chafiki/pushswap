/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchafiki <mchafiki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:53:54 by mchafiki          #+#    #+#             */
/*   Updated: 2025/04/10 16:53:55 by mchafiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*top;

	if (!*a)
		return ;
	top = *a;
	*a = (*a)->next;
	top->next = *b;
	*b = top;
	write(1, "pb\n", 3);
}

void	sb(t_stack **b)
{
	if (*b != NULL && (*b)->next != NULL)
	{
		ft_swap(&(*b)->data, &(*b)->next->data);
		write(1, "sb\n", 3);
	}
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (*b != NULL && (*b)->next != NULL)
	{
		last = ft_lstlast(*b);
		first = (*b)->next;
		last->next = *b;
		(*b)->next = NULL;
		*b = first;
		write(1, "rb\n", 3);
	}
}
