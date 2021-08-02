#include "../includes/libshell.h"

int add_to_env(t_cut_cmd **target, char *elem, t_TOKEN TOKEN);
void init_envp(t_msh *msh, char **envp);
t_cut_cmd *get_env_of(t_cut_cmd *target, char *to_find);
void init_env(t_msh *msh, char **envp);
int add_env(t_msh **msh, char *content, int mode);
int is_empty_env(t_cut_cmd *env);
int create_env_list(t_msh **msh, char *content);
