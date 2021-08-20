/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin1.5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:25:59 by tidminta          #+#    #+#             */
/*   Updated: 2021/08/18 20:55:15 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libshell.h"

static void	cut_option(t_msh *msh, t_cut_cmd *cmd)
{
	char	*tmp;
	char	*str;

	tmp = NULL;
	str = NULL;
	msh->tools->noforked_exit = 1;
	tmp = ft_substr(cmd->elem, 0, 2);
	str = ft_strdup("bash: export: ");
	str = ft_strjoin(str, tmp);
	str = ft_strjoin(str, ": invalid option\nexport: ");
	str = ft_strjoin(str, "usage: export [no option] [name[=value] ...]\n");
	ft_error(msh, cmd, str, 2);
}

int	check_o(t_msh *msh, t_cut_cmd *cmd)
{
	int		quote;

	quote = 0;
	while (cmd)
	{
		if (cmd->TOKEN == D_QUOTE || cmd->TOKEN == S_QUOTE)
			quote = 1;
		if ((cmd->TOKEN == OPTION || cmd->TOKEN == S_QUOTE
				|| cmd->TOKEN == D_QUOTE) && cmd->elem[quote] == '-')
		{
			cut_option(msh, cmd);
			return (ERROR);
		}
		quote = 0;
		cmd = cmd->p;
	}
	return (SUCCESS);
}

int	cut_export(t_msh *msh, t_cut_cmd *cmd, char *str)
{
	char	*error;
	int		i;

	error = NULL;
	i = -1;
	while (str[++i] && str[i] != '=')
	{
		if (!ft_isalpha(str[i]) && str[i] != '_')
		{
			error = ft_strdup("Minishell: export: \'");
			error = ft_strjoin(error, str);
			error = ft_strjoin(error, "\': not a valid identifier\n");
			msh->tools->noforked_exit = 1;
			ft_error(msh, cmd, error, 1);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int	check_e(t_msh *msh, t_cut_cmd *cmd)
{
	while (cmd && (cmd->TOKEN != ARG
			&& cmd->TOKEN != D_QUOTE && cmd->TOKEN != S_QUOTE))
	{
		if (cmd->TOKEN == D_L_REDIR
			|| cmd->TOKEN == L_REDIR || cmd->TOKEN == R_REDIR)
			return (SUCCESS);
		cmd = cmd->p;
	}
	return (cut_export(msh, cmd, cmd->elem));
}

void	pop_env(t_msh **msh)
{
	t_cut_cmd	*list;
	t_cut_cmd	*to_pop;

	list = (*msh)->env->head;
	to_pop = (*msh)->tools->tmp_node;
	if (!to_pop->n || to_pop->n == NULL)
	{
		to_pop->p->n = NULL;
		(*msh)->env->tail = to_pop->p;
	}
	else if (!to_pop->p || to_pop->p == NULL)
	{
		to_pop->n->p = NULL;
		(*msh)->env->head = to_pop->n;
	}
	else
	{
		to_pop->p->n = to_pop->n;
		to_pop->n->p = to_pop->p;
	}
}
