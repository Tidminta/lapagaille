#include "../includes/libshell.h"
#ifndef ERROR_H
# define ERROR_H

void write_error(t_msh *msh);
void handler(int n);
void ft_error(t_cut_cmd *cmd, char *str, int errornum);
#endif
