/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:48:48 by tidminta          #+#    #+#             */
/*   Updated: 2021/02/02 16:10:14 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// static int	ft_doublon_check(t_env_lair *lst, char *content)
// {
// 	t_env_list	*env;
// 	size_t		cpt;
// 	int			i;

// 	if (!lst || lst == NULL)
// 		return (ERROR);
// 	env = lst->start;
// 	i = 0;
// 	cpt = 0;
// 	while (content[i] != '=')
// 		cpt++;
// 	while (env->content != NULL)
// 	{
// 		if (ft_strncmp(content, env->content, cpt) == 0)
// 			return (SUCCESS);
// 		env = env->next;
// 	}
// 	return (ERROR);
// }

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

static int	ft_check_args(t_env_lair *lst, t_list * element)
{
	int	i;

	i = 0;
	if (!element || element == NULL)
		return (ERROR);
	while (element->content != NULL && element->token != SEPARATOR)
	{
		if ((!ft_isalpha(element->content[0])) || !ft_strchr(element->content, 61))
			i = i;
		else
			i++;
		element = element->next;
	}
	i = (i > 0) ? i : ERROR;
	while (element->previous != NULL && element->previous->token != CMD)
		element = element->previous;
	return (i);
}

static char			**ft_fill_exp_tab(t_list *element, int size_tab)
{
	char	**tab;
	int		i;

	i = 0;
	if (!size_tab)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (size_tab + 1))))
		return (NULL);
	tab[size_tab] = NULL;
	while ((element->content != NULL && element->token != SEPARATOR) && ( i < size_tab))
	{
		if ((!ft_isalpha(element->content[0])) || !ft_strchr(element->content, 61))
			i += 0 ;
		else
		{
			if ((i < size_tab) && (element->token == ARGS || element->token == OPTION))
			{
				tab[i] = element->content;
				i++;
			}
		}
		element = element->next;
	}
	return (tab);
}

static t_env_lair 		*pop_back_env_(t_env_lair *env_lair)
{
	t_env_list 		*temp;

	if (!env_lair || env_lair == NULL)
		return (NULL);
	if (env_lair->start == env_lair->end)
	{
		free (env_lair);
		env_lair = NULL;
		return (NULL);
	}
	temp = env_lair->end;
	env_lair->end->next = NULL;
	temp->next = NULL;
	temp->previous = NULL;
	free(temp);
	temp = NULL;
	env_lair->size--;
	return (env_lair);
}

static int	ft_fill_env(char **export_tab, t_msh *msh)
{
	t_env_lair *lst;
	// t_env_list *start_tmp;
	int i;

	// start_tmp = lst->start;
	i = -1;
	lst = msh->env_lair;
	// while(start_tmp->content)
	// {
	// 	printf("[tmp pointe sur][%s]\n", start_tmp->content);
	// 	start_tmp = start_tmp->next;
	// }
	// printf("[l100][tmp pointe sur][%s]\n", start_tmp->content);
	while (export_tab[++i] != NULL)
		ft_fill_end_env(lst, export_tab[i]);
	return (SUCCESS);
}

int			ft_my_export(t_msh *msh, t_list *element)
{
	int			size_tab;
	char		**export_tab;
	t_env_lair	*lst; 

	if (!msh || !element)
		return (ERROR);
	lst = msh->env_lair;
	// ft_doublon_check here
	if ((size_tab = ft_check_args(lst, element)) == ERROR)
		return (ERROR);
	if (!(export_tab = ft_fill_exp_tab(element, size_tab)))
		return (ERROR);
	ft_fill_env(export_tab, msh);
	free(export_tab);
	// print_list(lst);
	return (SUCCESS);
}
