/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:09:35 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/20 23:16:29 by tidminta         ###   ########.fr       */
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

// int				handle_exec(t_msh *msh)
// {//CHOIX D'EXECUTION : CMD AVEC/SANS PIPE
// 	t_cut_cmd *cmd;

// 	cmd = msh->tools->tail;
// 	if (msh->tools->nbpipe)
// 		cmd_pipe(msh, cmd);
// 	else
// 		cmd_nopipe(msh, cmd);
// 	return (SUCCESS);
// }

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
			printf("[NOT CMD]\n");
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

int			getnext_pipe(t_cut_cmd **cmd)
{//PERMET DE GET LA CMD APRES LE PROCHAIN PIPE
	while((*(cmd)) != NULL && (*(cmd))->header[H_SYMBOL] != PIPE)
		(*(cmd)) = (*(cmd))->p;
	if ((*(cmd)) != NULL && (((*(cmd))->p->header[H_CMDTYPE] == EXEC
		|| (*(cmd))->p->header[H_CMDTYPE] == BUILTIN)))//SOUS ENTEND QUE NOUS SOMME SUR UN PIPE
		(*(cmd)) = (*(cmd))->p;
	//ICI SOIT NOUS SOMMES SUR UNE CMD SOIT SUR NUL |
	if ((*(cmd)))
		return (SUCCESS);
	else 
		return (ERROR);
}

void		whatpostions(t_msh *msh)
{
	t_cut_cmd	*cmd;
	t_cut_cmd	*tmp;
	
	cmd = msh->tools->tail;
	if ((cmd->n == NULL && cmd->p == NULL) && (cmd->header[0] == EXEC || cmd->header[0] == BUILTIN))
		cmd->header[4] = UNIQUE_CMD;
	else
	{
		if (cmd->p && (cmd->header[0] == BUILTIN || cmd->header[0] == EXEC))
			cmd->header[4] = FIRST_CMD;
		getnext_pipe(&cmd);
		while (cmd != NULL)
		{
			tmp = cmd;
			if ((cmd->n->header[H_SYMBOL] == PIPE) && (cmd->header[H_CMDTYPE] == EXEC || cmd->header[H_CMDTYPE] == BUILTIN))
				cmd->header[4] = MIDDLE_CMD;
			if (getnext_pipe(&cmd) == ERROR)
				tmp->header[4] = LAST_CMD;
		}
	}
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
	tail = cmd;
	if (!msh || !cmd)
		return (NULL);
	while (cmd != NULL && (cmd->header[H_SYMBOL] != PIPE && cmd->header[H_SYMBOL] != R_SIMPLE))
	{
		ret++;
		cmd = cmd->p;
	}
	args = (char**)malloc(sizeof(char*) * (ret + 1));
	if (!args || args == NULL)
		return (NULL);
	while (tail != NULL && (tail->header[H_SYMBOL] != PIPE && tail->header[H_SYMBOL] != R_SIMPLE))
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
