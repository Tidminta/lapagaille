/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:48:48 by tidminta          #+#    #+#             */
/*   Updated: 2021/02/16 16:33:02 by tidminta         ###   ########.fr       */
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

static int	ft_fill_env(char **exp_tab, t_msh *msh)
{
	t_env_lair	*lst;
	t_env_list	*to_pop;
	size_t		len;
	size_t		j;
	int			i;

	to_pop = msh->env_lair->start;
	lst = msh->env_lair;
	while (to_pop != NULL)
	{
		i = -1;
		while (exp_tab[++i] != NULL)
		{
			j = 0;
			while (exp_tab[i][j] && exp_tab[i][j] != '=')
				j++;
			if (to_pop->content != NULL && ft_strncmp(to_pop->content, exp_tab[i], j) == 0)
			{
				free(to_pop->content);
				to_pop->content = ft_strdup(exp_tab[i]);
				free(exp_tab[i]);
				exp_tab[i] = ft_strdup(" ");
			}
		}
		to_pop = to_pop->next;
	}
	i = -1;
	while (exp_tab[++i] != NULL)
	{
		len = ft_strlen(exp_tab[i]);
		if (ft_strncmp(exp_tab[i], " ", len) != 0)
			ft_fill_end_env(lst, exp_tab[i]);
	}
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
	if ((size_tab = ft_check_args(lst, element)) == ERROR)
		return (ERROR);
	if (!(export_tab = ft_fill_exp_tab(element, size_tab)))
		return (ERROR);
	ft_fill_env(export_tab, msh);
	free(export_tab);
	return (SUCCESS);
}
