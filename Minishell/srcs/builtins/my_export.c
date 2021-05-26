/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:48:48 by tidminta          #+#    #+#             */
/*   Updated: 2021/05/26 18:56:34 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int	ft_check_args(t_env_lair *lst, t_list *elem)
{
	int	i;

	i = 0;
	if (!elem || elem == NULL)
		return (ERROR);
	while (elem->content && elem->token != SEP)
	{
		if ((!ft_isalpha(elem->content[0])) || !ft_strchr(elem->content, 61))
			i += 0;
		else
			i++;
		elem = elem->next;
	}
	if (i <= 0)
		return (ERROR);
	return (i);
}

static char	**ft_fill_exp_tab(t_list *elem, int size_tab)
{
	char	**tab;
	int		i;

	i = 0;
	if (!size_tab)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (size_tab + 1));
	if (!tab)
		return (NULL);
	tab[size_tab] = NULL;
	while ((elem->token != SEP && (i < size_tab)))
	{
		if ((!ft_isalpha(elem->content[0])) || !ft_strchr(elem->content, 61))
			i += 0;
		else
			if ((i < size_tab) && (elem->token == ARGS || elem->token == OPT))
				tab[i++] = elem->content;
		elem = elem->next;
	}
	return (tab);
}

static void	ft_fill_env(t_env_list *pop, t_env_lair *lst,
char **exp_tab, int size)
{
	size_t		j;
	int			i;

	while (pop != NULL)
	{
		i = -1;
		while (++i < size && exp_tab[i] != NULL)
		{
			j = 0;
			while (exp_tab[i][j] && exp_tab[i][j] != '=')
				j++;
			if (exp_tab[i][0] && ft_strncmp(pop->content, exp_tab[i], j) == 0)
			{
				free(pop->content);
				pop->content = ft_strdup(exp_tab[i]);
				ft_bzero(exp_tab[i], ft_strlen(exp_tab[i]));
			}
		}
		pop = pop->next;
	}
	i = -1;
	while (exp_tab[++i] != NULL)
		if (exp_tab[i][0])
			ft_fill_end_env(lst, exp_tab[i]);
}

int	ft_my_export(t_msh *msh, t_list *elem)
{
	int			size_tab;
	char		**export_tab;
	t_env_lair	*lst;

	if (!msh || !elem)
		return (ERROR);
	lst = msh->env_lair;
	size_tab = ft_check_args(lst, elem);
	if (size_tab == ERROR)
		return (ERROR);
	export_tab = ft_fill_exp_tab(elem, size_tab);
	if (!export_tab)
		return (ERROR);
	ft_fill_env(msh->env_lair->start, msh->env_lair, export_tab, size_tab);
	free(export_tab);
	return (SUCCESS);
}
