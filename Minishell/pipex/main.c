/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:04:36 by tminta            #+#    #+#             */
/*   Updated: 2023/05/11 16:38:10 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	ft_exec(t_pipe	*box, int indic)
{
	int		res;
	int		pid;

	pid = fork();
	if (pid == 0)//son
	{
		res = execve(box->path[indic], box->f_args[indic], box->envp);
		exit(0);
	}
	else//father
	{
		(void)res;
		wait(&pid);
	}
}

//if (!get_path) -> handle_error(errno);
int	processing(t_pipe *box)
{
	int indic;

	indic = -1;	
	// ft_open2(box);
	while (indic < 2)
		ft_exec(box, indic);
	// ft_pipe();
	// ft_redirections();
	return (0);
}

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