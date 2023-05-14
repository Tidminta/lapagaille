/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:26:30 by tidiane           #+#    #+#             */
/*   Updated: 2023/05/13 23:38:44 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	ft_get_cmd(t_pipe **box)
{
	int		indic;

	indic = 2;
	(*box)->cmd1 = (t_cmd *)malloc(sizeof(t_cmd) * 1);
	(*box)->cmd2 = (t_cmd *)malloc(sizeof(t_cmd) * 1);
	(*box)->cmd1->cmd_n = first_word((*box)->argv[indic++]);
	(*box)->cmd1->args = ft_split((*box)->argv[2], ' ');
	(*box)->cmd2->cmd_n = first_word((*box)->argv[indic]);
	(*box)->cmd2->args = ft_split((*box)->argv[3], ' ');
}

void	ft_parsing_step(t_pipe **box, char **argv, char **envp)
{
	int	indic;
	int	i;

	indic = -1;
	i = -1;
	ft_init(box, argv, envp);
	if (!(*box))
		return ;
	ft_get_cmd(box);
	while (++indic < 2)
		ft_get_path(*box, indic, i);
}

char	*split_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (ft_strncmp("PATH", envp[i], ft_strlen("PATH")))
		i++;
	path = ft_substr(envp[i], 5, (size_t)ft_strlen(envp[i]));
	return (path);
}

void	ft_verif(char *tmp, t_cmd *cmd)
{
	if (access(tmp, F_OK) == 0)
	{
		cmd->cmd_p = ft_strdup(tmp);
		if (cmd->cmd_p == NULL)
			return ;
	}
}

void	ft_get_path(t_pipe	*box, int indic, int i)
{
	char	*tmp;
	t_cmd	*cmd;

	tmp = split_path(box->envp);
	if (tmp == NULL || !tmp)
		;
	if (indic == 1)
		cmd = box->cmd1;
	else
		cmd = box->cmd2;
	box->path = ft_split(tmp, ':');
	free(tmp);
	while (box->path[++i])
	{
		tmp = ft_strdup(box->path[i]);
		tmp = ft_strjoin2(tmp, "/");
		tmp = ft_strjoin2(tmp, cmd->cmd_n);
		if (tmp)
		{
			ft_verif(tmp, cmd);
			free(tmp);
		}
	}
	ft_free_tab(box->path);
	free(box->path);
}
