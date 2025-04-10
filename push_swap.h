/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchafiki <mchafiki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:38:39 by mchafiki          #+#    #+#             */
/*   Updated: 2025/04/10 14:12:25 by mchafiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}					t_stack;

void				print_error(void);
void				ft_free(char **s);
size_t				ft_strlen(const char *str);
char				*mystrdup(const char *s, char c);
int					count_word(const char *s, char c);
int					ft_lenword(const char *s, char c);
size_t				ft_strlen(const char *str);
char				*ft_strjoin(char *s1, char *s2);
char				**ft_split(const char *s, char c);
int					is_only_spaces(char *str);
void				check_args(char **av);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strdup(const char *src);
char				*join_args(int ac, char **av);
int					is_valid_number(const char *str);
void				validate_split_args(char **split_args, char *joined);
t_stack				*ft_lstnew(int data);
int					ft_lstsize(t_stack *lst);
void				ft_lstadd_front(t_stack **stack, t_stack *new);
void				ft_lstadd_back(t_stack **stack, t_stack *new);
t_stack				*ft_lstlast(t_stack *lst);
int					ft_atoi(const char *str, char **av, t_stack **stack);
void				lines(char **av, t_stack **stack);
void				ft_lstclear(t_stack **lst);
t_stack				*fill_stack(char **av);
int					check_duplicates(t_stack *stack);
int					check_overflow(long long result, int sign, char **av,
						t_stack **stack);
int					check_if_args_empty(char *av);
int					check_sort(t_stack *stack);
void				error(t_stack **stack, char **str);
void				free_split(char **str);
void				ft_swap(int *a, int *b);
void				pa(t_stack **a, t_stack **b);
void				sa(t_stack **a);
void				rra(t_stack **a);
void				ra(t_stack **a);

#endif
