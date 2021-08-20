/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IO.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:01:03 by tidminta          #+#    #+#             */
/*   Updated: 2021/08/18 20:01:06 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include "../includes/libshell.h"

int	isredir(t_cut_cmd *cmd);

int	handle_redirection(t_msh *msh, t_cut_cmd *cmd, int fd);

int	is_input(t_cut_cmd **cmd);

int	input_redirection(t_msh *msh, t_cut_cmd *cmd);

int	is_output(t_cut_cmd **cmd);

int	output_redirection(t_msh *msh, t_cut_cmd *cmd);

#endif