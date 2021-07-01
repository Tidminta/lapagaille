/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:33 by loamar            #+#    #+#             */
/*   Updated: 2021/06/30 14:53:57 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// bricolage
int			handle_status(int status, t_msh *msh)
{
	msh->utils->status = status;

	return (handler_error);
}

int			handler_cmd(t_msh *msh, char **env)
{
	int		ret;
	t_list	*element;
	// if (!msh || !msh->env_list || !env)
	// 	return (ERROR);
	element = msh->lair_list->start;
	while (element->next != NULL)
	{
		if (element->token == CMD)
		{
			if (ft_handler_built_in(msh, element, env) != SUCCESS)
			{
				if ((exec_cmd(msh, element, env) == ERROR))
					handle_status(1, msh);
			}
			element = element->next;
			while (element->token == OPT || element->token == ARGS)
				element = element->next;
		}
		else
			element = element->next;
	}
	return (0);
}
