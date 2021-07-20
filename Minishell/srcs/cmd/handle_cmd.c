/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:03:41 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/20 23:15:09 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

void			simple_exec(t_msh *msh, t_cut_cmd *cmd)
{
	int		pid;
	char	*exec_path;
	char	**args;

	pid = fork();
	if (pid == 0)
	{
		exec_path = get_path(cmd, msh->path);
		if (!exec_path || exec_path == NULL)
			ft_error(cmd, "PATH ERROR\n", 0);
		args = handle_args(msh, cmd);
		if (!args || args == NULL)
			ft_error(cmd, "BAD ARGS/OPTION\n", 0);
		execve(exec_path, args, msh->envp);
		ft_error(cmd, "Execution failed.\n", errno);
	}
	else
		waitpid(pid, &msh->tools->status, 0);
}

void				cmd_nopipe(t_msh *msh, t_cut_cmd *cmd)
{
	int	ret;

	ret = choose_exec(cmd);
	if (ret == BUILTIN)
	{
		printf("[TEST][IS BUILTIN IN PROGRESS ..]\n");
		// handle_builtins(msh, cmd);
	}
	else if (ret == EXEC)
		simple_exec(msh, cmd);
	else
		ft_error(cmd, "Bad commande", 0);
}

void			cmd_pipe(t_msh *msh, t_cut_cmd *cmd)
{//EXECUTION DES COMMANDE PIPÉS
	int		pid;
	int		bfd;
	char	*exec_path;
	char	**args;

	bfd = 0;
	while (cmd != NULL)
	{
		pipe(msh->tools->pipe);
		pid = fork();
		if ( pid == 0)
		{
			dup2(bfd, 0);
			handle_redirection(msh, cmd);
			exec_path = get_path(cmd, msh->path);
			args = handle_args(msh, cmd);
			execve(exec_path, args, msh->envp);
			printf("[EXEC ERROR][%s]\n", cmd->elem);
		}
		else if (pid > 0)
		{
			wait(NULL);
			close(msh->tools->pipe[1]);
			bfd = msh->tools->pipe[0];
		}
		else
		{
			printf("ERROR PID\n");
			exit (0);
		}
		getnext_pipe(&cmd);
	}
}

int         handle_cmd(t_msh *msh)
{
	if (!msh || msh == NULL)
		return (ERROR);
	msh->tools->nbpipe = ispipe(msh);
	whatpostions(msh);
	// printheader(msh);
	if (msh->tools->nbpipe)
		cmd_pipe(msh, msh->tools->tail);
	else
		cmd_nopipe(msh, msh->tools->tail);
	msh->run_status = 0;
	return (0);
}
