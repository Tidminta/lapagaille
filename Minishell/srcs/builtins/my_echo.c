/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 06:06:53 by loamar            #+#    #+#             */
/*   Updated: 2021/04/05 18:24:14 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// static int	ft_count_word(t_msh *msh, char *str)
// {
// 	int		cpt;
// 	int		indic;
// 	int		i;

// 	if (!msh || !str)
// 		return (ERROR);
// 	cpt = 0;
// 	indic = 0;
// 	i = 0;
// 	if (ft_isalnum(str[0]) && (str[i] != 36 && str[i] != 32))
// 		cpt = 1;
// 	while (str[i])
// 	{
// 		if ((str[i] == ' ' || str[i] == '$')
// 			&& (str[i + 1] && (str[i + 1] >= 33 && str[i + 1] <= 126)))
// 			cpt++;
// 		i++;
// 	}
// 	while (str[--i] && !indic)
// 		if (str[i] != ' ' || str[i] != '$')
// 			indic++;
// 	if (!indic)
// 		cpt = 1;
// 	return (cpt);
// }

static int		check_if_exist(t_msh *msh, char *str, int indice)
{
	char		*s;
	t_env_list	*lst;
	size_t		i;

	i = 0;
	lst = msh->env_lair->start;
	while (indice-- >= 0)
		str++;
	while (str[i] && (str[i] != 32 || str[i] != 39 || str[i] != 34))
		i++;
	while (lst != NULL)
	{
		if ((ft_strncmp(lst->content, "(null)", 6) != 0)
			&& (ft_strncmp(str, lst->content, i) == 0))
		{
			s = ft_strchr(lst->content, 61) + 1;
			ft_putstr_fd(s, 1);
			return (SUCCESS);
		}
		lst = lst->next;
	}
	printf("NO MATCH FOUND !\n");
	return (ERROR);
}

// a finir echo pass$partout fail

static int	ft_handle_elem(t_msh *msh, char *str)
{
	int	i;

	if (!msh || !str)
		return (ERROR);
	i = -1;
	while (str[++i])
	{
		if (str[i] && (str[i] == 36 && check_if_exist(msh, str, i)))
		{
			while (str[i] && (ft_isalnum(str[i])))
				i++;
		}
		else
		{
			printf("l86\n");
			while (str[i])
			{
				ft_putchar_fd(str[i], 1);
				i++;
			}
			return (SUCCESS);
		}
	}
	return (SUCCESS);
}

// check nb mots
// substr + split
// fill en fct de tab[i][0]
// afficher + free 

int			ft_my_echo(t_msh *msh, t_list *lst)
{
	int		option;
	int		ret;
	int		cpt;
	char	**tab;
	t_list	*element;

	if (!msh || !lst)
		return (ERROR);
	option = (lst->token == OPTION) ? 1 : 0;
	element = lst;
	ret = 0;
	cpt = 0;
	while (element && element->token == ARGS)
	{
		// ret = ft_count_word(msh, element->content);
		// cpt += ret;
		ft_handle_elem(msh, element->content);
		ft_putchar_fd(32, 1);
		element = element->next;
	}
	ft_putchar_fd(10, 1);
	// tab = ft_fill_tab(msh);
	//affichage tab**
	// printf("[CPT FINAL][%d]\n", cpt);
	return (SUCCESS);
}
