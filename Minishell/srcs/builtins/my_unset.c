/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:14:39 by tidminta          #+#    #+#             */
/*   Updated: 2021/02/16 16:36:52 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// static void 	print_list(t_env_lair *env_lair)
// {
// 	int 	test; // pour le printf

// 	test = 1; // pour le printf
// 	t_env_list *current;

// 	current = env_lair->start;
// 	printf("| DEBUT | \n");
// 	while (current->next != NULL)
// 	{
// 		printf("[%d][%s]\n", test, current->content);
// 		current = current->next;
// 		test++; // pour le printf
// 	}
// 	printf("[hors boucle][%d][%s]\n", test, current->content);
// 	printf("| FIN |\n");
// 	printf("[size env_lair][%d]\n", env_lair->size);
// 	printf("[first env_lair][%s]\n", env_lair->start->content);
// 	printf("[end  env_lair][%s]\n", env_lair->end->content);
// }

static char	**ft_check_tab(t_list *lst)
{
	char	**tab;
	int		i;

	i = 0;
	while (lst != NULL && (lst->token == ARGS || lst->token == OPTION))
	{
		i++;
		lst = lst->next;
	}
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	tab[i] = NULL;
	while (lst != NULL && (lst->previous->token != CMD))
		lst = lst->previous;
	return (tab);
}

static int	ft_fill_tab(t_list *lst, char ***unset_tab)
{
	char	**tab_tmp;
	int		i;

	tab_tmp = *unset_tab;
	i = -1;
	while (tab_tmp[++i] != NULL
	&& (lst != NULL && (lst->token == ARGS || lst->token == OPTION)))
	{
		tab_tmp[i] = lst->content;
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
				to_pop = elem;
				if (elem == env_lair->start)//premier elem
				{
					to_pop->next->previous = NULL;
					env_lair->start = to_pop->next;
					to_pop->next = NULL;
					to_pop->previous = NULL;
					to_pop->content = NULL;
					to_pop = NULL;
					env_lair->size -= 1;
				}
				else if (elem == env_lair->end)//dernier elem
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
	t_env_list *env;

	if (!msh || !lst)
		return (ERROR);
	env = msh->env_lair->start;
	if (!(unset_tab = ft_check_tab(lst)))
		return (ERROR);
	if (ft_fill_tab(lst, &unset_tab) == ERROR)
		return (ERROR);
	if (ft_pop_node(msh->env_lair, unset_tab) == ERROR)
		return (ERROR);
	free(unset_tab);
	return (SUCCESS);
}
