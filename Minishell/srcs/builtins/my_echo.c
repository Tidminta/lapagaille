/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 06:06:53 by loamar            #+#    #+#             */
/*   Updated: 2021/04/16 17:56:55 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static t_ret		*ft_check(t_msh *msh, t_env_list *lst, char *str, int infos)
{
	char		*s;
	t_ret		*ret;
	size_t		i;
	size_t		len;

	if (!msh || !str || !lst)
		return (NULL);
	i = 0;
	ret = (t_ret*)malloc(sizeof(t_ret));
	ret->i = 0;
	ret->s = 0;
	while (infos-- >= 0)
		str++;
	while ((str[i]) && (str[i] != 32 && str[i] != 34
		&& str[i] != 36 && str[i] != 39 && str[i] != '\\'))
		i++;
	if (i && (!(s = ft_substr(str, 0, (size_t)i))))
		return (NULL);
	while (lst != NULL)
	{
		if ((ft_strncmp(lst->content, "(null)", 6) != 0)
			&& (ft_strncmp(s, lst->content, i) == 0))
		{
			free(s);
			ret->i = i;
			// ret->s = ft_strdup(ft_strchr(lst->content, 61) + 1);
			ret->s = ft_strchr(lst->content, 61) + 1;
			return (ret);
		}
		lst = lst->next;
	}
	if (s)
		free(s);
	return (NULL);
}

static int	ft_handle(t_msh *msh, char *str, size_t size, int quote)
{
	int			i;
	int			indic;
	t_ret		*ret;
	t_env_list	*lst;

	if (!msh || !str)
		return (ERROR);
	i = (!quote) ? -1 : 0;
	indic = 0;
	lst = msh->env_lair->start;
	if (i == 0 && str[i] == SQUOTE)
	{
		while (str[++i + 1])
			ft_putchar_fd(str[i], 1);
		return (SUCCESS);
	}
	while (str[++i])
	{
		if ((str[i] == 36) && (ret = ft_check(msh, lst, str, i)))
		{
			i += ret->i;
			ft_putstr_fd(ret->s, 1);
			ret->i = 0;
			free(ret);
			indic = 1;
		}
		else if ((str[i] != 92) && indic == 1 && (size_t)i < size)
		{
			indic = 0;
			if (!(str[i] == 34 && i == size - 1))
				ft_putchar_fd(str[i], 1);
		}
		else
		{
			if (!((str[i] == 34 && str[i] == 92) && i == size - 1))
				ft_putchar_fd(str[i], 1);
		}
	}
	return (SUCCESS);
}

int			ft_my_echo(t_msh *msh, t_list *lst)
{
	int		op;
	int		quot;
	t_list	*element;

	if (!msh || !lst)
		return (ERROR);
	op = (lst->token == OPT && ft_strncmp(lst->content, "-n", 2) == 0) ? 1 : 0;
	printf("[cont = %s][token = %d][op=%d]\n", lst->content, lst->token, op);
	quot = 0;
	element = lst;
	while (element && element->token == ARGS)
	{
		quot = (element->token == ARGS
		&& (element->content[0] == 34 || element->content[0] == 39)) ? 1 : 0;
		ft_handle(msh, element->content, ft_strlen(element->content), quot);
		if (!op)
			ft_putchar_fd(32, 1);
		element = element->next;
	}
	ft_putchar_fd(10, 1);
	return (SUCCESS);
}
