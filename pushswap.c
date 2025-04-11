#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*array;
	char	*joined;
	char	**sp;
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	array = 0;
	joined = NULL;
	if (ac < 2)
		return (0);
	check_args(av);
	joined = join_args(ac, av);
	sp = ft_split(joined, ' ');
	validate_split_args(sp, joined);
	free(joined);
	a = fill_stack(sp);
	if (check_sort(a))
		error(&a, sp);
	execute_algo(count(sp), &a, sort_array(array, count(sp), sp), &b);
	ft_free(sp);
	ft_lstclear(&a);
	ft_lstclear(&b);
}

void	error(t_stack **stack, char **str)
{
	ft_lstclear(stack);
	free_split(str);
	exit(0);
}
