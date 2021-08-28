#include "../includes/libshell.h"

int	builtin_echo_return_value(t_msh *msh, t_cut_cmd *cmd, int mode)
{
	t_cut_cmd	*iter;
	int			printf_ret;

	iter = cmd;
	printf_ret = 0;
	if (mode)
	{
		while (iter && (iter->TOKEN == OPTION || iter->TOKEN == ARG
				|| iter->TOKEN == D_QUOTE || iter-> TOKEN == S_QUOTE))
		{
			if (iter->n->n->TOKEN != C_BUILTIN)
				printf(" ");
			printf_ret += printf("%s", iter->elem);
			iter = iter->p;
		}
		return ((msh->tools->status = printf_ret));
	}
	return ((msh->tools->status = 0));
}

int	builtin_echo(t_msh *msh, t_cut_cmd *cmd)
{
	msh->tools->echo_opt = 0;
	while (cmd && !(cmd->TOKEN >= WILD_CARD && cmd->TOKEN <= CLOSED_DIV))
	{
		if (is_same(cmd->elem, "-n"))
			msh->tools->echo_opt = 1;
		if (cmd->p)
		{
			if (cmd->p->TOKEN == OPTION
				&& is_same(cmd->p->elem, "-n")
				&& (cmd->p->p && cmd->p->p->TOKEN >= OPTION
					&& cmd->p->p->TOKEN <= D_QUOTE))
				return (builtin_echo_return_value(msh, cmd->p->p, 1));
			else if ((cmd->p && (cmd->p->TOKEN >= ARG && cmd->p->TOKEN
						<= D_QUOTE && !is_same(cmd->p->elem, "-n"))))
				msh->tools->status = printf("%s", cmd->p->elem);
		}
		if (cmd->p && cmd->p->p)
			printf(" ");
		cmd = cmd->p;
	}
	if (!msh->tools->echo_opt)
		printf("\n");
	return (msh->tools->status);
}

int	builtin_cd(t_msh *msh, t_cut_cmd *cmd)
{
	(void)msh;
	(void)cmd;
	if ((!cmd->p) ||
	!(cmd->p->TOKEN == ARG ||
	cmd->p->TOKEN == D_QUOTE ||
	cmd->p->TOKEN == S_QUOTE ||
	cmd->p->TOKEN == OPTION))
		return (append_error(msh, cmd, "cd: usage: [path]\n", 1));
	return ((msh->tools->status = chdir((const char *)cmd->p->elem) == -1));
}


int	builtin_pwd(t_msh *msh, t_cut_cmd *cmd)
{
	char	*pwd;

	(void)cmd;
	pwd = get_cwd();
	msh->tools->status = 0;
	if (pwd)
		printf("%s\n", pwd);
	else
		msh->tools->status = 1;
	return (1);
}

int	builtin_env(t_msh *msh, t_cut_cmd *cmd)
{
	if (cmd->p && (cmd->p->TOKEN == ARG || cmd->p->TOKEN == OPTION))
		return ((msh->tools->status = 0));
	return (print_env(msh, msh->env->head));
}
