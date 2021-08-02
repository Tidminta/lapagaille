#include "../includes/libshell.h"

int				is_input(t_cut_cmd **cmd)
{
	while ((*(cmd)) && (*(cmd))->TOKEN != PIPE)
	{
		if ((*cmd)->TOKEN == L_REDIR || (*cmd)->TOKEN == D_L_REDIR)
			return (SUCCESS);
		(*(cmd)) = (*(cmd))->p;
	}
	return (ERROR);
}

int			input_redirection(t_msh *msh, t_cut_cmd *cmd)
{
	// char *line;

	if (is_input(&cmd) == SUCCESS)
	{
		while((cmd && cmd->TOKEN != PIPE) && (cmd->TOKEN == ARG || cmd->TOKEN == L_REDIR || cmd->TOKEN == D_L_REDIR))
		{
			if (cmd->TOKEN == ARG && cmd->n->TOKEN == L_REDIR)
			{
				msh->tools->fdin = open(cmd->elem, O_RDWR, NULL);
				if (msh->tools->fdin < 0)
					return (ERROR);//exit(127 | errno)
				msh->tools->istmp = 0;
				dup2(msh->tools->fdin, 0);
			}
			else if (cmd->TOKEN == ARG && cmd->n->TOKEN == D_L_REDIR)
			{
				msh->tools->marker = cmd->elem;
				msh->tools->tmp_node = cmd;
				msh->tools->tmpfd = open("./msh_heredoc.msh", O_RDWR |  O_CREAT | O_TRUNC, 0666);
				if (msh->tools->tmpfd < 0)
					printf("OPEN FAILED\n");//ft_error();
				while ((get_line(msh, "> ") >= 0) && (ft_strncmp(msh->tools->marker, msh->jobs->have_been_read, (size_t)ft_strlen(msh->jobs->have_been_read))))
				{
					// printf("[DEBUG][%s]\n", msh->jobs->have_been_read);
					ft_putendl_fd(msh->jobs->have_been_read, msh->tools->tmpfd);
				}
				msh->tools->istmp = 2;
			}
			cmd = cmd->p;
		}
		return (SUCCESS);
	}
	return (ERROR);
}