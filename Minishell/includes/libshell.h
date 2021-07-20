/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:52:06 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/20 23:19:45 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_SHELL_H
# define LIB_SHELL_H

/*
**
** HEADER_SIZE:
** 0 = Builtin (1) | Cmd(2) | opt(3) | arg(4)
** 1 = rsimple(1) | lsimple(2) |double(3) | pipe (4)
** 2 = quote (1) single (2) double
** 3 = div (voir ci dessous)
** 4 = firstcmd (1) | middle cmd (2) | lastcmd (3)
*/
# define H_CMDTYPE 0
# define H_SYMBOL 1
# define H_QUOTE 2
# define H_DIV 3
# define H_POS 4
# define HEADER_SIZE 5
# define PROMPT_NAME "msh% "

/*
** La liste des symbols uniques (pour le parsing) (if is_symbol(str[i]) ..."
*/
# define SYMBOL_LIST "> < |"
# define BUILTIN_LIST "echo cd pwd env export unset exit"

# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

# include "../libft/libft.h"
# include "./struct.h"
# include "./gc.h"
# include "./cmd.h"
# include "./ourlists.h"
# include "./error.h"

int				handle_env(t_msh *msh, char **envp);

int				find_path(t_msh *msh);

#endif
