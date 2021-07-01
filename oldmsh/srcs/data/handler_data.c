/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:48:58 by loamar            #+#    #+#             */
/*   Updated: 2021/05/17 17:45:23 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int	ft_size_data(t_msh *msh, char *buf)
{
	msh->data->size_data = 0;
	ft_memset(buf, 0, ft_strlen(buf));
	free(buf);
	while (msh->data->prompt_data[msh->data->size_data] != NULL)
		msh->data->size_data++;
	return (1);
}

int			handler_data(t_msh **msh, char *buf)
{
	if (!((*(msh))->data = (t_data *)malloc(sizeof(t_data))))
		return (handler_error(*msh));
	(*(msh))->data->prompt_data = ft_split_data(buf, ' ');
	ft_size_data(*msh, buf);
	if (data_check(*msh) == -1)
	{
		(*(msh))->utils->error_multi_line = 1;
		return (handler_error(*msh));
	}
	return (1);
}