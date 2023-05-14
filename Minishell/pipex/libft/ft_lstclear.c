/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:45:26 by tminta            #+#    #+#             */
/*   Updated: 2022/07/07 15:45:34 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
