/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:05:50 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/17 00:13:00 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
**  ICI NOUS METTRONS LES PROTOTYPES DES FONCTION DE GESTION DE COMMANDE 
**
** Redirections:
** ◦ < should redirect input.
** ◦ > should redirect output.
** ◦ “<<” read input from the current source until 
** a line containing only the delimiter is seen. it doesn’t need to update history
** a connaitre : isatty, ttyname, ttyslot, ioctl
**
*/

#ifndef CMD_H
# define CMD_H

# include "./libshell.h"

# define SUCCESS 1
# define ERROR -1
# define BUILTIN 1
# define EXEC 2
# define OPTION 3
# define PIPE 3
# define ARG 4
# define RREDIR 62
# define LREDIR 60
# define WRITE_P 1
# define READ_P 0
# define FIRST_CMD 1
# define MIDDLE_CMD 2
# define LAST_CMD 3


int         handle_cmd(t_msh *msh);

int			isbuiltin(t_msh *msh, char *content);

int			choose_exec(t_cut_cmd *cmd);

int			ispipe(t_msh *msh);

int			isredir(t_msh *msh);

int			handle_exec(t_msh *msh);

char		*get_path(t_cut_cmd *cmd, char **paths);

int			whatpostions(t_msh *msh);

void		printheader(t_msh *msh);

char		**handle_args(t_msh *msh, t_cut_cmd *cmd);

void		my_putstr(char *str1, char *str2);

void		cmd_nopipe(t_msh *msh, t_cut_cmd *cmd);

int			choose_exec(t_cut_cmd *cmd);

void		simple_exec(t_msh *msh, t_cut_cmd *cmd);

int			findnext_pipe(t_cut_cmd *cmd);

void		getnext_pipe(t_cut_cmd **cmd);

void		inpipe(t_msh *msh, t_cut_cmd *cmd_);

#endif