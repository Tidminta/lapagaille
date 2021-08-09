/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:46:33 by tidminta          #+#    #+#             */
/*   Updated: 2021/08/09 13:20:14 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

/*
 **	
 **		ENV TESTINGS
 **
 */

// static void			print_env(t_msh *msh, t_cut_cmd *env)
// {
// 	int		test;

// 	test = 1;
// 	if (!env || env == NULL)
// 	{
// 		printf("EMPTY LIST !... \n");
// 		exit(0);
// 	}
// 	printf("\n| PRINT LIST | \n");
// 	while (env)
// 	{
// 		printf("[%s]\n", env->elem);
// 		env = env->n;
// 	}
// 	printf("\n[head = %s]\n[tail = %s]\n", msh->env->head->elem, msh->env->tail->elem);
// 	printf("| FIN [size = %d]|\n", msh->env->size);
// }

static int		is_empty_env(t_cut_cmd *env)
{
	if (!env || env == NULL)
		return (SUCCESS);
	return (ERROR);
}

static int				create_env_list(t_msh **msh, char *content)
{
	t_cut_cmd	*new_block;

	if (is_empty_env((*msh)->env->head))
	{
		if (!(new_block = (t_cut_cmd *)malloc(sizeof(t_cut_cmd))))
			return (-1);
		new_block->elem = content;
		new_block->TOKEN = _UNASSIGNED;
		new_block->p = NULL;
		new_block->n = NULL;
		(*msh)->env->head = new_block;
		(*msh)->env->tail = new_block;
		(*msh)->env->size = 1;
		return (SUCCESS);
	}
	return (ERROR);
}

static int				add_env(t_msh **msh, char *content, int mode)
{
	t_cut_cmd	*new_block;

	if (!(new_block = (t_cut_cmd *)malloc(sizeof(t_cut_cmd))))
		return (-1);
	if (!ft_strchr(content, '='))
		new_block->elem = ft_strjoin(content, "=\"\"");
	else
		new_block->elem = ft_strdup(content);
	new_block->n = NULL;
	new_block->p = (*msh)->env->tail;
	if (mode)
		new_block->TOKEN = ENV_SOLO;
	else
		new_block->TOKEN = _UNASSIGNED;
	(*msh)->env->tail->n = new_block;
	(*msh)->env->tail = new_block;
	(*msh)->env->size++;
	return (SUCCESS);
}

void	init_env(t_msh *msh, char **envp)
{
	int		i;

	i = 0;
	msh->env = (t_env_list*)malloc(sizeof(t_env_list));
	msh->env->head = NULL;
	msh->env->tail = NULL;
	msh->env->sub = NULL;
	create_env_list(&msh,envp[i]);
	while (envp[++i])
		add_env(&msh, envp[i], 0);
}

/*
 **
 **			ENV TESTINGS
 **
 */

void			ft_error(t_cut_cmd *cmd, char *str, int errornum)
{
	ft_putendl_fd("[FT ERROR]\n", 2);
	if (str)
		ft_putstr_fd(cmd->elem, 1);
	else
		strerror(errornum);
	exit (errornum);
}

int			add_to_env(t_cut_cmd **target, char *elem, t_TOKEN TOKEN)
{
	t_cut_cmd *ret;

	ret = fill(elem, TOKEN);
	if (!*target)
	{
		*target = ret;
		return (1);
	}
	ret->n = *target;
	*target = ret;
	return (1);
}

int	is_builtin(char *str)
{
	char **list;
	int i;

	i = 0;
	list = ft_split(BUILTIN_LIST, ' ');
	while (list[i])
	{
		if (!ft_strncmp(str, list[i], ft_strlen(str)))
			return (1);
		i++;
	}
	return (0);
}

int	split_len(char **split)
{
	int i;

	i = 0;
	if (!split)
		return (0);
	while (split[i])
		i++;
	return (i);
}

void	write_error(t_msh *msh)
{
	if (msh->tools->error_msg)
	{
		write(2, msh->tools->error_msg, ft_strlen(msh->tools->error_msg));
		write(2, "\n", 1);
	}
	msh->tools->error_msg = NULL;
}

void	handler(int n)
{
	(void)n;
	gc("collect -all");
	exit (0);
}
//ignore up

/**
 * builtins
 *
 **/

