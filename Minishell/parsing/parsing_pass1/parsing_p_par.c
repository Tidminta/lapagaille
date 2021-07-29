#include "../../includes/libshell.h"

int		p_check_par(t_msh *msh, char *str)
{
	int count;
	int open;
	int close;
	int i;
	int err;

	(void)msh;
	i = -1;
	open = 0;
	close = 0;
	err = 1;
	count = 0;
	while (str[++i] && err)
	{
		if (str[i] == '(' || str[i] == ')')
			count++;
		if (str[i]== ')')
			close++;
		if (close > open)
			err = 0;
		if (str[i] == '(')
			open++;
	}
	err = open != close ? 0 : err;
	err = count % 2 == 0 ? err : 0;
	if (!err)
		msh->tools->error_msg = ft_strdup("Unbalanced parenthesis.");
	return (err);
}
