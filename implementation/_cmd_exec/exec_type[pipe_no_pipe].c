/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_type[pipe_no_pipe].c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 21:32:31 by tidminta          #+#    #+#             */
/*   Updated: 2021/08/18 21:34:00 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libshell.h"

void	cmd_nopipe(t_msh *msh, t_cut_cmd *cmd)
{
	(void)cmd;
	(void)msh;
	if (cmd && cmd->TOKEN == C_BUILTIN)
		handle_builtins(msh, cmd);
	else if (cmd && cmd->TOKEN == C_ENV)
		simple_exec(msh, cmd);
}

/* _place_holder_handle_wildcards(msh, cmd); */
/* _place_holder_handle_expand_env(msh, cmd); */
void	son_fork(t_msh *msh, t_cut_cmd *cmd, int bfd)
{
	char	*exec_path;
	char	**args;

	signal(SIGINT, signal_handler);
	dup2(bfd, 0);
	handle_redirection(msh, cmd, bfd);
	if (cmd && cmd->TOKEN == C_BUILTIN)
		handle_builtins(msh, cmd);
	else
	{
		exec_path = _place_holder_get_path(msh, cmd);
		msh->tools->tmp_node2 = cmd;
		args = handle_args(msh, cmd);
		execve(exec_path, args, list_to_split(msh->env->head));
		printf("[EXEC -1][elem = %s][TOKEN = %d]\n", cmd->elem, cmd->TOKEN);
		exit (1);
	}
}

// int kill(pid_t pid, int sig);
void	father_fork(t_msh *msh, int pid, int *bfd)
{
	waitpid(pid, &msh->tools->status, 0);
	if (msh->tools->status)
		printf("[FORK ISSUE][%d]\n", msh->tools->status);
	if (bfd >= 0)
	{
		close(msh->tools->pipe[1]);
		*bfd = msh->tools->pipe[0];
	}
	if ((open("./msh_heredoc.msh", O_RDONLY, 0666)) != -1)
		delete_heredoc(msh);
}

/* CHANGE ->ft_error(cmd, "-1 PID\n", 0); */
void	cmd_pipe(t_msh *msh, t_cut_cmd *cmd)
{
	pid_t	pid;
	int		bfd;

	bfd = 0;
	while (cmd != NULL)
	{
		pipe(msh->tools->pipe);
		if ((cmd->p && cmd->p->TOKEN == ARG) && is_same(cmd->elem, "export"))
			builtin_export(msh, cmd);
		else if ((cmd->p && cmd->p->TOKEN == ARG)
			&& is_same(cmd->elem, "unset"))
			builtin_unset(msh, cmd);
		else
		{
			pid = fork();
			if (pid == 0)
				son_fork(msh, cmd, bfd);
			else if (pid > 0)
				father_fork(msh, pid, &bfd);
			else
				ft_error(msh, cmd, "-1 PID\n", 0);
		}
		getnext_pipe(&cmd);
	}
}
