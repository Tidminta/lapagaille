/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:40:08 by tminta            #+#    #+#             */
/*   Updated: 2023/05/13 20:21:02 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	ft_exec(t_pipe	*box, int indic, int *fdout)
{
	int		res;
	int		pid;
	t_cmd	*cmd;

	(void)fdout;
	pid = fork();
	if (indic == 1)
		cmd = box->cmd1;
	else
		cmd = box->cmd2;
	if (pid == 0)
	{
		res = execve(cmd->cmd_p, cmd->args, box->envp);
		exit(1);
		// perror("PIPEX");
	}
	else
	{
		(void)res;
		close(box->pipe[1]);
		wait(&pid);
	}
}

static void	ft_redir(t_pipe *box, int indic)
{
	if (indic == 1)
	{
		box->fd1 = open(box->file1, O_RDWR | O_CREAT, 0666);
		dup2(box->fd1, 0);
		dup2(box->pipe[1], 1);
	}
	else if (indic == 2)
	{
		box->fd2 = open(box->file2, O_RDWR | O_CREAT | O_TRUNC , 0666);
		dup2(box->pipe[0], 0);
		dup2(box->fd2, 1);
	}
}

//if (!get_path) -> handle_error(errno);
int	processing(t_pipe *box)
{	
	int indic;
	int	fdout;

	indic = 1;
	// ft_open2(box);
	pipe(box->pipe);
	while (indic <= 2)
	{
		ft_redir(box, indic);
		ft_exec(box, indic, &fdout);
		indic++;
	}
	return (0);
}