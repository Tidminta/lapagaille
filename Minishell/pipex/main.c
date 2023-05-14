/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:04:36 by tminta            #+#    #+#             */
/*   Updated: 2023/05/13 20:19:47 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

// void	ft_exec(t_pipe	*box, int indic, int *fdout)
// {
// 	int		res;
// 	int		pid;
// 	t_cmd	*cmd;

// 	(void)fdout;
// 	pid = fork();
// 	if (indic == 1)
// 		cmd = box->cmd1;
// 	else
// 		cmd = box->cmd2;
// 	if (pid == 0)//son
// 	{
// 		res = execve(cmd->cmd_p, cmd->args, box->envp);
// 		exit(0);
// 	}
// 	else//father
// 	{
// 		(void)res;
// 		close(box->pipe[1]);
// 		wait(&pid);
// 	}
// }

// void	ft_redir(t_pipe *box, int indic)
// {
// 	if (indic == 1)
// 	{
// 		box->fd1 = open(box->file1, O_RDWR | O_CREAT, 0666);
// 		dup2(box->fd1, 0);
// 		dup2(box->pipe[1], 1);
// 	}
// 	else if (indic == 2)
// 	{
// 		box->fd2 = open(box->file2, O_RDWR | O_TRUNC | O_APPEND, 0666);
// 		dup2(box->pipe[0], 0);
// 		dup2(box->fd2, 1);
// 	}
// }

// //if (!get_path) -> handle_error(errno);
// int	processing(t_pipe *box)
// {	
// 	int indic;
// 	int	fdout;

// 	indic = 1;
// 	// ft_open2(box);
// 	pipe(box->pipe);
// 	while (indic <= 2)
// 	{
// 		ft_redir(box, indic);
// 		ft_exec(box, indic, &fdout);
// 		indic++;
		
// 	}
// 	return (0);
// }

//  ./pipex file1 cmd1 cmd2 file2
int	main(int argc, char **argv, char **envp)
{
	t_pipe	*box;

	(void)argc;
	// if (argc != 5)
	// {
	// 	exit (0);
	// }
	ft_parsing_step(&box, argv, envp);
	if (!box)
		exit(0);
	processing(box);
	return (0);
}