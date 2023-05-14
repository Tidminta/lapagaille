/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:24:02 by tminta            #+#    #+#             */
/*   Updated: 2023/05/13 19:45:33 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

// static int	is_empty_(t_cmd *elem, int indic)
// {
// 	// if (indic == FILE)
// 	// 	(void)elem; //(t_files*)elem;
// 	// else if (indic == CMD)
// 	// 	(t_cmd*)elem;
// 	(void)indic;
// 	if (!elem || elem == NULL)
// 		return (SUCCESS);
// 	return (ERROR);
// }

// static t_files		*ft_create_lstf();//create list file

int		ft_create_lstc(t_pipe **box)//crete list cmd
{
	t_cmd   *new_block;

    // if (is_empty_((*box)->cmd_box->head, 1))
    // {
        new_block = (t_cmd *)malloc(sizeof(t_cmd));
        if (!new_block)
            return (-1);
		(*box)->cmd_box = (t_box*)malloc(sizeof(t_box) * 1);
		(*box)->cmd_box->head = (t_cmd*)malloc(sizeof(t_cmd) * 1);
		(*box)->cmd_box->tail = (t_cmd*)malloc(sizeof(t_cmd) * 1);
        // new_block->cmd_n = ft_strdup("Yeah!");
		new_block->cmd_p = NULL;
		new_block->args = NULL;
		new_block->pos = -1;
        new_block->n = NULL;
        (*box)->cmd_box->head = new_block;
        (*box)->cmd_box->tail = new_block;
        (*box)->cmd_box->size = 1;		
        return (SUCCESS);
    // }
    return (ERROR);	
}

int add_cmd(t_pipe **box, char *content, int indic)
{
    t_cmd   *new_block;

	(void)indic;
    new_block = (t_cmd *)malloc(sizeof(t_cmd));
    if (!new_block)
        return (-1);
    new_block->cmd_n = ft_strdup(content);
	new_block->cmd_p = NULL;
    new_block->n = NULL;
    new_block->p = (*box)->cmd_box->tail;
    (*box)->cmd_box->tail->n = new_block;
    (*box)->cmd_box->tail = new_block;
    (*box)->cmd_box->size++;
	(*box)->cmd_box->tail->pos = (*box)->cmd_box->size;
    return (SUCCESS);
}

t_pipe	*ft_box_fill(char **argv, char **envp)
{
	t_pipe	*tools;

	tools = (t_pipe *)malloc(sizeof(t_pipe));
	if (!tools)
		return (NULL);
	tools->envp = envp;
	tools->argv = argv;
	// tools->file1 = ft_strdup(argv[1]);
	// tools->cmd1 = ft_strdup(argv[2]);
    // tools->cmd[0] = ft_strdup(argv[2]);
    // tools->cmd[1] = ft_strdup(argv[3]);
	// tools->o_cmd1 = 0;
    // tools->only_cmd = (char**)malloc(sizeof(char*) * 3);
    // tools->only_cmd[2] = NULL;
	// tools->file2 = ft_strdup(argv[4]);
	// tools->cmd2 = ft_strdup(argv[3]);
	// tools->o_cmd2 = 0;
	tools->path = 0;
	tools->pid = 0;
	tools->err_no = 0;
	tools->fd1 = 0;
	tools->fd2 = 0;
	tools->pipe = (int*)malloc(sizeof(int) * 2);
	// tools->pipe = pipe(tools->pipe);
	tools->file1 = argv[1];
	tools->file2 = argv[4];
	// tools->paths = 0;
    // tools->f_args = (char***)malloc(sizeof(char**) * 3);
    // tools->f_args[2] = NULL;
	// tools->f_args[0] = ft_split(argv[2], ' ');
	// tools->f_args[1] = ft_split(argv[3], ' ');
	ft_create_lstc(&tools);
	return (tools);
}

void	ft_init(t_pipe **box, char **argv, char **envp)
{
	(*box) = ft_box_fill(argv, envp);
}