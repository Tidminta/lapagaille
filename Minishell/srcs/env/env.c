/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:06:55 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/20 23:17:31 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

void				print(t_msh *msh)
{
	t_env *env;
	int i;

	i = 0;
	env = msh->e_tail;
	if (!env)
	{
		printf("ENV = NULL!\n");
		// sleep(5);
		exit(0);
	}
	printf("\n[**	PRINT LIST	**]\n");
	while(env != NULL)
	{
		printf("[node %d][%s]\n", i, env->elem);
		env = env->p;
		i++;
	}
	printf("\n[**	PRINT LIST	**]\n");
	// sleep(5);
}

int				find_path(t_msh *msh)
{
	t_env	*env;
	char	*path_tmp;

	env = msh->e_tail;
	while (env != NULL)
	{
		if (ft_strncmp(env->elem, "PATH=", 5) == 0)
		{
			path_tmp = ft_strnstr(env->elem, "=", (size_t)ft_strlen(env->elem)) + 1;
			msh->path = ft_split(path_tmp, ':');
			if (msh->path)
				return (SUCCESS);
			return (ERROR);	
		}
		env = env->p;
	}
	return (ERROR);
}

int			handle_env(t_msh *msh, char **envp)
{
	t_env	*env;
	int		i;

	if (!msh | !envp)
		return (ERROR);
	i = -1;
	msh->envp = envp;
	while (envp[++i] != NULL)
	{
		env = envnode(msh, envp[i]);
		env = env->p;
	}
	if (!find_path(msh))
		return (ERROR);
	printf("\n**	HANDLE ENV OK	**\n");
	return (SUCCESS);
}