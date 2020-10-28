/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:50:53 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/28 15:08:57 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			ft_free_split(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void			*ft_garbage_collector(t_list **garbage, t_mapinfos *map,
				unsigned int size, int fd)
{
	t_list	*new;
	void	*tmp;

	(void)fd;
	if (!(tmp = (void*)malloc(size)))
		ft_error(garbage, "Error\nIt's may be a malloc error.\n", 0, map);
	if (!(new = ft_lstnew(tmp)))
		ft_error(garbage, "Error\nIt's may be a malloc error.\n", 0, map);
	ft_lstadd_front(garbage, new);
	return (tmp);
}

static void		ft_clear(void *content)
{
	if (content)
		free(content);
}

void			ft_freelst(t_list *l)
{
	t_list	*tmp;
	int		lst_size;
	void	(*clear)(void*);
	int		i;

	clear = &ft_clear;
	i = 0;
	lst_size = ft_lstsize(l);
	while (l && i < lst_size)
	{
		tmp = l->next;
		if (l->content)
		{
			ft_lstdelone(l, clear);
			l = tmp;
		}
		i++;
	}
}

int				ft_error(t_list **garbage, char *s, int indice, t_mapinfos *map)
{
	int		list_size;
	void	(*clear)(void*);

	clear = &ft_clear;
	if (garbage)
		list_size = ft_lstsize(*garbage);
	if (map)
		ft_clear_map(map);
	if (indice == 0)
	{
		ft_freelst(*garbage);
	}
	if (s)
		ft_putstr_fd(s, 1);
	if (map && map->fd)
		close(map->fd);
	exit(EXIT_SUCCESS);
}
