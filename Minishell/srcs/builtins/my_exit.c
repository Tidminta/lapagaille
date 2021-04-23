/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:19:34 by tidminta          #+#    #+#             */
/*   Updated: 2021/04/23 18:01:52 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void			ft_free_env_lair(t_env_lair *to_free)
{
	t_env_list *tmp;
	t_env_list *lst;

	lst = to_free->start;
	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
	if (lst)
	{
		free(lst->content);
		free(lst);
	}
}

void				ft_exit(t_msh *msh)
{
	void	*lst;
	size_t	cpt;

	cpt = 0;
	lst = msh->env_lair->start;
	ft_putstr_fd("exit!\n", 1);
	free_data(msh);
	free_lair_list(msh);
	free_env_lair(msh);
	ft_free_separator_tab(msh);
	exit(0);
}
