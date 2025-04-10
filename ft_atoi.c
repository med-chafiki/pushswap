/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchafiki <mchafiki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:16:04 by mchafiki          #+#    #+#             */
/*   Updated: 2025/04/09 18:47:01 by mchafiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, char **av, t_stack **stack)
{
	int			i;
	long long	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	if (!str)
		return (0);
	while (str[i] == 32 || (str[i] > 9 && str[i] < 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (check_overflow(result, sign, av, stack))
			return (0);
	}
	return ((int)(sign * result));
}

int	check_overflow(long long result, int sign, char **av, t_stack **stack)
{
	if (sign == 1 && result > INT_MAX)
	{
		lines(av, stack);
		return (1);
	}
	if (sign == -1 && (-result) < INT_MIN)
	{
		lines(av, stack);
		return (1);
	}
	return (0);
}

void	lines(char **av, t_stack **stack)
{
	ft_free(av);
	if (stack)
		ft_lstclear(stack);
	print_error();
}
