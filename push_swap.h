/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchafiki <mchafiki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:38:39 by mchafiki          #+#    #+#             */
/*   Updated: 2025/04/06 14:39:56 by mchafiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

void	print_error(void);
void	ft_free(char **s);
char	*mystrdup(const char *s, char c);
int		count_word(const char *s, char c);
int		ft_lenword(const char *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(const char *s, char c);
int		is_only_spaces(char *str);
void	check_args(char **av);

#endif