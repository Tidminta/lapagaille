/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:34:57 by tidminta          #+#    #+#             */
/*   Updated: 2021/02/23 14:18:42 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int			ft_my_cd(t_msh *msh, t_list *lst)
{
	int		ret;

	if (!msh || !lst)
		return (ERROR);
	ret = 0;
	if (lst->token == ARGS)
	{
		 if ((ret = chdir(lst->content)) == ERROR)
		 	ft_putendl_fd(strerror(errno), 1);
	}
	return (ret);
}
