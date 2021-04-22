/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_built_ins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:59:38 by tidminta          #+#    #+#             */
/*   Updated: 2021/04/22 17:30:13 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int		ft_built_in_check(char *s)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen(s);
	while (++i < len)
		s[i] = ft_tolower(s[i]);
	if ((ft_strncmp(s, "echo", len) == 0)
	|| (ft_strncmp(s, "cd", len) == 0)
	|| (ft_strncmp(s, "pwd", len) == 0)
	|| (ft_strncmp(s, "export", len) == 0)
	|| (ft_strncmp(s, "unset", len) == 0)
	|| (ft_strncmp(s, "env", len) == 0)
	|| (ft_strncmp(s, "cd", len) == 0)
	|| (ft_strncmp(s, "list", len) == 0)
	|| (ft_strncmp(s, "exit", len) == 0))
		return (SUCCESS);
	else
		return (ERROR);
}

static int				ft_exec_built_in(t_msh *msh, t_list *element, char **env)
{
	char	*content;
	size_t	len;
	int		i;

	content = element->content;
	len = ft_strlen(content);
	i = -1;
	if (ft_strncmp(content, "exit", len) == 0)
		ft_exit();
	else if ((ft_strncmp(content, "pwd", len) == 0))
	{
		if (ft_my_pwd() == ERROR)
			return (ERROR);
	}
	else if (ft_strncmp(content, "env", len) == 0)
	{
		if (ft_my_env(msh->env_lair) == ERROR)
			return (ERROR);
	}
	else if (ft_strncmp(content, "export", len) == 0)
	{
		if ((ft_my_export(msh, element->next) == ERROR))
			return (ERROR);
	}
	else if (ft_strncmp(content, "unset", len) == 0)
	{
		if (ft_my_unset(msh, element->next) == ERROR)
			return (ERROR);
	}
	else if (ft_strncmp(content, "cd", len) == 0)
	{
		if (ft_my_cd(msh, element->next) == ERROR)
			return (ERROR);
	}
	else if (ft_strncmp(content, "echo", len) == 0)
	{
		if (ft_my_echo(msh, element->next, 0) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

//builtin executiuon -> ptr_func_tab ou liste chainnée avec pointeur sur fct??
int				ft_handler_built_in(t_msh *msh, t_list *element, char **env)
{
	char *content;

	if (!msh || !element || !env)
		return (ERROR);
	content = element->content;
	if (ft_built_in_check(content) != SUCCESS)
		return (ERROR);
	ft_exec_built_in(msh, element, env);
	return (SUCCESS);
}
