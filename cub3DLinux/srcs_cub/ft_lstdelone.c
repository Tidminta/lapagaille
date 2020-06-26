/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 17:29:55 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/05 12:13:10 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
}
