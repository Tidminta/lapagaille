/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:43:45 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/08 20:12:47 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include "includes/libft.h"

size_t		ft_get_path(char *to_find, t_list *lst, char *s)
{
	int		i;
	char	*tmp;
	char	**tab;

	i = 0;
	while (lst->next)
	{
		tmp = lst->content;
		tab = ft_split(tmp, ' ');
		while (tab[i])
		{
			if (ft_strncmp(to_find, tab[i], 2) == 0)
			{
				s = tab[i + 1];
				return (1);
			}
		}
		lst = lst->next;
	}
	return (0);
}

int 	main(int ac, char **av)
{
	t_list	*list;
	t_list	*list2;
	t_res	*res_tmp;
	char 	*path = NULL;
	int 	i;
	int 	j;

	(void)ac;
	(void)av;
	i = 0;
	j = 0;
	res_tmp = malloc(sizeof(t_res));
	list = ft_lstnew("");
	list2 = ft_lstnew("SO       ./path_to_so_texture");
	ft_lstadd_front(&list, list2);
	ft_print_list(list);
	ft_get_path("SO", list, path);
	system("leaks a.out");
	return (0);
}
