#include "../includes/libshell.h"

# define NO_ARGS 0
# define ARGS 1
# define ARGS_BUT 2

void simple_exec(t_msh *msh, t_cut_cmd *cmd);
void cmd_nopipe(t_msh *msh, t_cut_cmd *cmd);
void cmd_pipe(t_msh *msh, t_cut_cmd *cmd);
char **handle_args(t_msh *msh, t_cut_cmd *cmd);
int _placeholder_handle_cmd(t_msh *msh);
int handle_cmd(t_msh *msh, t_cut_cmd *pos);
void delete_heredoc(t_msh *msh);
char **handle_heredoc(t_msh *msh, t_cut_cmd *cmd, int mode);
int choose_args(t_msh *msh);
