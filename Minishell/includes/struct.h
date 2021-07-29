/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:33:58 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/29 18:35:08 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
** ICI NOUS METTRONS TOUTES LES STRUCTURES QUE NOUS UTILISERONS
**
*/

#ifndef STRUCT_H
# define STRUCT_H
#include "./libshell.h"

typedef enum TOKEN
{
	_START,
	_UNASSIGNED,
	C_BUILTIN,
	C_ENV,
	LAST_CMD,
	ARG,
	OPTION,
	S_QUOTE,
	D_QUOTE,
	WILD_CARD,
	PIPE,
	R_REDIR,
	D_R_REDIR,
	L_REDIR,
	D_L_REDIR,
	OR,
	AND,
	OPEN_DIV,
	CLOSED_DIV,
	_END,
}	t_TOKEN;

/*
**[s_jobs] contient la ligne actuellement lue et le status du prompt
*/
typedef struct s_jobs
{
	char	*reading_line;
	char	*have_been_read;
	int		prompt_status;
}			t_job;

/*
** [s_cut_cmd] contient la ligne lue divisee par type
** le type est stocke dans le header: voir includes/libshell.h
** pour les details sur la place des index
*/
typedef struct s_cut_cmd
{
	int			header[HEADER_SIZE];
	t_TOKEN		TOKEN;
	char		*elem;
	struct		s_cut_cmd *	n;
	struct		s_cut_cmd * p;
}				t_cut_cmd;

typedef struct	s_env_list
{
	struct s_cut_cmd	*tail;
	struct s_cut_cmd	*head;
	int					size;
}				t_env_list;

/*
** [s_tools] contient toutes les infos pour une seule execution
** reinitialier les valeurs de la stucture a zero avant de lire le prompt
*/
typedef struct		s_tools
{
	t_cut_cmd	*head;
	t_cut_cmd	*tail;
	t_cut_cmd	*tmp_node;
	int			fdin;
	int			fdout;
	int			tmpfd;
	int			nbpipe;
	int			nbredir;
	int			istmp;
	int			last_op;
	int			status;
	int			run_status;
	int			tmp_status;
	int			pipe[2];
	char		*error_msg;
	char		*marker;
}					t_tools;

/*
** [s_msh] contient toutes les structures
** explication de la structure tools au dessus
*/
typedef struct s_msh
{
	t_job		*jobs;
	t_cut_cmd	*line;
	t_cut_cmd	*envp;
	t_env_list	*env;
	char		**path;
	t_tools		*tools;
}			t_msh;

#endif
