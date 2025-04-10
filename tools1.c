/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchafiki <mchafiki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:04:49 by mchafiki          #+#    #+#             */
/*   Updated: 2025/04/09 19:16:11 by mchafiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*char_dest;
	unsigned char	*char_src;

	if (!dest && !src)
		return (NULL);
	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *src)
{
	size_t	len_src;
	char	*arr;

	len_src = ft_strlen(src);
	arr = (char *)malloc((len_src + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	ft_memcpy(arr, src, len_src + 1);
	return (arr);
}

char	*join_args(int ac, char **av)
{
	int		i;
	char	*joined;

	i = 1;
	joined = ft_strdup("");
	while (i < ac)
	{
		joined = ft_strjoin(joined, av[i]);
		joined = ft_strjoin(joined, " ");
		i++;
	}
	return (joined);
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	validate_split_args(char **av, char *joined)
{
	int	j;

	j = 0;
	while (av[j])
	{
		if (!is_valid_number(av[j]) || !check_if_args_empty(av[j]))
		{
			free(joined);
			ft_free(av);
			print_error();
		}
		j++;
	}
}
