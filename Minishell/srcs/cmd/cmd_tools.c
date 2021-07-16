/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:09:35 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/17 00:14:52 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// int			isbuiltin(t_msh *msh, char *content)
// {
// 	int		i;
// 	char	**tab = NULL;

// 	i = -1;
// 	(void)msh;
// 	// tab = msh->builtins;
// 	while (tab[++i])
// 		if (!ft_strncmp(tab[i], content, ft_strlen(content)))
// 			return (BUILTIN);
// 	return (ERROR);
// }

int			ispipe(t_msh *msh)
{//RENVOI LE NOMBRE DE PIPE
	t_cut_cmd	*cmd;
	char		*elem;
	int			cpt;
	int			i;

	cpt = 1;
	i = -1;
	cmd = msh->tools->tail;
	while (cmd != NULL)
	{
		elem = cmd->elem;
		sleep(1);
		while (elem[++i])
		{
			if (elem[i] == '|')
				cpt++;
		}
		cmd = cmd->p;
		i = 0;
	}
	return (cpt);
}

int			isredir(t_msh	*msh)
{//RENVOI LE NOMBRE DE REDIRECTION
	t_cut_cmd	*cmd;
	int			i;
	int			cpt;

	i = 0;
	cpt = 0;
	cmd = msh->tools->tail;
	while (cmd != NULL)
	{
		if (cmd->header[H_SYMBOL] == 1 || cmd->header[H_SYMBOL] == 2)
			cpt++;
		cmd = cmd->p;
	}
	return (cpt);
}

int			choose_exec(t_cut_cmd *cmd)
{//RENVOI LE TYPE D'EXECUTION
	int		ret;
	
	ret = cmd->header[H_CMDTYPE];
	if (ret == 1)
		return (BUILTIN);
	else if (ret == 2)
		return (EXEC);
	else
		return (ERROR);
}

int			whatpostions(t_msh *msh)
{//DEFINIE LES POSITIONS DE CHAQUE CMD
	t_cut_cmd *cmd;

	cmd = msh->tools->tail;
	if ((cmd->n == NULL && cmd->p == NULL) && (cmd->header[0] == 1 || cmd->header[0] == 2))
	{
		// CAS OU UNE SEULE COMMANDE (return handle error)
		cmd->header[4] = LAST_CMD;
		return (SUCCESS);
	}
	else if ((cmd->n == NULL && cmd->p) && (cmd->header[0] == 1 || cmd->header[0] == 2))
	{
		cmd->header[4] = FIRST_CMD;
		cmd = cmd->p;
	}
	while (cmd != NULL)
	{
		if (cmd->p != NULL)
			cmd->header[4] = MIDDLE_CMD;
		else
				cmd->header[4] = LAST_CMD;
		cmd = cmd->p;
	}
	return (SUCCESS);
}

char			*get_path(t_cut_cmd *cmd, char **paths)
{//RENVOI LE BON PATH D'UN EXECUTABLE
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
				if (r_dir && (!ft_strncmp(cmd->elem, r_dir->d_name, (size_t)ft_strlen(r_dir->d_name))))
				{
					tmp = ft_strjoin(paths[i], "/");
					str = ft_strjoin(tmp, cmd->elem);
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

char			**handle_args(t_msh *msh, t_cut_cmd *cmd)
{//RENVOI TAB D'ARGS
	int			ret;
	int			i;
	t_cut_cmd	*tail;
	char 		**args;

	ret = 0;
	i = -1;
	if (!msh || !cmd)
		return (NULL);
	while (cmd != NULL)
	{
		if ((cmd->header[0] == 0 || cmd->header[1] == 3))
		{
			cmd = NULL;
			break ;
		}
		ret++;
		cmd = cmd->p;
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

void			simple_exec(t_msh *msh, t_cut_cmd *cmd)
{
	int		pid;
	char	*exec_path;
	char	**args;

	pid = fork();
	if (pid == 0)
	{
		exec_path = get_path(cmd, msh->path);
		if (!exec_path || exec_path == NULL)
			ft_error(cmd, "PATH ERROR\n", 0);
		args = handle_args(msh, cmd);
		if (!args || args == NULL)
			ft_error(cmd, "BAD ARGS/OPTION\n", 0);
		execve(exec_path, args, msh->envp);
		ft_error(cmd, "Execution failed.\n", errno);
	}
	else
		waitpid(pid, &msh->tools->status, 0);
}

void				cmd_nopipe(t_msh *msh, t_cut_cmd *cmd)
{
	int	ret;

	ret = choose_exec(cmd);
	if (ret == BUILTIN)
	{
		printf("[TEST][IS BUILTIN]\n");
		// handle_builtins(msh, cmd);
	}
	else if (ret == EXEC)
		simple_exec(msh, cmd);
	else
		ft_error(cmd, "Bad commande", 0);
}

void			printheader(t_msh *msh)
{//A JETTER
	t_cut_cmd *cmd;

	cmd = msh->tools->tail;

	while (cmd)
	{
		printf("[%s]", cmd->elem);
		if (cmd->header[4] == FIRST_CMD)
			printf("[FIRT CMD]\n");
		else if (cmd->header[4] == MIDDLE_CMD)
			printf("[MIDDLE CMD]\n");
		else if (cmd->header[4] == LAST_CMD)
			printf("[LAST CMD]\n");
		else
		printf("[ERROR]\n");
		sleep(1);
		cmd = cmd->p;
	}
}

void			my_putstr(char *str1, char *str2)
{//A JETTER
	ft_putstr_fd(str1, 2);
	ft_putstr_fd("\n[", 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd("]\n", 2);
	ft_putstr_fd("\n", 2);
}
