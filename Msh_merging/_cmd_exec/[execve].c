#include "../includes/libshell.h"

t_cut_cmd	*ft_ls(char *path, char *options)
{
	struct dirent	*de;
	DIR				*dr;
	char			*tmp;
	t_cut_cmd		*concat;

	(void)concat;
	if (path)
		dr = opendir(path);
	else
		dr = opendir(".");
	concat = NULL;
	while (dr != NULL && (de = readdir(dr)) != NULL)
	{
		tmp = ft_strdup(de->d_name);
		if (!is_same(options, "-a") && tmp[0] == '.')
			continue ;
		else
			add_to_env(&concat, tmp, _UNASSIGNED);
		tmp = NULL;
	}
	dr ? closedir(dr) : 0;
	return (concat);
}

char			*determine_path_type(t_cut_cmd *cmd, char *str)
{
	int		i;
	char	*modulo;

	(void)cmd;
	modulo = NULL;
	i = 0;
	if (!c_is_present(str, '/'))
		return (NULL);
	str = ft_strrev(str);
	while (str[i]!= '/')
		i++;
	str = str_modulo(str, &cmd->elem, i);
	cmd->elem = ft_strrev(cmd->elem);
	return (ft_strrev(str));
}

char			*_place_holder_get_path(t_msh *msh, t_cut_cmd *cmd)
{
	t_cut_cmd	*update_path;
	char		**tmp;
	char		*tmp2;

	(void)tmp;
	update_path = get_env_of(msh->envp, "PATH");
	gc_free_calloc(msh->path);
	msh->path = ft_split(ft_split(update_path->elem, '=')[1], ':');
	tmp2 = determine_path_type(cmd, ft_strdup(cmd->elem));
	if (tmp2)
	{
		tmp = ft_calloc(2, sizeof(char *) * 2);
		tmp[0] = tmp2;
		return (get_path(cmd, tmp));
	}	
	else
		return (get_path(cmd, msh->path));
}

void			ft_list_join(t_cut_cmd **left, t_cut_cmd *start, t_cut_cmd *right)
{
	(void)left;
	(void)start;
	(void)right;
	t_cut_cmd *iterator;

	iterator = (*left);
	while ((iterator) && (iterator)->p && (iterator->p) != start && (iterator) != start)
		(iterator) = (iterator)->p;
	(iterator)->p = right;
}

t_cut_cmd	**head_tail(t_msh *msh, char *mode)
{
	static t_cut_cmd	**bak;

	if (!bak)
	{
		gc("pause");
		bak = ft_calloc(2, sizeof(t_cut_cmd *) * 2);
		gc("resume");
	}
	if (is_same(mode, "backup") && !bak[0] && !bak[1])
	{
		bak[0] = msh->tools->head;
		bak[1] = msh->tools->tail;
		msh->tools->head = NULL;
		msh->tools->tail = NULL;
	}
	else if (is_same(mode, "restore"))
	{
		msh->tools->head = bak[0];
		msh->tools->tail = bak[1];
		gc_free(bak);
		bak = NULL;
	}
	return (bak);
}

// void			_place_holder_handle_wildcards(t_msh *msh, t_cut_cmd *cmd)
// {
// 	(void)cmd;
// 	(void)msh;
// 	t_cut_cmd *iterator;

// 	iterator = cmd;
// 	printf("ok %s", iterator->p->elem);
// 	$BR
// }

void		_place_holder_handle_expand_env(t_msh *msh, t_cut_cmd *cmd)
{
	(void)msh;
	(void)cmd;
}

void			delete_heredoc(t_msh *msh)
{
	t_cut_cmd	*to_delete;
	char		**delete_args;
	char		*to_delete_path;
	int			pid2;

	pid2 = fork();
	if (pid2 == 0)
	{
		to_delete = (t_cut_cmd*)malloc(sizeof(t_cut_cmd));
		to_delete->elem = ft_strdup("/bin/rm");
		to_delete_path = get_path(to_delete, list_to_split(msh->env->head));
		delete_args = ft_split("rm -rf ./msh_heredoc.msh", ' ');
		msh->tools->marker = NULL;//AKA COLLECT
		execve(to_delete->elem, delete_args, list_to_split(msh->env->head));
		printf("[FORK FORK FAILED]\n");
	}
	else
		waitpid(pid2, &msh->tools->status, 0);
}

void			simple_exec(t_msh *msh, t_cut_cmd *cmd)
{
	int		pid;
	char	*exec_path;
	char	**args;


	if (!msh || !cmd)
		ft_putendl_fd("[!MSH || !CMD]\n", 2);
	pid = fork();
	if (pid == 0)
	{
		handle_redirection(msh, cmd, -1);
		// _place_holder_handle_wildcards(msh, cmd);
		// _place_holder_handle_expand_env(msh, cmd);
		if (cmd->TOKEN == C_BUILTIN)
			handle_builtins(msh, cmd);
		else
		{
			exec_path = _place_holder_get_path(msh, cmd);
			if (!exec_path || exec_path == NULL)
				ft_error(cmd, "PATH -1\n", 0);
			args = handle_args(msh, cmd);
			if (!args || args == NULL)
				ft_error(cmd, "BAD ARGS/OPTION\n", 0);
			execve(exec_path, args, list_to_split(msh->env->head));
			ft_error(cmd, "Execution failed.\n", errno);
		}
	}
	else
	{
		waitpid(pid, &msh->tools->status, 0);
		if (msh->tools->status)
			printf("[FATHER FORK][STATUS = %d]\n", msh->tools->status);
		if ((open("./msh_heredoc.msh", O_RDONLY, 0666) ) != -1)
			delete_heredoc(msh);
	}
}