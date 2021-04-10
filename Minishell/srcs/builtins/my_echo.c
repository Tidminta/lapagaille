/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 06:06:53 by loamar            #+#    #+#             */
/*   Updated: 2021/04/10 18:24:04 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int		check_if_exist(t_msh *msh, char *str, int indice)
{
	char		*s;
	t_env_list	*lst;
	size_t		i;

	i = 0;
	lst = msh->env_lair->start;
	while (indice-- >= 0)
		str++;
	while (str[i] && (str[i] != 32 && str[i] != 34
		&& str[i] != 36 && str[i] != 39))
		i++;
	if (i && (!(s = ft_substr(str, 0, (size_t)i))))
		return (ERROR);
	while (lst != NULL)
	{
		if ((ft_strncmp(lst->content, "(null)", 6) != 0)
			&& (ft_strncmp(s, lst->content, i) == 0))
		{
			if (s)
				free(s);
			s = ft_strchr(lst->content, 61) + 1;
			ft_putstr_fd(s, 1);
			return (SUCCESS);
		}
		lst = lst->next;
	}
	if (s)
		free(s);
	return (ERROR);
}

static int	ft_handle_elem(t_msh *msh, char *str, int quote)
{
	int		i;
	int		indic;
	size_t	len;

	if (!msh || !str)
		return (ERROR);
	i = (!quote) ? -1 : 0;
	indic = 0;
	len = ft_strlen(str);
	if (i >= 0 && str[i] == SQUOTE)
	{
		while (str[++i + 1])
			ft_putchar_fd(str[i], 1);
		return (SUCCESS);
	}
	while (str[++i])
	{
		if (str[i] && (str[i] == 36 && (check_if_exist(msh, str, i) >= 0)))
			indic = 1;
		else if (indic != 1)
			ft_putchar_fd(str[i], 1);
	}
	return (SUCCESS);
}

int			ft_my_echo(t_msh *msh, t_list *lst)
{
	int		option;
	int		quote;
	t_list	*element;

	if (!msh || !lst)
		return (ERROR);
	option = (lst->token == OPTION) ? 1 : 0;
	quote = 0;
	element = lst;
	while (element && element->token == ARGS)
	{
		quote = (element->token == ARGS
		&& (element->content[0] == 34 || element->content[0] == 39)) ? 1 : 0;
		ft_handle_elem(msh, element->content, quote);
		ft_putchar_fd(32, 1);
		element = element->next;
	}
	ft_putchar_fd(10, 1);
	return (SUCCESS);
}
