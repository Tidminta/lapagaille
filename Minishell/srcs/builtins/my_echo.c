/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 06:06:53 by loamar            #+#    #+#             */
/*   Updated: 2021/03/04 17:21:57 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// check nb mots
// substr + split
// fill en fct de tab[i][0]
// afficher + free 

static int		check_if_exist(t_msh *msh, char *str, int indice)
{
	t_env_list	*lst;
	size_t	i;
	int		ret;

	i = 0;
	lst = msh->env_lair->start;
	ret = 0;
	while (indice >= 0)
	{
		str++;
		indice--;
	}
	while (str[i] && (str[i] != 32 || str[i] != 39 || str[i] != 34))
		i++;
	while (lst && ret == 0)
	{
		if ((ft_strncmp(lst->content, "(null)", 6) != 0) && (ft_strncmp(str, lst->content, i) == 0))
		{
			printf("[ENV MATCH FOUND][%s][%s][%zu]\n", str, lst->content, i);
			ret = 1;
		}
		lst = lst->next;
	}
	return (ret);
}

static int		ft_count_word(t_msh *msh, char *str)
{
	int		cpt;
	int		indic;
	int		i;

	if (!msh || !str)
		return (ERROR);
	cpt = (str[0] == ' ') ? 0 : 1;
	indic = 0;
	i = -1;
	while (str[++i])
	{
		if ((str[i] == ' ' || str[i] == '$') && (str[i + 1] >= 33 && str[i + 1] <= 126))
			cpt++;
	}
	while (str[--i] && !indic)
	{
		if (str[i] != ' ' || str[i] != '$')
			indic++;
	}
	if (!indic)
		cpt = 1;
	return (cpt);
}

int 	ft_my_echo(t_msh *msh, t_list *lst)
{
	int		option;
	int		ret;
	int		cpt;
	t_list	*element;

	if (!msh || !lst)
		return (ERROR);
	option = (lst->token == OPTION) ? 1 : 0;
	element = lst;
	ret = 0;
	cpt = 0;
	while (element && element->token == ARGS)
	{
		ret = ft_count_word(msh, element->content);
		cpt += ret;
		printf("[element->content][%s]->[%d]\n", element->content, ret);
		element = element->next;
	}
	printf ("[CPT FINAL][%d]\n", cpt);
	return (SUCCESS);
}

