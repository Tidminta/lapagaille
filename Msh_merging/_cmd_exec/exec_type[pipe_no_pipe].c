#include "../includes/libshell.h"

void				cmd_nopipe(t_msh *msh, t_cut_cmd *cmd)
{
	(void)cmd;
	(void)msh;
	if (cmd && cmd->TOKEN == C_BUILTIN)
		handle_builtins(msh, cmd);
	else if (cmd && cmd->TOKEN == C_ENV)
		simple_exec(msh, cmd);
}

void			cmd_pipe(t_msh *msh, t_cut_cmd *cmd)
{
	int		pid;
	int		bfd;
	char	*exec_path;
	char	**args;

	bfd = 0;
	while (cmd != NULL)
	{
			pipe(msh->tools->pipe);
			if ((cmd->p && cmd->p->TOKEN == ARG) && is_same(cmd->elem, "export"))
				builtin_export(msh, cmd);
			else
			{
				pid = fork();
				if ( pid == 0)
				{
					dup2(bfd, 0);
					handle_redirection(msh, cmd, bfd);
					if (cmd && cmd->TOKEN == C_BUILTIN)
						handle_builtins(msh, cmd);
					else
					{
						exec_path = get_path(cmd, msh->path);
						args = handle_args(msh, cmd);
						execve(exec_path, args, list_to_split(msh->env->head));
						printf("[EXEC -1][%s]\n", cmd->elem);
					}
				}
				else if (pid > 0)
				{
					waitpid(pid, &msh->tools->status, 0);
					if (msh->tools->status)
						printf("[FORK ISSUE][%d]\n", msh->tools->status);
					close(msh->tools->pipe[1]);
					bfd = msh->tools->pipe[0];
					if ((open("./msh_heredoc.msh", O_RDONLY, 0666) ) != -1)
						delete_heredoc(msh);
				}
				else
				{
					printf("-1 PID\n");
					exit (0);
				}
			}
		getnext_pipe(&cmd);
	}
}
