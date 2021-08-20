/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 21:32:39 by tidminta          #+#    #+#             */
/*   Updated: 2021/08/18 21:36:40 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libshell.h"

int	catch_and(t_msh *msh, t_cut_cmd **pos)
{
	int	deep;

	deep = 0;
	if ((*pos)->TOKEN != AND)
		return (0);
	if (!msh->tools->status)
		(*pos) = (*pos)->p;
	while (msh->tools->status && (*pos))
	{
		if ((*pos)->TOKEN == OPEN_DIV)
			deep++;
		if ((*pos)->TOKEN == OR && !deep)
			break ;
		(*pos) = (*pos)->p;
	}
	return (1);
}

int	catch_or(t_msh *msh, t_cut_cmd **pos)
{
	int	deep;

	deep = 0;
	if ((*pos)->TOKEN != OR)
		return (0);
	if (msh->tools->status)
		(*pos) = (*pos)->p;
	while (!msh->tools->status && (*pos))
	{
		if ((*pos)->TOKEN == OPEN_DIV)
			deep++;
		if ((*pos)->TOKEN == AND && !deep)
			break ;
		(*pos) = (*pos)->p;
	}
	return (1);
}

void	init_pos(t_cut_cmd *tail, t_cut_cmd **pos)
{
	if (tail && tail->TOKEN == OPEN_DIV)
		(*pos) = tail->p;
	else
		(*pos) = tail;
}

/*
	move_pos(msh, &pos);
	if (((pos) && (catch_and(msh, &pos) || catch_or(msh, &pos))))
		return (handle_cmd(msh, pos));
	if ((pos) && goto_next_div(msh, &pos))
		return (handle_cmd(msh, pos));
*/

/* ft_error l92 */
void	replace_args(t_msh *msh, t_cut_cmd *cmd)
{
	t_cut_cmd	*tmp;
	t_cut_cmd	**tracer;

	if (!msh || !cmd)
		exit (0);
	tracer = &msh->tools->tail;
	tmp = NULL;
	while (cmd)
	{
		if (is_same(cmd->elem, "<"))
			tmp = cmd->p->p;
		cmd = cmd->p;
	}
	if (tmp)
	{
		if (!tmp->p)
			tmp->n->p = NULL;
		else
			tmp->n->p = tmp->p;
		(*tracer)->n = tmp;
		tmp->p = *tracer;
		tmp->n = NULL;
		*tracer = tmp;
	}
}

int	handle_cmd(t_msh *msh, t_cut_cmd *pos)
{
	if (!msh || !pos || !msh->tools->tail)
		return (-1);
	msh->tools->noforked_exit = 0;
	msh->tools->l_redir = 0;
	ispipe(msh);
	whatpostions(msh);
	if (msh->tools->nbpipe)
		cmd_pipe(msh, pos);
	else
	{
		if ((pos->p && pos->p->TOKEN == ARG) && is_same(pos->elem, "export"))
			builtin_export(msh, pos);
		else if ((pos->p && pos->p->TOKEN == ARG)
			&& is_same(pos->elem, "unset"))
			builtin_unset(msh, pos);
		else
			simple_exec(msh, pos);
	}
	return (0);
}
