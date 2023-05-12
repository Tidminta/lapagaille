/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:26:30 by tidiane           #+#    #+#             */
/*   Updated: 2023/05/11 19:28:11 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void    ft_get_cmd(t_pipe **box)
{
    (*box)->only_cmd[0] = ft_only_cmd(*box, 0);
    (*box)->only_cmd[1] = ft_only_cmd(*box, 1);
}

void	ft_parsing_step(t_pipe **box, char **argv, char **envp)
{
    int indic;

    indic = -1;
	ft_init(box, argv, envp);
    if (!(*box))
        return ;
	ft_get_cmd(box);
	// ft_get_arg(); NOT NECESSARY
    while (++indic < 2)
        ft_get_path(*box, indic);
}

char	*ft_only_cmd(t_pipe *box, int indic)
{
	char	*str;
	char	**table;
	size_t	i;

	table = (char **)malloc(sizeof(char*) * 3);
	// table[0] = box->cmd1;
	// table[1] = box->cmd2;
    table[0] = box->cmd[0];
	table[2] = box->cmd[1];
	i = 0;
	while (table[indic][i] && table[indic][i] != ' ')
		i++;
	str = ft_substr(table[indic], 0, i);
    free(table[0]);
    free(table[1]);
    free(table);
	return (str);
}

t_pipe	*ft_box_fill(char **argv, char **envp)
{
	t_pipe	*tools;

	tools = (t_pipe *)malloc(sizeof(t_pipe));
	if (!tools)
		return (NULL);
	ft_create_lstc(&tools);
	tools->envp = envp;
	tools->file1 = ft_strdup(argv[1]);
	tools->cmd1 = ft_strdup(argv[2]);
    tools->cmd[0] = ft_strdup(argv[2]);
    tools->cmd[1] = ft_strdup(argv[3]);
	tools->o_cmd1 = 0;
    tools->only_cmd = (char**)malloc(sizeof(char*) * 3);
    tools->only_cmd[2] = NULL;
	tools->file2 = ft_strdup(argv[4]);
	tools->cmd2 = ft_strdup(argv[3]);
	tools->o_cmd2 = 0;
	tools->path = 0;
	tools->pid = 0;
	tools->err_no = 0;
	tools->fd1 = 0;
	tools->fd2 = 0;
	tools->paths = 0;
    tools->f_args = (char***)malloc(sizeof(char**) * 3);
    tools->f_args[2] = NULL;
	tools->f_args[0] = ft_split(argv[2], ' ');
	tools->f_args[1] = ft_split(argv[3], ' ');
	printf("[test][%s]\n", tools->cmd_box->head->cmd_n);
	exit (0);
	return (tools);
}

void	ft_init(t_pipe **box, char **argv, char **envp)
{
	(*box) = ft_box_fill(argv, envp);
}

void	ft_free_split2(t_pipe *box)
{
	int i;

	i = -1;
	while (box->paths[i])
		free(box->paths[i]);
}

char	*split_path(char **envp)
{
	int	i;
	char	*path;

	i = 0;
	while (ft_strncmp("PATH", envp[i], ft_strlen("PATH")))
		i++;
	path = ft_substr(envp[i], 5, (size_t)ft_strlen(envp[i]));
    ft_strtrim(path, "\n");
	return (path);
}

int	ft_get_path(t_pipe	*box, int indic)
{
	char	*tmp;
	// char	*path;
	int		res;
	int		i;

	i = -1;
	res = 0;
	tmp = split_path(box->envp);
	box->paths = ft_split(tmp, ':');
	if (tmp)
		free(tmp);
	while (box->paths[++i])
	{
		tmp = ft_strdup(box->paths[i]);
		tmp = ft_strjoin(tmp, "/");
		tmp = ft_strjoin(tmp, box->only_cmd[indic]);
		ft_strtrim(tmp, "\n");
        // printf("[complet path][%s]\n", tmp);
        // sleep(1);
		if (access(tmp, F_OK) == 0)
		{
			box->path[indic] = ft_strdup(tmp);
            // printf("[final path][%s]\n", box->path);
			res = 1;
            // sleep(1);
		}
		free(tmp);
	}
	// if (box->paths)
	// 	ft_free_split2(box);
	return (res);
}