#include "../includes/libshell.h"

int	print_env(t_cut_cmd *target)
{
	if (!target)
		return (0);
	while (target)
	{
		printf("%s\n", target->elem);
		target = target->n;
	}
	return (1);
}
