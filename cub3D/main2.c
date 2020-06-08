#include "includes/libftprintf.h"
#include "includes/libft.h"

int main(int ac, char **av)
{
	char *str;
	int fd;
	int ret;
	int	cpt;
	// t_list	*tmp;
	t_list	*map;

	(void)ac;
	cpt = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == - 1)
		return (0);
	map = ft_lstnew("");
	while ((ret = get_next_line(fd, &str) > 0))
	{
		ft_printf("[GNL][%s]\n", str);
		ft_lstadd_back(&map, ft_lstnew(str));
		free(str);
		// free(tmp);
	}
	ft_print_list(map);
	return (0);
}
