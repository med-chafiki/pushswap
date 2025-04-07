#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*joined;
	char	**sp;

	if (ac < 2)
		return (0);
	check_args(av);
	joined = join_args(ac, av);
	sp = ft_split(joined, ' ');
	validate_split_args(sp, joined);
}
