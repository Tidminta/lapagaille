#include "../includes/libshell.h"


// printf("ERROR BUILTIN EXPORT\n"); l.24 a la place du exit 0
int	builtin_export(t_msh *msh, t_cut_cmd *cmd)
{
	char	**env_split;

	env_split = NULL;
	if (!msh || !cmd)
		exit (0);
	msh->tools->status = 0;
	if ((!cmd->p) || ((cmd->p)
			&& ((cmd->p->TOKEN >= PIPE && cmd->p->TOKEN <= D_L_REDIR)
				|| cmd->p->elem[0] == '#')))
		return (print_export(msh, msh->env->head, env_split, msh->tools->to_p));
	cmd = cmd->p;
	while (cmd && cmd->TOKEN != PIPE)
	{
		if (((cmd->TOKEN == ARG || cmd->TOKEN == OPTION
					|| cmd->TOKEN == D_QUOTE || cmd->TOKEN == S_QUOTE))
			&& (check_o(msh, cmd) == SUCCESS
				&& check_e(msh, cmd, cmd->elem) == SUCCESS))
			swap_env(&msh, cmd->elem);
		cmd = cmd->p;
	}
	return (SUCCESS);
}

int	builtin_unset(t_msh *msh, t_cut_cmd *cmd)
{
	t_cut_cmd	*env;

	if (!msh || !cmd)
		return (0);
	env = msh->env->head;
	cmd = cmd->p;
	msh->tools->status = 0;
	while (cmd && (cmd->TOKEN == ARG))
	{
		if (is_env(&msh, cmd->elem) == SUCCESS)
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
	if (index_of_cmd != -1)
		f_p_builtin[index_of_cmd](msh, cmd);
	exit (0);
}
