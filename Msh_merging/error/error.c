#include "../includes/libshell.h"

void	write_error(t_msh *msh)
{
	if (msh->tools->error_msg)
	{
		write(2, msh->tools->error_msg, ft_strlen(msh->tools->error_msg));
		write(2, "\n", 1);
	}
	msh->tools->error_msg = NULL;
}

void	handler(int n)
{
	(void)n;
	gc("collect -all");
	exit (0);
}

void			ft_error(t_cut_cmd *cmd, char *str, int errornum)
{
	if (str)
		ft_putstr_fd(cmd->elem, 1);
	else
		strerror(errornum);
	exit (errornum);
}
