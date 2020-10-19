/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:50:53 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/19 17:57:24 by tidminta         ###   ########.fr       */
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

/*
**************************************
**		DONT FORGET TO FREE			**
**		zbuff (init.c | l123)		**
**************************************
*/

void			*ft_garbage_collector(t_list **garbage, unsigned int size, int fd)
{
	t_list	*new;
	void	*tmp;

	if (!(tmp = (void*)malloc(size)))
		ft_error(garbage, "Error\nIt's may be a malloc error.\n", 0, fd);
	if (!(new = ft_lstnew(tmp)))
		ft_error(garbage, "Error\nIt's may be a malloc error.\n", 0, fd);
	ft_lstadd_front(garbage, new);
	return (tmp);
}

static void		ft_clear(void *content)
{
	if (content)
	{
		// printf("OK [%s]!\n", (char*)content);
		free(content);
	}
}

void		ft_freelst(t_list *l)
{
	t_list	*tmp;
	int		lst_size;
	void	(*clear)(void*);
	
	clear = &ft_clear;
	lst_size = ft_lstsize(l);
	printf("[avant]liste size = %d\n", lst_size);
	while (l)
	{
		tmp = l->next;
		ft_lstdelone(l, clear);
		l = tmp;
	}
	lst_size = 0;
	lst_size = ft_lstsize(l);
	printf("[apres] liste size = %d\n", lst_size);
}

int			ft_error(t_list **garbage, char *s, int indice, int fd)
{
	int		list_size;
	void	(*clear)(void*);

	clear = &ft_clear;
	list_size = ft_lstsize(*garbage);
	if (indice == 0)
	{
		ft_freelst(*garbage);
		system("leaks Cub3D");
	}
	if (s)
		ft_putstr_fd(s, 1);
	if (fd)
		close (fd);
	exit(EXIT_SUCCESS);
}
