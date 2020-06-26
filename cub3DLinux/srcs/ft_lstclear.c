/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 17:49:35 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/26 16:00:11 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*prev;

	if (!lst)
		return ;
	while (*lst)
	{
		prev = *lst;
		cur = *lst;
		cur = prev->next;
		(del)(prev->content);
		free(prev);
		*lst = cur;
	}
}
