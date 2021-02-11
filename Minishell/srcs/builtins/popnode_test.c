/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popnode_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:53:45 by tidminta          #+#    #+#             */
/*   Updated: 2021/02/11 12:58:12 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// printf("\n[l 90][ft_pop_node][%s]\n", lst->content);
// printf("[l 91][%s][tmp->content = %s]\n[l 92][ft_pop_node lst = lst->previous]\n", test, tmp->content);
// printf("[l 96][ft_pop_node]\n");
// printf("[l 98][ft_pop_node]\n");
// printf("[l 100][ft_pop_node]\n");
// printf("[l 103][ft_pop_node]\n");
// printf("[l 106][ft_pop_node]\n");

static int			ft_pop_node(t_env_lair *env_lair, char **unset_tab)
{
	int			i;
	t_env_list	*tmp;
	t_env_list	*lst;
	size_t		len;

	i = 0;
	while (unset_tab[i] != NULL)
	{
		len = ft_strlen(unset_tab[i]);
		lst = env_lair->start;
		while (unset_tab[i] && lst)
		{
			if (lst->content && ft_strncmp(unset_tab[i], lst->content, len) == 0)
			{
				if (lst->next != NULL)
				{
					tmp = lst->next; char* test = 0; test = (tmp) ? "TMP != NULL" : "TMP == NULL";
					lst = lst->previous; test = (lst) ? "[l 93][LST != NULL]" : "[l 93][LST == NULL]";
					lst->next = tmp;
					// lst = lst->next;
				}
				else
				{
					tmp = lst->previous;
					// printf("NEXT == NULL\n\n");
					// free(lst->content);
					lst->content = NULL;
					lst->next = NULL;
					lst->previous = NULL;
					lst = tmp;
					break ;
				}
			}
			else
			{
				// printf("[l 101][NEXT]\n");
				lst = lst->next;
			}
		}
		i++;
		printf("** E O L **\n");
	}
	printf("[l 98][pop node][end]\n");
	return (SUCCESS);
}

int main(void)
{

	return (0);
}