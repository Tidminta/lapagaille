/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ourlists.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:49:03 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/07 14:54:12 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

#include "./libshell.h"

t_env			*envnode(t_msh *msh, char *elem);

void			print(t_msh *msh);

t_cut_cmd		*fill(char *elem, int header[HEADER_SIZE]);

int				add(t_msh *msh, char *elem, int header[HEADER_SIZE]);

t_env			*fill_env(char *elem);

int				init_cmd(t_msh *msh);

#endif