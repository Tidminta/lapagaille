/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:24:02 by tminta            #+#    #+#             */
/*   Updated: 2023/05/11 19:31:21 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	is_empty_(t_cmd *elem, int indic)
{
	// if (indic == FILE)
	// 	(void)elem; //(t_files*)elem;
	// else if (indic == CMD)
	// 	(t_cmd*)elem;
	if (!elem || elem == NULL)
		return (SUCCESS);
	return (ERROR);
}

// static t_files		*ft_create_lstf();//create list file

int		ft_create_lstc(t_pipe **box)//crete list cmd
{
	t_cmd   *new_block;

    if (is_empty_env((*box)->cmd_box->head))
    {
        new_block = (t_cmd *)malloc(sizeof(t_cmd));
        if (!new_block)
            return (-1);
        new_block->cmd_n = ft_strdup("Yeah!");
		new_block->cmd_p = NULL;
		new_block->args = NULL;
		new_block->pos = -1;
        new_block->n = NULL;
        (*box)->cmd_box->head = new_block;
        (*box)->cmd_box->tail = new_block;
        (*box)->cmd_box->size = 1;
        return (SUCCESS);
    }
    return (ERROR);	
}

int add_cmd(t_pipe **box, char *content, int indic)
{
    t_cmd   *new_block;

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