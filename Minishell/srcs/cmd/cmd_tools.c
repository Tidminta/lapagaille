/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:09:35 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/13 19:42:54 by tidminta         ###   ########.fr       */
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
{
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
{
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
{
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
{
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

void			printheader(t_msh *msh)
{
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