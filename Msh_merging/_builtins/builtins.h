#include "../includes/libshell.h"
#ifndef BUILTIN_H
# define BUILTIN_H

int		builtin_export(t_msh *msh, t_cut_cmd *cmd);
int		builtin_unset(t_msh *msh, t_cut_cmd *cmd);
int		builtin_exit(t_msh *msh, t_cut_cmd *cmd);
void	add_builtin(int (***f_p_builtin)(t_msh *msh, t_cut_cmd *cmd), void *addr, int size);
void	handle_builtins(t_msh *msh, t_cut_cmd *cmd);
int		builtin_echo_return_value(t_msh *msh, t_cut_cmd *cmd, int mode);
int		builtin_echo(t_msh *msh, t_cut_cmd *cmd);
int		builtin_cd(t_msh *msh, t_cut_cmd *cmd);
int		builtin_pwd(t_msh *msh, t_cut_cmd *cmd);
int		builtin_env(t_msh *msh, t_cut_cmd *cmd);
int		print_env(t_cut_cmd *target);
#endif
