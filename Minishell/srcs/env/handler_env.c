/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:30:11 by loamar            #+#    #+#             */
/*   Updated: 2021/04/23 17:04:34 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int		linked_list_env(t_msh *msh, char **env)
{
	int		count;

	count = 0;
	msh->env_list = NULL;
	msh->env_lair = init_env_lair(msh->env_lair);
	if (msh->env_lair == NULL)
		return (ERROR);
	ft_fill_empty_env(msh->env_lair, env[count]);
	while (env[count] != NULL)
	{
		count++;
		ft_fill_end_env(msh->env_lair, env[count]);
	}
	return (SUCCESS);
}

static int		get_path(t_msh *msh)
{
	t_env_list	*element;
	char		*tmp;

	tmp = NULL;
	element = msh->env_lair->start;
	while (element != NULL)
	{
		if (element->content[0] == 'P'
		&& element->content[1] == 'A'
		&& element->content[2] == 'T'
		&& element->content[3] == 'H'
		&& element->content[4] == '=')
		{
			tmp = ft_substr(element->content, 5,
			ft_strlen(element->content) - 5);
			msh->utils->path = ft_split(tmp, ':');
			return (SUCCESS);
		}
		else
			element = element->next;
	}
	free(tmp);
	return (ERROR);
}

int			handler_env(t_msh *msh, char **env)
{
	int		ret;

	ret = 0;
	ret = linked_list_env(msh, env);
	if (ret == ERROR)
		return (ERROR);
	get_path(msh);
	return (SUCCESS);
}
