#include "../includes/libshell.h"

int		swap_env(t_msh **msh, char *new)
{
	t_cut_cmd 	*env;
	size_t		len;
	int			match;

	len = 0;
	match = 0;
	env = (*msh)->env->head;
	while (new[len] != '\0' && !match)
	{
		if (new[len] == '=')
			match = 1;
		len++;
	}
	if (new[len])
	{
		while (env)
		{
			if (!ft_strncmp(new, (env)->elem, len))
			{
				gc("pause");
				(env)->elem = ft_strdup(new);
				gc("resume");
				env->TOKEN = _UNASSIGNED;
				return (SUCCESS);
			}
			(env) = (env)->n;
		}
		gc("pause");
		add_env(msh, new, 0);
		gc("resume");
		return (SUCCESS);
	}
	else
	{
		len = ft_strlen(new);
		while (env && !match)
		{
			if (!ft_strncmp(env->elem, new, len))
				match = 1;
			env = env->n;
		}
		if (!match)
		{
			gc("pause");
			add_env(msh, new, ENV_SOLO);
			gc("resume");
		}
		return (SUCCESS);
	}
	return (ERROR);
}

int		builtin_export(t_msh *msh, t_cut_cmd *cmd)
{
	int			ret;
	t_cut_cmd	*env;

	env = msh->env->head;
	if ((!cmd->p) || ((cmd->p) && (cmd->p->TOKEN >= PIPE && cmd->p->TOKEN <= D_L_REDIR)))
	{
		if (!msh->tools->fdout)
			msh->tools->fdout = 1;
		while(env)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putendl_fd(env->elem, msh->tools->fdout);
			env = env->n;
		}
		return (SUCCESS);
	}
	cmd = cmd->p;
	while (cmd && cmd->TOKEN != PIPE)
	{
		if (cmd->TOKEN == ARG)
			ret = swap_env(&msh, cmd->elem);
		cmd = cmd->p;
	}
	// print_env(msh, env);
	return (SUCCESS);
}

int	builtin_unset(t_msh *msh, t_cut_cmd *cmd)
{
	(void)msh;
	(void)cmd;
	if (!(cmd->p && cmd->p->TOKEN == ARG))
		return ((msh->tools->status = 0));
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

void	add_builtin(int (***f_p_builtin)(t_msh *msh, t_cut_cmd *cmd), void *addr, int size)
{
	static	int pos;
	char *add_fail;

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
	static int			(**f_p_builtin)(t_msh *msh, t_cut_cmd *cmd);
	int					(*malloc_size)(t_msh *msh, t_cut_cmd *cmd);
	int					size;
	int					index_of_cmd;

	(void)cmd;
	(void)msh;
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
}
