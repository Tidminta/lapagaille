/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:52:06 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/30 20:12:16 by motoure          ###   ########.fr       */
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
# define $OKOK printf("OKOK");
# define $ENDL printf("\n");
# define $MARK(x) printf("MARK: ");printf(x);printf("\n");
# define $ZERO '\0'
# define $PRINT(x, y) printf(x, y); 

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
# include "./struct.h"
# include "./gc.h"
# include "cmd.h"
# include "../_IO/IO.h"
# include "../_IO/pipe/pipe.h"
# include "../_cmd_exec/cmd_exec.h"
# include "../_env/env.h"
# include "../init/init.h"
# include "../error/error.h"
# include "../_builtins/builtins.h"
# include "../parsing/string_utils.h"
# include "../parsing/parsing_pass1/parsing_pass1.h"
# include "../parsing/parsing_pass2/parsing_pass2.h"
# include "../libft/libft.h"
#endif
