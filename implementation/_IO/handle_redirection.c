/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:51:37 by tidminta          #+#    #+#             */
/*   Updated: 2021/08/18 19:51:45 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libshell.h"

int	isredir(t_cut_cmd *cmd)
{
	while (cmd != NULL && cmd->TOKEN != PIPE)
	{
		if (cmd->TOKEN == R_REDIR || cmd->TOKEN == L_REDIR
			|| cmd->TOKEN == D_R_REDIR)
			return (SUCCESS);
		cmd = cmd->p;
	}
	return (ERROR);
}

int	handle_redirection(t_msh *msh, t_cut_cmd *cmd, int fd)
{
	int	ret;

	ret = isredir(cmd);
	if ((ret == -1) && (fd >= 0))
	{
		if (!cmd->is_last)
			dup2(msh->tools->pipe[1], 1);
		return (SUCCESS);
	}
	else
	{
		msh->tools->fdin = 0;
		msh->tools->fdout = 0;
		msh->tools->b_stdout = dup(STDOUT_FILENO);
		input_redirection(msh, cmd);
		output_redirection(msh, cmd);
		if (msh->tools->noforked_exit && (!cmd->is_last))
			dup2(msh->tools->pipe[1], 1);
	}
	return (SUCCESS);
}
