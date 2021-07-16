/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:00:40 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/08 20:52:05 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// a refaire
void	handle_error(void)
{
	exit (0);
}

void			ft_error(t_cut_cmd *cmd, char *str, int errornum)
{
	if (str)
		ft_putstr_fd(cmd->elem, 1);
	else
		strerror(errornum);
	//collect();
	exit (errornum);
}