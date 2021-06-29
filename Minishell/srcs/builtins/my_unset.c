/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:14:39 by tidminta          #+#    #+#             */
/*   Updated: 2021/05/26 19:31:24 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static char	**ft_check_tab(t_list *lst)
{
	char	**tab;
	int		i;

	i = 0;
	while (lst != NULL && (lst->token == ARGS || lst->token == OPT))
	{
		i++;
		lst = lst->next;
	}
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	tab[i] = NULL;
	// while (lst != NULL && (lst->previous->token != CMD))
	// 	lst = lst->previous;
	return (tab);
}

static int	ft_fill_tab(t_list *lst, char ***unset_tab)
{
	char	**tab_tmp;
	int		i;

	tab_tmp = *unset_tab;
	i = -1;
	while (lst != NULL && (lst->token == ARGS || lst->token == OPT))
	{
		tab_tmp[++i] = lst->content;
		lst = lst->next;
	}
	return (SUCCESS);
}

int			ft_pop_node(t_env_lair *env_lair, char **unset_tab)
{
	int			i;
	t_env_list	*to_pop;
	t_env_list	*elem;
	size_t		len;

	i = 0;
	while (unset_tab[i] != NULL)
	{
		len = ft_strlen(unset_tab[i]);
		elem = env_lair->start;
		while (elem != NULL)
		{
			if (elem->content && ft_strncmp(unset_tab[i], elem->content, len) == 0)
			{
				printf("unset tab[%i] : %s | content : %s\n", i, unset_tab[i], elem->content);
				to_pop = elem;
				if (elem == env_lair->start)
				{
					to_pop->next->previous = NULL;
					env_lair->start = to_pop->next;
					to_pop->next = NULL;
					to_pop->previous = NULL;
					to_pop->content = NULL;
					to_pop = NULL;
					env_lair->size -= 1;
				}
				else if (elem == env_lair->end)
				{
					to_pop->previous->next = NULL;
					env_lair->end = to_pop->previous;
					to_pop->next = NULL;
					to_pop->previous = NULL;
					to_pop = NULL;
					env_lair->size -= 1;
				}
				else
				{
					to_pop->previous->next = to_pop->next;
					to_pop->next->previous = to_pop->previous;
					//pas oublier de free
					env_lair->size -= 1;
				}
			}
			elem = elem->next;
		}
		i++;
	}
	return (SUCCESS);
}

int			ft_my_unset(t_msh *msh, t_list *lst)
{
	char		**unset_tab;
	t_env_list	*env;

	if (!msh || !lst)
		return (ERROR);
	env = msh->env_lair->start;
	unset_tab = ft_check_tab(lst);
	if (!unset_tab)
		return (ERROR);
	if (ft_fill_tab(lst, &unset_tab) == ERROR)
		return (ERROR);
	if (ft_pop_node(msh->env_lair, unset_tab) == ERROR)
		return (ERROR);
	free(unset_tab);
	return (SUCCESS);
}
