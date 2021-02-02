/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:14:39 by tidminta          #+#    #+#             */
/*   Updated: 2021/02/02 18:58:47 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void 	print_list(t_env_lair *env_lair)
{
	int 	test; // pour le printf

	test = 1; // pour le printf
	t_env_list *current;

	current = env_lair->start;
	printf("| DEBUT | \n");
	while (current->next != NULL)
	{
		printf("[%d][%s]\n", test, current->content);
		current = current->next;
		test++; // pour le printf
	}
	printf("[hors boucle][%d][%s]\n", test, current->content);
	printf("| FIN |\n");
	printf("[size env_lair][%d]\n", env_lair->size);
	printf("[first env_lair][%s]\n", env_lair->start->content);
	printf("[end  env_lair][%s]\n", env_lair->end->content);
}

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

static int			ft_pop_node(t_env_lair *env_lair, char **unset_tab)
{
	int			i;
	t_env_list	*tmp;
	t_env_list	*lst;
	size_t		len;

	i = 0;
	while (unset_tab[i] != NULL)
	{
		len = ft_strlen(unset_tab[i]);
		lst = env_lair->start;
		while (unset_tab[i] && lst)
		{
			// printf("[tab[%i] = %s]\n[lst->content][%s]\n", i, unset_tab[i], lst->content);
			if (lst->content && ft_strncmp(unset_tab[i], lst->content, len) == 0)
			{
				if (lst->next != NULL)
				{
					printf("\n[l 90][ft_pop_node][%s]\n", lst->content);
					tmp = lst->next; char* test = 0; test = (tmp) ? "TMP != NULL" : "TMP == NULL";
					printf("[l 91][%s][tmp->content = %s]\n[l 92][ft_pop_node lst = lst->previous]\n", test, tmp->content);
					lst = lst->previous; test = (lst) ? "[l 93][LST != NULL]" : "[l 93][LST == NULL]";
					printf("[l 94][ft_pop_node][%s][lst->content = %s]\n", test, lst->content);
					lst->next->content = NULL;
					printf("[l 96][ft_pop_node]\n");
					lst->next->previous = NULL;
					printf("[l 98][ft_pop_node]\n");
					lst->next->next = NULL;
					printf("[l 100][ft_pop_node]\n");
					// free(lst->next);
					// lst->next = NULL;
					printf("[l 103][ft_pop_node]\n");
					lst->next = tmp;
					// lst = lst->next;
					printf("[l 106][ft_pop_node]\n");
				}
				else
				{
					tmp = lst->previous;
					// printf("NEXT == NULL\n\n");
					// free(lst->content);
					lst->content = NULL;
					lst->next = NULL;
					lst->previous = NULL;
					lst = tmp;
					break ;
				}
			}
			else
			{
				// printf("[l 101][NEXT]\n");
				lst = lst->next;
			}
		}
		i++;
		printf("** E O L **\n");
	}
	printf("[l 98][pop node][end]\n");
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
	// printf("[l 114][ft_my_unset][b4 pop node]\n");
	if (ft_pop_node(msh->env_lair, unset_tab) == ERROR)
		return (ERROR);
	// printf("[l 117][ft_my_unset][after pop node]\n");
	free(unset_tab);
	// print_list(msh->env_lair);
	return (SUCCESS);
}
