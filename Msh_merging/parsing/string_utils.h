#include "../includes/libshell.h"

int is_symbol(char c);
int is_quote(char c, char type);
void p_putchar_str(char **str, char c);
t_cut_cmd *fill(char *elem, t_TOKEN TOKEN);
int add(t_msh *msh, char *elem, t_TOKEN TOKEN);
int split_len(char **split);
char **list_to_split(t_cut_cmd *target);
char *get_path(t_cut_cmd *cmd, char **paths);
int c_is_present(char *str, char c);
int get_enum_len(void);
char *n_dup(char *str, int start, int end);
char *str_modulo(char *src, char **modulo, int inc);
int is_match(char *list, char sep, char *elem);
int is_match2(char *list, char sep, char *elem);
int is_same(char *s1, char *s2);
int get_c_index(char *str, char c);
void print_list2(t_cut_cmd *ptr);
void print_list(t_msh *msh);
char *debug_get_line_name(t_cut_cmd *to_print);
char *get_cwd(void);
char *get_prompt_of(t_msh *msh, char *cwd);
int get_line(t_msh *msh, char *str);
void get_line_info(t_cut_cmd *to_debug);
void msh_debug(t_msh *msh, char *elem);
void print_split(char **split);
