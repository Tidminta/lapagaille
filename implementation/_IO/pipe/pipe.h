/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:52:13 by tidminta          #+#    #+#             */
/*   Updated: 2021/08/18 19:52:18 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "../../includes/libshell.h"

void	ispipe(t_msh *msh);

void	whatpostions(t_msh *msh);

int		getnext_pipe(t_cut_cmd **cmd);

#endif