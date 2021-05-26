/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:19:34 by tidminta          #+#    #+#             */
/*   Updated: 2021/05/24 16:55:44 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// static void			ft_free_env_lair(t_env_lair *to_free)

void				ft_exit(t_msh *msh)
{
	int		ret;
	void	*lst;
	size_t	cpt;

	cpt = -1;
	lst = msh->env_lair->start;
	ft_putstr_fd("exit!\n", 1);
	// ft_free_separator_tab(msh);
	if ((ret = free_data(msh)) == 0)
	{
		printf("free data fail !\n");
	}
	if ((ret = free_lair_list(msh)) == 0)
		printf("free lair list fail !\n");
	if ((ret = free_env_lair(msh)) == 0)
		printf("free env lair fail !\n");
	while (msh->utils->path[++cpt])
		free(msh->utils->path[cpt]);
	free(msh);
	// system("leaks minishell");
	exit(0);
}
