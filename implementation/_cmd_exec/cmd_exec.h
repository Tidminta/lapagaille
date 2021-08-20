/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 21:32:10 by tidminta          #+#    #+#             */
/*   Updated: 2021/08/18 21:35:04 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_EXEC_H
# define CMD_EXEC_H

# include "../includes/libshell.h"

# define NO_ARGS 0
# define ARGS 1
# define ARGS_BUT 2

void	simple_exec(t_msh *msh, t_cut_cmd *cmd);

void	cmd_nopipe(t_msh *msh, t_cut_cmd *cmd);

void	cmd_pipe(t_msh *msh, t_cut_cmd *cmd);

void	delete_heredoc(t_msh *msh);

void	replace_args(t_msh *msh, t_cut_cmd *cmd);

void	son_fork(t_msh *msh, t_cut_cmd *cmd, int bfd);

void	father_fork(t_msh *msh, pid_t pid, int *bfd);

void	move_pos(t_msh *msh, t_cut_cmd **pos);

char	*_place_holder_get_path(t_msh *msh, t_cut_cmd *cmd);

char	*determine_path_type(t_cut_cmd *cmd, char *str);

char	**handle_heredoc(t_msh *msh, t_cut_cmd *cmd, int mode);

char	**handle_args(t_msh *msh, t_cut_cmd *cmd);

int		choose_args(t_msh *msh);

int		handle_cmd(t_msh *msh, t_cut_cmd *pos);

int		_placeholder_handle_cmd(t_msh *msh);

int		goto_next_div(t_msh *msh, t_cut_cmd **pos);

void	init_pos(t_cut_cmd *tail, t_cut_cmd **pos);

void	signal_handler(int signal);

#endif
