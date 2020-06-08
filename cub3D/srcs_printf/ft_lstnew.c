/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:33:59 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/06 20:09:26 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	// tmp->content = ft_calloc(1, sizeof(content));
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}
