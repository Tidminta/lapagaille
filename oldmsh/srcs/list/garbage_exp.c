/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:18:23 by tidminta          #+#    #+#             */
/*   Updated: 2021/04/23 17:18:30 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

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

	player = (t_player*)ft_garbage_collector(&map->garbage, map,
		sizeof(t_player), map->fd);
	ft_bzero(player, sizeof(t_player));
	player->zbuff = (double*)ft_garbage_collector(&map->garbage, map,
		sizeof(double) * map->res->x, map->fd);
	ft_bzero(player->zbuff, sizeof(double*) * (size_t)nb);
