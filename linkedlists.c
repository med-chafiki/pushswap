/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchafiki <mchafiki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:18:38 by mchafiki          #+#    #+#             */
/*   Updated: 2025/04/09 14:18:38 by mchafiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int data)
{
	t_stack	*new_element;

	new_element = malloc(sizeof(t_stack));
	if (!new_element)
		return (NULL);
	new_element->data = data;
	new_element->next = NULL;
	return (new_element);
}

int	ft_lstsize(t_stack *lst)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	ft_lstadd_front(t_stack **stack, t_stack *new)
{
	if (!new || !stack)
		return ;
	new->next = *stack;
	*stack = new;
}

void	ft_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new || !stack)
		return ;
	last = ft_lstlast(*stack);
	if (!last)
		*stack = new;
	else
		last->next = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}
