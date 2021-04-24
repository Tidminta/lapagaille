/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:19:34 by tidminta          #+#    #+#             */
/*   Updated: 2021/04/24 17:56:15 by tidminta         ###   ########.fr       */
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
	int		ret;
	void	*lst;
	size_t	cpt;

	cpt = 0;
	lst = msh->env_lair->start;
	ft_putstr_fd("exit!\n", 1);
	// ft_free_separator_tab(msh);
	if ((ret = free_data(msh)) == 0)
		printf("free data done !\n");
	if ((ret = free_lair_list(msh)) == 0)
		printf("free lair list done !\n");
	if ((ret = free_env_lair(msh)) == 0)
		printf("free env lair done !\n");
	// system("leaks minishell");
	exit(0);
}
