/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:26:11 by tidminta          #+#    #+#             */
/*   Updated: 2021/08/18 21:01:09 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libshell.h"

int	builtin_export(t_msh *msh, t_cut_cmd *cmd)
{
	char	**env_split;
	char	*to_print;

	env_split = NULL;
	to_print = NULL;
	if (cmd->p)
		if ((check_o(msh, cmd) == -1) || (check_e(msh, cmd) == -1))
			return (ERROR);
	if ((!cmd->p) || ((cmd->p)
			&& (cmd->p->TOKEN >= PIPE && cmd->p->TOKEN <= D_L_REDIR)))
	{
		cut_bexport(msh, msh->env->head, env_split, to_print);
		return (SUCCESS);
	}
	cmd = cmd->p;
	while (cmd && cmd->TOKEN != PIPE)
	{
		if (cmd->TOKEN == ARG)
			swap_env(&msh, cmd->elem);
		cmd = cmd->p;
	}
	return (SUCCESS);
}

int	builtin_unset(t_msh *msh, t_cut_cmd *cmd)
{
	t_cut_cmd	*env;

	env = msh->env->head;
	cmd = cmd->p;
	while (cmd && (cmd->TOKEN == ARG))
	{
		if (is_env(&msh, cmd->elem))
			pop_env(&msh);
		cmd = cmd->p;
	}
	return (2);
}

int	builtin_exit(t_msh *msh, t_cut_cmd *cmd)
{
	(void)msh;
	(void)cmd;
	gc("collect -all");
	exit (0);
	return (2);
}

void	add_builtin(int (***f_p_builtin)(t_msh *msh, t_cut_cmd *cmd),
		void *addr, int size)
{
	static int	pos;
	char		*add_fail;

	add_fail = ft_strdup("BUILTIN_ARRAY_OVERFLOW, exiting now\n");
	(void)f_p_builtin;
	if (pos == size)
	{
		write(2, add_fail, ft_strlen(add_fail));
		gc("collect -all");
		exit (0);
	}
	(*f_p_builtin)[pos] = addr;
	pos++;
}

void	handle_builtins(t_msh *msh, t_cut_cmd *cmd)
{
	static	int	(**f_p_builtin)(t_msh *msh, t_cut_cmd *cmd);
	int			(*malloc_size)(t_msh *msh, t_cut_cmd *cmd);
	int			size;
	int			index_of_cmd;

	size = split_len(ft_split(BUILTIN_LIST, ' '));
	if (!f_p_builtin)
	{
		gc("pause");
		f_p_builtin = ft_calloc(size, sizeof(malloc_size) * size);
		gc("resume");
		add_builtin(&f_p_builtin, builtin_echo, size);
		add_builtin(&f_p_builtin, builtin_cd, size);
		add_builtin(&f_p_builtin, builtin_pwd, size);
		add_builtin(&f_p_builtin, builtin_env, size);
		add_builtin(&f_p_builtin, builtin_export, size);
		add_builtin(&f_p_builtin, builtin_unset, size);
		add_builtin(&f_p_builtin, builtin_exit, size);
	}
	index_of_cmd = is_match2(BUILTIN_LIST, ' ', cmd->elem);
	f_p_builtin[index_of_cmd](msh, cmd);
	exit (0);
}
