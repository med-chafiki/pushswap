#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*joined;
	char	**sp;
	t_stack	*stack;

	if (ac < 2)
		return (0);
	check_args(av);
	joined = join_args(ac, av);
	sp = ft_split(joined, ' ');
	validate_split_args(sp, joined);
	free(joined);
	stack = fill_stack(sp);
	if (check_sort(stack))
		error(&stack, sp);
	ft_free(sp);
	ft_lstclear(&stack);
}

void	error(t_stack **stack, char **str)
{
	ft_lstclear(stack);
	free_split(str);
	exit(0);
}
