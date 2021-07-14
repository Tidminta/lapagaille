/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:50:47 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/13 21:44:40 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

t_env		*fill_env(char *elem)
{
	t_env *ret;
	int i;

	i = -1;
	if (!(ret = malloc(sizeof(t_env))))
		return (0);
	// ret->elem = to_gc(&ret->elem, ft_strdup(elem));
	ret->elem = ft_strdup(elem);
	ret->n = NULL;
	ret->p = NULL;
	return (ret);
}

t_env			*envnode(t_msh *msh, char *elem)
{
	t_env *ret;

	ret = fill_env(elem);
	if (!msh->e_head)
	{
		msh->e_head = ret;
		msh->e_tail = msh->e_head;
		return (ret);
	}
	ret->n = msh->e_head;
	msh->e_head->p = ret;
	msh->e_head = ret;
	return (ret);
}

t_cut_cmd		*fill(char *elem, int header[HEADER_SIZE])
{
	t_cut_cmd *ret;
	int i;

	i = -1;
	if (!(ret = malloc(sizeof(t_cut_cmd))))
		return (0);
	// ret->elem = to_gc(&ret->elem, ft_strdup(elem));
	ret->elem = strdup(elem);
	while (++i < HEADER_SIZE)
		ret->header[i] = header[i];
	ret->n = NULL;
	ret->p = NULL;
	return (ret);
}

int			add(t_msh *msh, char *elem, int header[HEADER_SIZE])
{
	t_cut_cmd *ret;

	ret = fill(elem, header);
	if (!msh->tools->head)
	{
		msh->tools->head = ret;
		msh->tools->tail = msh->tools->head;
		return (1);
	}
	ret->n = msh->tools->head;
	msh->tools->head->p = ret;
	msh->tools->head = ret;
	// msh->tools->head->p = NULL;
	return (1);
}

int			init_cmd(t_msh *msh)
{

	int		*cmd;
	int		*option;
	int		*arg;
	int		*pipe;

	cmd = (int *)malloc(sizeof(int) * HEADER_SIZE);
	option = (int *)malloc(sizeof(int) * HEADER_SIZE);
	arg = (int *)malloc(sizeof(int) * HEADER_SIZE);
	pipe = (int *)malloc(sizeof(int) * HEADER_SIZE);
	ft_memset(cmd, 48, (size_t)HEADER_SIZE);
	ft_memset(option, 48, (size_t)HEADER_SIZE);
	ft_memset(arg, 48, (size_t)HEADER_SIZE);
	ft_memset(pipe, 48, (size_t)HEADER_SIZE);
	cmd[0] = 2;
	option[0] = 3;
	arg[0] = 4;
	pipe[0] = 0;
	pipe[1] = 3;
	add(msh, "cat", cmd);
	add(msh, "-e", option);
	add(msh, "Makefile", arg);
	add(msh, "|", pipe);
	add(msh, "grep", cmd);
	add(msh, "srcs", arg);
	return (SUCCESS);
}