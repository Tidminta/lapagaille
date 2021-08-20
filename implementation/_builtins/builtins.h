/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:26:24 by tidminta          #+#    #+#             */
/*   Updated: 2021/08/18 21:03:55 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../includes/libshell.h"

int		builtin_export(t_msh *msh, t_cut_cmd *cmd);

int		builtin_unset(t_msh *msh, t_cut_cmd *cmd);

int		builtin_exit(t_msh *msh, t_cut_cmd *cmd);

int		builtin_echo_return_value(t_msh *msh, t_cut_cmd *cmd, int mode);

int		builtin_echo(t_msh *msh, t_cut_cmd *cmd);

int		builtin_cd(t_msh *msh, t_cut_cmd *cmd);

int		builtin_pwd(t_msh *msh, t_cut_cmd *cmd);

int		builtin_env(t_msh *msh, t_cut_cmd *cmd);

int		print_env(t_msh *msh, t_cut_cmd *target);

int		swap_env(t_msh **msh, char *new);

int		check_o(t_msh *msh, t_cut_cmd *cmd);

int		check_e(t_msh *msh, t_cut_cmd *cmd);

int		is_env(t_msh **msh, char *to_pop);

void	pop_env(t_msh **msh);

void	cut_bexport(t_msh *msh, t_cut_cmd *env,
			char **env_split, char *to_print);

void	add_builtin(int (***f_p_builtin)(t_msh *msh,
				t_cut_cmd *cmd), void *addr, int size);

void	print_alpha_export(t_msh *msh, t_cut_cmd *cmd);

void	handle_builtins(t_msh *msh, t_cut_cmd *cmd);

void	print_export(t_msh *msh, char *env);

#endif
