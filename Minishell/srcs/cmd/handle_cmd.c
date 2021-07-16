/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:03:41 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/17 00:16:58 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

void			getnext_pipe(t_cut_cmd **cmd)
{//PERMET DE GET LA CMD APRES LE PROCHAIN PIPE
	while((*(cmd)) != NULL && (*(cmd))->header[H_SYMBOL] != PIPE)
		(*(cmd)) = (*(cmd))->p;
	if ((*(cmd)) != NULL && ((*(cmd))->header[H_SYMBOL] == PIPE && (*(cmd))->p->header[H_CMDTYPE] == EXEC))
		(*(cmd)) = (*(cmd))->p;
}


int				findnext_pipe(t_cut_cmd *cmd)
{//VERIFIE SI CMD EN COURS EST SUIVI D'UN PIPE
	if (cmd == NULL || cmd->p == NULL)
		return (ERROR);
	while (cmd != NULL && cmd->header[H_SYMBOL] != PIPE)
		cmd = cmd->p;
	if (cmd && cmd->header[H_SYMBOL] == PIPE)
		return (SUCCESS);
	return (ERROR);
}

void			cmd_pipe(t_msh *msh, t_cut_cmd *cmd)
{
	int		pid;
	int		bfd;
	char	*exec_path;
	char	**args;

	bfd = 0;
	while (cmd != NULL)
	{
		pipe(msh->tools->pipe);
		pid = fork();
		if ( pid == 0)
		{
			dup2(bfd, 0);
			if ((cmd->header[H_POS] == FIRST_CMD ) || (cmd->header[H_POS] == MIDDLE_CMD))
				dup2(msh->tools->pipe[1], 1);
			close(msh->tools->pipe[0]);
			exec_path = get_path(cmd, msh->path);
			args = handle_args(msh, cmd);
			execve(exec_path, args, msh->envp);
			printf("[EXEC ERROR][%s]\n", cmd->elem);	
		}
		else if (pid > 0)
		{
			wait(NULL);
			close(msh->tools->pipe[1]);
			bfd = msh->tools->pipe[0];
		}
		else
		{
			printf("ERROR PID\n");
			exit (0);
		}
		getnext_pipe(&cmd);
	}
}

int				handle_exec(t_msh *msh)
{//CHOIX D'EXECUTION : CMD AVEC/SANS PIPE
	t_cut_cmd *cmd;

	cmd = msh->tools->tail;
	if (msh->tools->nbpipe)
		cmd_pipe(msh, cmd);
	else
		cmd_nopipe(msh, cmd);
	return (SUCCESS);
}

// WIFSIGNALED(status)
// renvoie vrai si le fils s'est terminé à cause d'un signal.
// WIFSTOPPED(status)
// renvoie vrai si le fils a été arrêté par la délivrance d'un signal.
// Cette macro n'a de sens que si l'on a effectué l'appel avec l'option WUNTRACED 
// ou lorsque l'appel est en cours de suivi (voir ptrace(2)).
// WSTOPSIG(status)
// renvoie le numéro du signal qui a causé l'arrêt du fils. 
// Cette macro ne peut être évaluée que si WIFSTOPPED renvoie vrai.
int         handle_cmd(t_msh *msh)
{//HOME : GESTION DE CMD	
	if (!msh || msh == NULL)
		return (ERROR);
	msh->tools->nbpipe = ispipe(msh);
	msh->tools->nbredir = isredir(msh);
	// whatpostions(msh);
	// printheader(msh);
	handle_exec(msh);
	msh->tools->last_fd = 0;
	return (0);
}
