/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:48:48 by tidminta          #+#    #+#             */
/*   Updated: 2021/04/13 17:53:52 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int	ft_check_args(t_env_lair *lst, t_list *elem)
{
	int	i;

	i = 0;
	if (!elem || elem == NULL)
		return (ERROR);
	while (elem->content != NULL && elem->token != SEP)
	{
		if ((!ft_isalpha(elem->content[0])) || !ft_strchr(elem->content, 61))
			i = i;
		else
			i++;
		elem = elem->next;
	}
	i = (i > 0) ? i : ERROR;
	while (elem->previous != NULL && elem->previous->token != CMD)
		elem = elem->previous;
	return (i);
}

static char			**ft_fill_exp_tab(t_list *elem, int size_tab)
{
	char	**tab;
	int		i;

	i = 0;
	if (!size_tab)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (size_tab + 1))))
		return (NULL);
	tab[size_tab] = NULL;
	while ((elem->content != NULL && elem->token != SEP && (i < size_tab)))
	{
		if ((!ft_isalpha(elem->content[0])) || !ft_strchr(elem->content, 61))
			i += 0;
		else
		{
			if ((i < size_tab) && (elem->token == ARGS || elem->token == OPT))
			{
				tab[i] = elem->content;
				i++;
			}
		}
		elem = elem->next;
	}
	return (tab);
}

static int	ft_fill_env(char **exp_tab, t_msh *msh)
{
	t_env_lair	*lst;
	t_env_list	*pop;
	size_t		len;
	size_t		j;
	int			i;

	pop = msh->env_lair->start;
	lst = msh->env_lair;
	while (pop != NULL)
	{
		i = -1;
		while (exp_tab[++i] != NULL)
		{
			j = 0;
			while (exp_tab[i][j] && exp_tab[i][j] != '=')
				j++;
			if (pop->content && ft_strncmp(pop->content, exp_tab[i], j) == 0)
			{
				pop->content = ft_strdup(exp_tab[i]);
				free(exp_tab[i]);
				exp_tab[i] = ft_strdup(" ");
			}
		}
		pop = pop->next;
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

int			ft_my_export(t_msh *msh, t_list *elem)
{
	int			size_tab;
	char		**export_tab;
	t_env_lair	*lst;

	if (!msh || !elem)
		return (ERROR);
	lst = msh->env_lair;
	if ((size_tab = ft_check_args(lst, elem)) == ERROR)
		return (ERROR);
	if (!(export_tab = ft_fill_exp_tab(elem, size_tab)))
		return (ERROR);
	ft_fill_env(export_tab, msh);
	free(export_tab);
	return (SUCCESS);
}
