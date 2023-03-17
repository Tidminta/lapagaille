/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:04:36 by tminta            #+#    #+#             */
/*   Updated: 2023/03/16 19:59:11 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

t_pipe	*ft_init(char **argv, char **envp)
{
	t_pipe	*tools;

	tools = (t_pipe *)malloc(sizeof(t_pipe));
	if (!tools)
		return (NULL);
	tools->envp = envp;
	tools->file1 = argv[1];
	tools->cmd1 = argv[2];
	tools->file2 = argv[3];
	tools->cmd2 = argv[4];
	return (tools);
}

// int	handle_redirection(box); -> gere les redirections
// int	ft_free(t_tools	*box); -> free tout ce qui a été malloc

void	ft_open(t_pipe *box)
{
	box->fd1 = open(box->file1, O_RDWR);
	if (box->fd1 == -1)
		return (ft_free(box));
	box->fd2 = open(box->file2, O_RDWR);
	if (box->fd2 == -1)
		return (ft_free(box));
}

int	processing(t_pipe *box)
{
	ft_open(box);
}


int	main(int argc, char **argv, char **envp)
{
	t_pipe	*box;

	if (argc != 5)
	{
		exit (0);
	}
	box = ft_init(argv, envp);
	if (!box)
		exit(0);
	processing(box);
	return (0);
}