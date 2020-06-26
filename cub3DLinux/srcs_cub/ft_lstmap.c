/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:30:55 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/05 12:11:43 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;

	if (!(newlst = malloc(sizeof(t_list))))
		return (NULL);
	if (!lst || !f)
		return (NULL);
	if (lst)
	{
		newlst->content = (*f)(lst->content);
		newlst->next = ft_lstmap(lst->next, f, del);
		return (newlst);
	}
	return (NULL);
}
