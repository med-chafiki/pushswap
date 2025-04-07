/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchafiki <mchafiki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:33:33 by mchafiki          #+#    #+#             */
/*   Updated: 2025/04/07 18:21:03 by mchafiki         ###   ########.fr       */
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
