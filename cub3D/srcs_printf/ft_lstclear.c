/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 17:49:35 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/05 12:09:01 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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
