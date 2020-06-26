/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 18:45:12 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/05 12:07:15 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!alst)
		return ;
	tmp = *alst;
	if (*alst)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
	}
	else
		*alst = new;
}
