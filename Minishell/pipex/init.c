/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:24:02 by tminta            #+#    #+#             */
/*   Updated: 2023/05/13 21:30:02 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

t_pipe	*ft_box_fill(char **argv, char **envp)
{
	t_pipe	*tools;

	tools = (t_pipe *)malloc(sizeof(t_pipe));
	if (!tools)
		return (NULL);
	tools->envp = envp;
	tools->argv = argv;
	tools->path = 0;
	tools->pid = 0;
	tools->fd1 = 0;
	tools->fd2 = 0;
	tools->pipe = (int *)malloc(sizeof(int) * 2);
	tools->file1 = argv[1];
	tools->file2 = argv[4];
	return (tools);
}

void	ft_init(t_pipe **box, char **argv, char **envp)
{
	(*box) = ft_box_fill(argv, envp);
}
