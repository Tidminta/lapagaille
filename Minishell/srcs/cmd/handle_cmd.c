/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:03:41 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/05 20:20:39 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

/*
static void	print_list(t_msh *msh)
{
	t_cut_cmd *lst;

	lst = msh->head;
	ft_putstr_fd("** DEBUT DE LIST**\n", 1);
	while (lst)
	{
		ft_putstr_fd("[", 1);
		ft_putstr_fd(lst->elem, 1);
		ft_putstr_fd("]\n", 1);
		lst = lst->n;
	}
	ft_putstr_fd("** FIN DE LIST**\n", 1);
}

int			isbuiltin(t_msh *msh, char *content)
{
	int		i;
	char	**tab = NULL;

	i = -1;
	(void)msh;
	// tab = msh->builtins;
	while (tab[++i])
		if (!ft_strncmp(tab[i], content, ft_strlen(content)))
			return (BUILTIN);
	return (ERROR);
}

int			ispipe(char *elem)
{
	int	cpt;
	int i;

	cpt = 0;
	i = -1;
	while (elem[++i])
	{
		if (elem[i] == PIPE)
			cpt++;
	}
	return (cpt);
}

int			idredir(t_cut_cmd *cmd)
{
	char *s;
	int	i;
	int cpt;

	i = 0;
	cpt = 0;
	while (cmd != NULL)
	{
		if (cmd->header[H_SYMBOL] == 1 || cmd->header[H_SYMBOL] == 2)
			cpt++;
		cmd = cmd->p;
	}
	return (cpt);
}

int			choose_exec(t_msh *msh, t_cut_cmd *cmd_lst)
{
	int		i;
	int		cpt;

	msh->tools->nbpipe = ispipe(cmd_lst);
	msh->tools->nbredir = isredir(cmd_lst);
	return (cmd_lst->header[H_CMDTYPE]);
}
*/
/*
// static int	handler_builtins(msh);

// Redirections:
// ◦ < should redirect input.
// ◦ > should redirect output.
// ◦ “<<” read input from the current source until 
// a line containing only the delimiter is seen. it doesn’t need to update history
// a connaitre : isatty, ttyname, ttyslot, ioctl

int         handle_cmd(t_msh *msh)
{
	int			ret;
	pid_t		pid;
	t_cut_cmd 	*cmd_lst;
	
	ret = 0;
	cmd_lst = msh->tools->tail;
	ret = choose_exec(msh, cmd_lst);
	// forker puis exec en fonction de ret
	pid = fork();
	if (pid == 0)
	{//fils
		
	}
	else
	{//pere
		
	}
	return (0);
}
*/
