/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:26:30 by tidiane           #+#    #+#             */
/*   Updated: 2023/05/13 20:18:58 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"


/****		GET CMD		****/
void    ft_get_cmd(t_pipe **box)
{
	int		indic;

	indic = 2;
	(*box)->cmd1 = (t_cmd*)malloc(sizeof(t_cmd) * 1);
	(*box)->cmd2 = (t_cmd*)malloc(sizeof(t_cmd) * 1);
    (*box)->cmd1->cmd_n = first_word((*box)->argv[indic++]);
	(*box)->cmd1->args = ft_split((*box)->argv[2], ' ');
    (*box)->cmd2->cmd_n = first_word((*box)->argv[indic]);
	(*box)->cmd2->args = ft_split((*box)->argv[3], ' ');
}

/****		GET CMD		****/

void	ft_parsing_step(t_pipe **box, char **argv, char **envp)
{
    int indic;

    indic = -1;
	ft_init(box, argv, envp);
    if (!(*box))
        return ;
	ft_get_cmd(box);
    while (++indic < 2)
        ft_get_path(*box, indic);
}

// void	ft_free_split2(t_pipe *box)
// {
// 	int i;

// 	i = -1;
// 	while (box->paths[i])
// 		free(box->paths[i]);
// }

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
	t_cmd	*cmd;
	int		res;
	int		i;

	i = -1;
	res = 0;
	tmp = split_path(box->envp);
	if (tmp == NULL || !tmp)
		return (ERROR);
	if (indic == 1)
		cmd = box->cmd1;
	else
		cmd = box->cmd2;
	//
	box->path = ft_split(tmp, ':');
	if (tmp)
		free(tmp);
	while (box->path[++i])
	{
		tmp = ft_strdup(box->path[i]);
		tmp = ft_strjoin(tmp, "/");
		tmp = ft_strjoin(tmp, cmd->cmd_n);
		ft_strtrim(tmp, "\n");
		if (access(tmp, F_OK) == 0)
		{
			cmd->cmd_p = ft_strdup(tmp);
			if (cmd->cmd_p == NULL)
				return (0);
			res = 1;
		}
		free(tmp);
	}
	return (res);
}