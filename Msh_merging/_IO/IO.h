#include "../includes/libshell.h"

int		isredir(t_cut_cmd *cmd);
int		handle_redirection(t_msh *msh, t_cut_cmd *cmd, int fd);
int		is_input(t_cut_cmd **cmd);
int		input_redirection(t_msh *msh, t_cut_cmd *cmd);
int		is_output(t_cut_cmd **cmd);
int		output_redirection(t_msh *msh, t_cut_cmd *cmd);
