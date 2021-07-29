#include "../../includes/libshell.h"
extern t_gc *g_gc;

int	get_line(void)
{
	char *str;
	char *str2;

	str = readline("test_> ");
	str2 = ft_strdup(str);
	return (1);
}

int	main(void)
{
	gc_init();
	char *str;

	while (1)
	{
		get_line();
		gc("collect");
	}
	return (0);
}