int	builtin_echo(t_msh *msh, t_cut_cmd *cmd)
{
	(void)msh;
	(void)cmd;
	$MARK("echo");
	return (1);
}

int	builtin_cd(t_msh *msh, t_cut_cmd *cmd)
{
	(void)msh;
	(void)cmd;
	$MARK("cd");
	return (2);
}

int	builtin_pwd(t_msh *msh, t_cut_cmd *cmd)
{
	(void)msh;
	(void)cmd;
	$MARK("pwd");
	return (1);
}

int	builtin_env(t_msh *msh, t_cut_cmd *cmd)
{
	t_cut_cmd	*env;

	env = msh->env->head;
	(void)cmd;
	while(env)
	{
		if (env->TOKEN == _UNASSIGNED)
			ft_putendl_fd(env->elem, 1);
		
		env = env->n;
	}
	return (2);
}

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
	//$MARK("unset");
	return (2);
}

int	builtin_exit(t_msh *msh, t_cut_cmd *cmd)
{
	(void)msh;
	(void)cmd;
	//$MARK("exit");
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

void	roll_builtin(t_msh *msh, t_cut_cmd *cmd, int	(**f_p_builtin)(t_msh *msh, t_cut_cmd *cmd))
{
	int i;

	i = -1;
	while (f_p_builtin[++i])
		f_p_builtin[i](msh, cmd);
}


void	handle_builtins(t_msh *msh, t_cut_cmd *cmd)
{
	static int			(**f_p_builtin)(t_msh *msh, t_cut_cmd *cmd);
	int					(*malloc_size)(t_msh *msh, t_cut_cmd *cmd);
	int					size;
	int					index_of_cmd;
	//	int					index_of_cmd;

	(void)cmd;
	(void)msh;
	size = split_len(ft_split(BUILTIN_LIST, ' '));
	if (!f_p_builtin)
	{
		//f_p_builtin = malloc_builtin_array(size);
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
		//$MARK("INIT")
	}
	index_of_cmd = is_match2(BUILTIN_LIST, ' ', cmd->elem);
	f_p_builtin[index_of_cmd](msh, cmd);
	exit (0);
}

/**
 * builtins
 *
 **/

/**
 * env
 *
 **/

// void	init_envp(t_msh *msh, char **envp)
// {
// 	int i;
// 	t_cut_cmd *ptr;

// 	i = 0;
// 	if (!envp)
// 		return ;
// 	while (envp[i])
// 	{
// 		add_to_env(&msh->envp, envp[i], _UNASSIGNED);
// 		i++;
// 	}
// 	ptr = get_env_of(msh->envp, "PATH");
// 	msh->path = ft_split(ft_split(ptr->elem, '=')[1], ':');
// 	// (void)msh;
// }

t_cut_cmd	*get_env_of(t_cut_cmd *target, char *to_find)
{
	t_cut_cmd	*ptr;
	char		*current_var;

	ptr = target;
	current_var = NULL;
	if (!ptr)
		return (NULL);
	while (ptr)
	{
		current_var = ft_split(ptr->elem, '=')[0];
		if (!ft_strncmp(current_var, to_find, ft_strlen(to_find)))
			return (ptr);
		ptr = ptr->n;
	}
	return (NULL);
}

/**
 * env
 *
 **/

/**
 * cmd_tools
 *
 **/

void		ispipe(t_msh *msh)
{
	t_cut_cmd	*cmd;
	int			cpt;

	cmd = msh->tools->tail;
	cpt = 0;
	while (cmd != NULL)
	{
		if (cmd->TOKEN == PIPE)
			cpt++;
		cmd = cmd->p;
	}
	msh->tools->nbpipe = cpt;
}

int			getnext_pipe(t_cut_cmd **cmd)
{
	if ((*cmd) == NULL || !(*cmd))
		return (ERROR);
	while((*cmd) && (*cmd)->TOKEN != PIPE)
		(*cmd) = (*cmd)->p;
	if ((*cmd) && (*cmd)->p /* && ((*cmd)->p->TOKEN == C_ENV || (*cmd)->p->TOKEN == C_BUILTIN)*/)
		*cmd = (*cmd)->p;
	if (*cmd)
		return (SUCCESS);
	return (ERROR);
}

void		whatpostions(t_msh *msh)
{
	t_cut_cmd	*cmd;
	t_cut_cmd	*tmp;

	cmd = msh->tools->tail;
	while (cmd != NULL)
	{
		tmp = cmd;
		if (getnext_pipe(&cmd) == -1)
			tmp->is_last = 1;
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
	{
		printf("GET PATH !CMD\n");
		return (NULL);
	}
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

int				choose_args(t_msh *msh)
{
	t_cut_cmd	*cmd;

	cmd = msh->tools->tmp_node;
	if (!msh->tools->istmp)
		return (NO_ARGS);
	else if (cmd->p && cmd->p->TOKEN == ARG)
		return (ARGS_BUT);
	else
		return (ARGS);
}

char			**handle_heredoc(t_msh *msh, t_cut_cmd *cmd, int mode)
{
	char		**args;
	t_cut_cmd	*tmp;
	int			i;

	i = 0;
	tmp = cmd;
	if (mode == ARGS)
	{	
		args = (char **)malloc(sizeof(char*) * 3);
		args[0] = ft_strdup(cmd->elem);
		args[1] = ft_strdup("./msh_heredoc.msh");
		args[2] = NULL;
		msh->tools->istmp = 0;
	}
	else
	{
		while(tmp != NULL)
		{
			if (tmp != msh->tools->tmp_node && tmp->TOKEN != D_L_REDIR)
				i++;
			tmp = tmp->p;
		}
		args = (char**)malloc(sizeof(char*) * i + 1);
		i = -1;
		while (cmd != NULL)
		{
			if (cmd != msh->tools->tmp_node && cmd->TOKEN != D_L_REDIR)
				args[++i] = cmd->elem;
			cmd = cmd->p;
		}
		args[++i] = NULL;
	}
	return (args);
}

char			**handle_args(t_msh *msh, t_cut_cmd *cmd)
{
	int			ret;
	int			tmp_check;
	int			i;
	t_cut_cmd	*tail;
	char 		**args;

	ret = 0;
	i = -1;
	tail = cmd;
	if (!msh || !cmd)
		return (NULL);
	tmp_check = choose_args(msh);
	if (msh->tools->istmp && (tmp_check == ARGS || tmp_check == ARGS_BUT))
		args = handle_heredoc(msh, cmd, tmp_check);
	else
	{
		while (cmd && (cmd->TOKEN == C_ENV || cmd->TOKEN == C_BUILTIN || cmd->TOKEN == ARG || cmd->TOKEN == OPTION))
		{
			ret++;
			cmd = cmd->p;
		}
		args = (char**)gc_malloc(sizeof(char*) * (ret + 1));
		while (tail && (tail->TOKEN == C_ENV || tail->TOKEN == C_BUILTIN || tail->TOKEN == ARG || tail->TOKEN == OPTION))
		{
			args[++i] = ft_strdup(tail->elem);
			tail = tail->p;
		}
		args[++i] = NULL;
	}
	return (args);
}

/**
 * cmd_tools
 *
 **/

// int			is_env(t_msh *msh, char *to_find)
// {
	
// }

// char		*is_substitution(t_msh *msh, char *content)
// {
// 	size_t	len;
// 	char	*sub;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	len = 0;
// 	while (content[i])
// 	{
// 		len = ft_strlen(content);
// 		if (content[i] == '$')
// 		{
// 			j = i;
// 			while(content[++j] && content[j] != ' ')
// 				j++;
// 			sub = ft_substr(content, ((unsigned int)i + 1), (size_t)j);
// 			if (is_env(msh, sub))
// 		}
// 	}
// }

char		**list_to_split(t_msh *msh, t_cut_cmd *target)
{
	char	**ret;
	int		i;
	t_cut_cmd	*count;

	i = 0;
	(void)msh;
	count = target;
	while (count)
	{
		count = count->n;
		i++;
	}
	ret = gc_malloc(sizeof(char*) * i + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (target)
	{
		ret[i] = ft_strdup(target->elem);
		target = target->n;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

int				is_input(t_cut_cmd **cmd)
{
	while ((*(cmd)) && (*(cmd))->TOKEN != PIPE)
	{
		if ((*cmd)->TOKEN == L_REDIR || (*cmd)->TOKEN == D_L_REDIR)
			return (SUCCESS);
		(*(cmd)) = (*(cmd))->p;
	}
	return (ERROR);
}

int			is_output(t_cut_cmd **cmd)
{

	while ((*(cmd)) && (*(cmd))->TOKEN != PIPE)
	{
		if ((*(cmd))->TOKEN == R_REDIR || (*(cmd))->TOKEN == D_R_REDIR)
			return (SUCCESS);
		(*(cmd)) = (*(cmd))->p;
	}
	return (ERROR);
}

int			isredir(t_cut_cmd *cmd)
{
	while (cmd != NULL && cmd->TOKEN != PIPE)
	{
		if (cmd->TOKEN == R_REDIR || cmd->TOKEN == L_REDIR || cmd->TOKEN == D_R_REDIR || cmd->TOKEN == D_L_REDIR)
			return (SUCCESS);
		cmd = cmd->p;
	}
	return (ERROR);
}

int			output_redirection(t_msh *msh, t_cut_cmd *cmd)
{
	if (is_output(&cmd) == SUCCESS)
	{
		while ((cmd != NULL && cmd->TOKEN != PIPE)
				&& (cmd->TOKEN == ARG || cmd->TOKEN == R_REDIR || cmd->TOKEN == D_R_REDIR))
		{
			if (cmd->TOKEN == ARG && cmd->n->TOKEN == R_REDIR)
			{
				msh->tools->fdout = open(cmd->elem, O_RDWR | O_CREAT, 0666);
				if (msh->tools->fdout < 0)
					return (ERROR);//exit (127 | errno)
			}
			else if (cmd->TOKEN == ARG && cmd->n->TOKEN == D_R_REDIR)
			{
				msh->tools->fdout = open(cmd->elem, O_RDWR | O_CREAT | O_APPEND, 0666);
				if (msh->tools->fdout < 0)
					return (ERROR);//exit (127 | errno)

			}
			cmd = cmd->p;
		}
		dup2(msh->tools->fdout, 1);
		return (SUCCESS);
	}
	return (ERROR);
}

int			input_redirection(t_msh *msh, t_cut_cmd *cmd)
{
	// char *line;

	if (is_input(&cmd) == SUCCESS)
	{
		while((cmd && cmd->TOKEN != PIPE) && (cmd->TOKEN == ARG || cmd->TOKEN == L_REDIR || cmd->TOKEN == D_L_REDIR))
		{
			if (cmd->TOKEN == ARG && cmd->n->TOKEN == L_REDIR)
			{
				msh->tools->fdin = open(cmd->elem, O_RDWR, NULL);
				if (msh->tools->fdin < 0)
					return (ERROR);//exit(127 | errno)
				msh->tools->istmp = 0;
				dup2(msh->tools->fdin, 0);
			}
			else if (cmd->TOKEN == ARG && cmd->n->TOKEN == D_L_REDIR)
			{
				msh->tools->marker = cmd->elem;
				msh->tools->tmp_node = cmd;
				msh->tools->tmpfd = open("./msh_heredoc.msh", O_RDWR |  O_CREAT | O_TRUNC, 0666);
				if (msh->tools->tmpfd < 0)
					printf("OPEN FAILED\n");//ft_error();
				while ((get_line(msh, "> ") >= 0) && (ft_strncmp(msh->tools->marker, msh->jobs->have_been_read, (size_t)ft_strlen(msh->jobs->have_been_read))))
				{
					// printf("[DEBUG][%s]\n", msh->jobs.have_been_read);
					ft_putendl_fd(msh->jobs->have_been_read, msh->tools->tmpfd);
				}
				msh->tools->istmp = 2;
			}
			cmd = cmd->p;
		}
		return (SUCCESS);
	}
	return (ERROR);
}

int			handle_redirection(t_msh *msh, t_cut_cmd *cmd, int fd)
{
	int	ret;

	ret = isredir(cmd);
	if ((ret == -1) && (fd >= 0))
	{
		if (!cmd->is_last)
			dup2(msh->tools->pipe[1], 1);
		return (SUCCESS);
	}
	else
	{
		msh->tools->fdin = 0;
		msh->tools->fdout = 0;
		input_redirection(msh, cmd);
		output_redirection(msh, cmd);
	}
	return (SUCCESS);
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
		to_delete_path = get_path(to_delete, list_to_split(msh, msh->envp));
		delete_args = ft_split("rm -rf ./msh_heredoc.msh", ' ');
		msh->tools->marker = NULL;//AKA COLLECT
		execve(to_delete->elem, delete_args, list_to_split(msh, msh->envp));
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


	pid = fork();
	if (pid == 0)
	{
		handle_redirection(msh, cmd, -1);
		if (cmd->TOKEN == C_BUILTIN)
			handle_builtins(msh, cmd);
		else
		{
			exec_path = get_path(cmd, msh->path);
			if (!exec_path || exec_path == NULL)
				ft_error(cmd, "PATH -1\n", 0);
			args = handle_args(msh, cmd);
			if (!args || args == NULL)
				ft_error(cmd, "BAD ARGS/OPTION\n", 0);
			execve(exec_path, args, list_to_split(msh, msh->envp));
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

void			cmd_pipe(t_msh *msh, t_cut_cmd *cmd)
{
	int		pid;
	int		bfd;
	char	*exec_path;
	char	**args;

	bfd = 0;
	while (cmd != NULL)
	{
			pipe(msh->tools->pipe);
			if ((cmd->p && cmd->p->TOKEN == ARG) && is_same(cmd->elem, "export"))
				builtin_export(msh, cmd);
			else
			{
				pid = fork();
				if ( pid == 0)
				{
					dup2(bfd, 0);
					handle_redirection(msh, cmd, bfd);
					if (cmd && cmd->TOKEN == C_BUILTIN)
						handle_builtins(msh, cmd);
					else
					{
						exec_path = get_path(cmd, msh->path);
						args = handle_args(msh, cmd);
						execve(exec_path, args, list_to_split(msh, msh->envp));
						printf("[EXEC -1][%s]\n", cmd->elem);
					}
				}
				else if (pid > 0)
				{
					waitpid(pid, &msh->tools->status, 0);
					if (msh->tools->status)
						printf("[FORK ISSUE][%d]\n", msh->tools->status);
					close(msh->tools->pipe[1]);
					bfd = msh->tools->pipe[0];
				}
				else
				{
					printf("-1 PID\n");
					exit (0);
				}
			}
		getnext_pipe(&cmd);
	}
}

int         handle_cmd(t_msh *msh, t_cut_cmd *pos)
{
	// t_cut_cmd	*sub;

	if (!msh || msh == NULL)
		return (-1);
	ispipe(msh);
	whatpostions(msh);
	if (msh->tools->nbpipe > 0)
		cmd_pipe(msh, pos);
	else
	{
		if ((pos->p && pos->p->TOKEN == ARG) && is_same(pos->elem, "export"))
			builtin_export(msh, pos);
		else
			simple_exec(msh, pos);
	}
	return (0);
}

int	handle_and(t_msh *msh, t_cut_cmd **new_pos)
{
	(void)msh;
	t_cut_cmd *new_new_pos;

	new_new_pos = (*new_pos)->n;
	*new_pos = new_new_pos;
	return (1);
}

int		_placeholder_handle_cmd(t_msh *msh)
{
	(void)msh;
	if (msh->tools->error_msg)
		return (0);
	t_cut_cmd	*ptr;
	t_cut_cmd	*pos;

	ptr = get_env_of(msh->envp, "PATH");
	pos = msh->tools->tail;
	////$MARK("place_holder")
	return (handle_cmd(msh, pos));
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_msh	*msh;

	i = -1;
	// while (envp[++i])
	// 	printf("[%s]\n", envp[i]);
	// $BR
	gc_init();
	(void)argc;
	(void)argv;
	// (void)envp;
	gc("pause");
	init_msh(&msh, envp);
	gc("resume");
	signal(SIGINT, handler);
	while (msh->tools->run_status)
	{
		get_line(msh, NULL);
		p_process_line(msh);
		//print_list(&msh);
		_placeholder_handle_cmd(msh);
		write_error(msh);
		//if (msh.tools->head)
		//	msh_debug(&msh, "line");
		msh->jobs->have_been_read = NULL;
		msh->jobs->reading_line = NULL;
		msh->tools->head = NULL;
		msh->tools->tail = NULL;
		gc("collect");
		// init_msh(&msh, envp);
	}
	gc("collect -all");
	return (0);
}
