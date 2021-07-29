#ifndef DATA_H
# define DATA_H

#include "./libshell.h"

void fill_header(int src[4], int *dst[4]);
t_cut_cmd *fill(char *elem, int header[4]);
void	gc_init();
int add(t_msh *msh, char *elem, int header[4]);
void init_jobs(t_job *jobs);
void init_msh(t_msh *msh);
void ready_for_input(t_msh *msh);
void print_list(void);
void initializer(t_msh *msh);
char *debug_get_line_name(t_cut_cmd *to_print);
void get_line_info(t_cut_cmd *to_debug);
void msh_debug(t_msh *msh, char *elem);
int is_symbol(char c);
char *p_near(char *str);
int add_symbol(t_msh *msh, char *ret, int i);
int process_line(t_msh *msh);
void write_error(t_msh *msh);

#endif
