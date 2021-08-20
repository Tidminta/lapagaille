/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:05:50 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/26 00:20:55 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
**  ICI NOUS METTRONS LES PROTOTYPES DES FONCTION DE GESTION DE COMMANDE
**
*/

#ifndef CMD_H
# define CMD_H

# include "./libshell.h"

# define SUCCESS 1
# define ERROR -1
# define NO_ARGS 0
# define ARGS 1
# define ARGS_BUT 2


int         handle_cmd(t_msh *msh, t_cut_cmd *pos);

int			isbuiltin(t_msh *msh, char *content);

int			choose_exec(t_cut_cmd *cmd);

void		ispipe(t_msh *msh);

int			isredir(t_cut_cmd *cmd);

#endif
