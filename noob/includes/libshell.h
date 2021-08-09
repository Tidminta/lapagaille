/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:52:06 by tidminta          #+#    #+#             */
/*   Updated: 2021/08/02 13:28:27 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_SHELL_H
# define LIB_SHELL_H

/*
**
** HEADER_SIZE:
** 0 = Builtin (1) | Cmd(2) | opt(3) | arg(4)
** 1 = symbol -> simple(1) | double (2) | pipe (3)
** 2 = quote (39) single (34) double (!valeur ascii en int)
** 3 = div (voir ci dessous)
** 4 = nombre de pipe
*/

# define $BR exit (0);
# define $OKOK printf("OKOK\n");
# define $ENDL printf("\n");
# define $PF(x) printf(x);
# define $MARK(x) printf("MARK: ");printf(x);printf("\n");
# define $ZERO '\0'
# define $PRINT(x, y) printf(x, y); 

# define H_CMDTYPE 0
# define H_SYMBOL 1
# define H_QUOTE 2
# define H_DIV 3
# define HEADER_SIZE 4
# define PROMPT_NAME "->"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\033[45;1m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/*
** La liste des symbols uniques (pour le parsing) (if is_symbol(str[i]) ..."
*/

# define SYMBOL_LIST ">:<:|:&"
# define SYMBOL_DETERMINE "| > >> < << || && ( )"
# define BUILTIN_LIST "echo cd pwd env export unset exit"

/*
** ERROR_MSG
*/

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <string.h>
# include <dirent.h>
# include "../libft/libft.h"
# include "./struct.h"
# include "./gc.h"
# include "cmd.h"

void		init_msh(t_msh **msh, char **envp);
void		init_env(t_msh *msh, char **envp);


int			is_same(char *s1, char *s2);
int			c_is_present(char *str, char c);
int			get_enum_len(void);
void		print_list2(t_cut_cmd *ptr2);
void		print_list(t_msh *msh);
char		get_next_char(char *str, int i, char *regex);
int			get_next_quote(char *str, int i);
void		p_putchar_str(char **str, char c);
t_cut_cmd	*fill(char *elem, t_TOKEN TOKEN);
t_cut_cmd	*get_env_of(t_cut_cmd *target, char *to_find);
int			add(t_msh *msh, char *elem, t_TOKEN TOKEN);
char		*debug_get_line_name(t_cut_cmd *to_print);
void		get_line_info(t_cut_cmd *to_debug);
void		msh_debug(t_msh *msh, char *elem);
int			is_symbol(char c);
int			is_quote(char c, char type);
char		*p_near(char *str);
int			is_builtin(char *str);
void		print_split(char **split);
char		*n_dup(char *str, int start, int end);
char		*str_modulo(char *src, char **modulo, int inc);
int			is_match(char *list, char sep, char *elem);
int			is_match2(char *list, char sep, char *elem);
int			split_len(char **split);
int			p_p_ready_to_process(t_msh *msh);
void		write_error(t_msh *msh);
int			get_line(t_msh *msh, char *str);
void		handler(int n);
void		init_jobs(t_msh **msh);
void		init_tools(t_msh *msh);
int			_placeholder_handle_cmd(t_msh *msh);

int			p_process_line(t_msh *msh);
int			p_check_par(t_msh *msh, char *str);
char		find_quote(t_msh *msh, char quote, int remove);
int			get_next_quote2(char *src, char **dst);
int			split_quotes(t_msh *msh, char *ptr);
int			p_check_quotes(t_msh *msh);
int			add_symbol(t_msh *msh, char *str, char *ret, int i);
int			p_check_symbols(t_msh *msh, char *str);
int			escape_symbol(t_msh *msh, char *str, char **ret, int i);
int			p_str_to_struct(t_msh *msh, char *str);
char		*p_escape_line(t_msh *msh, char *str);
int			p_p_check_par_join(t_msh *msh);
int			p_quote_to_struct(t_msh *msh, char *str);
int			p_p_determine_token(t_msh *msh);
int			get_c_index(char *str, char c);
t_TOKEN		p_p_determine_symbol(char *elem);
t_TOKEN		p_p_determine_cmd(char *elem, int cmd_re_eval);

#endif
