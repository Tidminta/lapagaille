# include "../includes/libshell.h"

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
	str = ft_strjoin(str, "usage: export [no option] [name[=value] ...]");
	printf("[DONT FRGT TO FIX THIS][ERROR][%s]\n", str);
}


int	check_o(t_msh *msh, t_cut_cmd *cmd)
{
	int		quote;

	quote = 0;
	while (cmd && (cmd->TOKEN == ARG
			|| cmd->TOKEN == OPTION || cmd->TOKEN == D_QUOTE
			|| cmd->TOKEN == S_QUOTE))
	{
		if (cmd->TOKEN == D_QUOTE || cmd->TOKEN == S_QUOTE)
			quote = 1;
		if (cmd->elem[quote] == '-')
		{
			cut_option(msh, cmd);
			return (ERROR);
		}
		quote = 0;
		cmd = cmd->p;
	}
	return (SUCCESS);
}

/*
append_error(msh, cmd, error, 0);
ft_error(cmd, error, 1);
return (ERROR);
*/
int	check_e(t_msh *msh, t_cut_cmd *cmd, char *str)
{
	char	*error;
	int		i;

	error = NULL;
	i = -1;
	(void)cmd;
	if (!ft_isalpha(str[0]) && (str[i] != '_' || str[i] != '\\'))
	{
		error = ft_strdup("Minishell: export: \'");
		error = ft_strjoin(error, str);
		error = ft_strjoin(error, "\': not a valid identifier");
		msh->tools->noforked_exit = 1;
		printf("[DONT FRGT TO FIX THIS][ERROR][%s]\n", error);
		return (ERROR);
	}
	return (SUCCESS);
}

void	pop_env(t_msh **msh)
{
	t_cut_cmd	*list;
	t_cut_cmd	*to_pop;

	if (!(*msh))
		return ;
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
