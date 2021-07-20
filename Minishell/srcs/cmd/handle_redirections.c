/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 22:46:43 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/20 23:27:56 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int			isredir(t_cut_cmd *cmd)
{
	while (cmd != NULL && cmd->header[H_SYMBOL] != PIPE)
	{
		if (cmd->header[H_SYMBOL] == 1 || cmd->header[H_SYMBOL] == 2)
			return (SUCCESS);
		cmd = cmd->p;
	}
	return (ERROR);
}

int			output_redirection(t_msh *msh, t_cut_cmd *cmd)
{
	while(cmd != NULL && (cmd->header[H_SYMBOL] != R_SIMPLE && cmd->header[H_SYMBOL] != PIPE))
		cmd = cmd->p;
	if (cmd && cmd->header[H_SYMBOL] == R_SIMPLE)
	{
		cmd = cmd->p;
		while ((cmd != NULL && cmd->header[H_SYMBOL] != PIPE) && (cmd->header[H_CMDTYPE] == ARG || cmd->header[H_SYMBOL] == R_SIMPLE))
		{
			if (cmd->header[H_SYMBOL] != R_SIMPLE)
			{
				msh->tools->fdout = open(cmd->elem, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
				if (msh->tools->fdout < 0)
					return (ERROR);//exit (127 | errno)
			}
			cmd = cmd->p;
		}
		dup2(msh->tools->fdout, 1);
	}
	return (SUCCESS);
}

int			input_redirection(t_msh *msh, t_cut_cmd *cmd)
{
	while (cmd && (cmd->header[H_SYMBOL] != L_SIMPLE && cmd->header[H_SYMBOL] != PIPE))
		cmd = cmd->p;
	if (cmd && cmd->header[H_SYMBOL] == L_SIMPLE)
	{
		cmd = cmd->p;
		while((cmd && cmd->header[H_SYMBOL] != PIPE) && (cmd->header[H_CMDTYPE] == ARG || cmd->header[H_SYMBOL] == L_SIMPLE))
		{
			if (cmd->header[H_SYMBOL] == L_SIMPLE)
			{
				msh->tools->fdin = open(cmd->p->elem, O_RDWR, NULL);
				if (msh->tools->fdin < 0)
					return (ERROR);//exit(127 | errno)
			}
			cmd = cmd->p;
		}
		dup2(msh->tools->fdin, 0);
	}
	return (SUCCESS);
}

int			handle_redirection(t_msh *msh, t_cut_cmd *cmd)
{
	int	ret;

	ret = isredir(cmd);
	if (ret == ERROR)
	{//AUCUNE REDIRECTION | FONCTIONNEMENT REDIRECTION PIPE NORMALE
		if (cmd->header[H_POS] != LAST_CMD)
			dup2(msh->tools->pipe[1], 1);
		return (ERROR);
	}
	else
	{
		msh->tools->fdin = 0;
		msh->tools->fdout = 0;
		input_redirection(msh, cmd);
		output_redirection(msh, cmd);
		// dup2(msh->tools->fdout, 1);
	}
	return (SUCCESS);
}
