/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:03:41 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/13 22:16:14 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"


char			*get_path(t_cut_cmd **cmd, char **paths)
{
	int				i;
	char			*str;
	char			*tmp;
	DIR				*o_dir;
	struct dirent	*r_dir;

	i = -1;
	if (!cmd || !paths)
		return (NULL);
	while (paths[++i])
	{
		o_dir = opendir(paths[i]);
		if (o_dir != NULL)
		{
			while ((r_dir = readdir(o_dir)) != NULL)
			{
				if (r_dir && (!ft_strncmp((*(cmd))->elem, r_dir->d_name, (size_t)ft_strlen(r_dir->d_name))))
				{
					tmp = ft_strjoin(paths[i], "/");
					str = ft_strjoin(tmp, (*(cmd))->elem);
					free(tmp);
					if (!str)
						return (NULL);
					return (str);
				}
			}
			if (o_dir)
				closedir(o_dir);
		}
	}
	return (NULL);
}

char			**handle_args(t_msh *msh, t_cut_cmd **cmd)
{
	int			ret;
	int			i;
	t_cut_cmd	*tail;
	char 		**args;
	
	ret = 0;
	i = -1;
	if (!msh || !(*(cmd)))
		return (NULL);
	while (cmd && ((*(cmd))->header[0] > 0 && (*(cmd))->header[1] != 3))
	{
		ret++;
		(*(cmd)) = (*(cmd))->p;
	}
	args = (char**)malloc(sizeof(char*) * (ret + 1));
	if (!args || args == NULL)
		return (NULL);
	tail = msh->tools->tail;
	while (tail != NULL && tail->header[0] > 0)
	{
		args[++i] = strdup(tail->elem);
		if (args[i] == NULL)
		{
			while (i-- > 0)
				free(args[i]);
			return (NULL);
		}
		tail = tail->p;
	}
	args[++i] = NULL;
	return (args);
}

void			my_putstr(char *str1, char *str2)
{
	ft_putstr_fd(str1, 2);
	ft_putstr_fd("\n[", 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd("]\n", 2);
	ft_putstr_fd("\n", 2);
}

int				reg_exec(t_msh *msh, t_cut_cmd **cmd)
{
	int		pid;
	int		ret;
	char	**args;
	char	*exec_path;

	ret = 0;
	if ((*(cmd))->header[0] != 2 || (*(cmd))->header[0] != 2)
		return (0);
	my_putstr("[REGULAR EXECUTION][120]", (*(cmd))->elem);
	if ((*(cmd))->header[4] == FIRST_CMD)
	{
		pipe(msh->tools->pipe);
		close(STDOUT_FILENO);
		dup(msh->tools->pipe[1]);
	}
	pid = fork();
	if (pid == 0)
	{
		if (isatty(0))
		{
			close(STDIN_FILENO);
			dup(msh->tools->pipe[0]);
		}
		if ((*(cmd))->header[4] == LAST_CMD)
		{
			// dup2(msh->tools->pipe[1], msh->tools->fdout);
			dup2(msh->tools->pipe[0], msh->tools->fdin);
		}
		exec_path = get_path(cmd, msh->path);
		if (!exec_path || exec_path == NULL)
			ft_error(*cmd, "command not found\n", 127);
		args = handle_args(msh, cmd);
		if (!args || args == NULL)
		{
			free(exec_path);
			ft_error(*cmd, "Out of memory.\n", ENOMEM);
		}
		ret = execve(exec_path, args, NULL);
		exit (errno);
	}
	/*else au cas où execve foire*/
	else
	{
		sleep(1);
		close(msh->tools->pipe[1]);
		close(msh->tools->pipe[0]);
		waitpid(pid, &msh->tools->status, 0);
	}
	// close pipe
	return (SUCCESS);
}


// Pas correct
void				handle_next(t_msh *msh, t_cut_cmd *cmd)
{
	while (cmd && cmd->header[1] != 3)
		cmd = cmd->p;
	if (cmd->elem[1] == 3)
	{
		while (cmd && (cmd->header[0] != 3 || cmd->header[0] != 4))
			cmd = cmd->p;
		if (cmd->header[0] == 4)
		{
			msh->tools->pipe[1] = open(cmd->elem, O_CREAT | O_RDWR);
			if (msh->tools->pipe[1] == -1)
				ft_error(cmd, NULL, errno);
			msh->tools->pipe[1] = dup2(msh->tools->pipe[0], msh->tools->pipe[1]);
		}
	}
}

int				handle_exec(t_msh *msh)
{
	t_cut_cmd 	*cmd;
	int			mode;
	int			pipe;

	mode = 0;
	pipe = -1;
	if (!msh)
		return (ERROR);
	cmd = msh->tools->tail;
	while (++pipe <= msh->tools->nbpipe)
	{
		while(cmd && cmd->header[H_CMDTYPE] != 2)
			cmd = cmd->p;
		mode = choose_exec(cmd);
		if (mode == BUILTIN)
		{
			// handle_next_cmd();
			// handle_builtin();
		}
		else if (mode == EXEC)
		{
			// handle_fd(msh, cmd);
			reg_exec(msh, &cmd);
			while (cmd->header[H_SYMBOL] != 3)
				cmd = cmd->p;
		}
		else
			exit (0);
	}
	return (SUCCESS);
}

// WIFSIGNALED(status)
// renvoie vrai si le fils s'est terminé à cause d'un signal.
// WIFSTOPPED(status)
// renvoie vrai si le fils a été arrêté par la délivrance d'un signal. Cette macro n'a de sens que si l'on a effectué l'appel avec l'option WUNTRACED ou lorsque l'appel est en cours de suivi (voir ptrace(2)).
// WSTOPSIG(status)
// renvoie le numéro du signal qui a causé l'arrêt du fils. Cette macro ne peut être évaluée que si WIFSTOPPED renvoie vrai.
// stdin = 0
// stdout = 1
// stderr = 2
int         handle_cmd(t_msh *msh)
{	
	if (!msh || msh == NULL)
		return (ERROR);
	msh->tools->nbpipe = ispipe(msh);
	msh->tools->nbredir = isredir(msh);
	whatpostions(msh);
	handle_exec(msh);
	msh->tools->last_fd = 0;
	return (0);
}
