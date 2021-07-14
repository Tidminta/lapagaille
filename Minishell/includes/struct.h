/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:33:58 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/09 23:27:44 by tidminta         ###   ########.fr       */
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

//[s_jobs] contient la ligne actuellement lue et le status du prompt
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
	int 	header[HEADER_SIZE];
	char	*elem;
	struct	s_cut_cmd *	n;
	struct	s_cut_cmd * p;
}			t_cut_cmd;

/*
** [s_tools] contient toutes les infos pour une seule execution
** reinitialier les valeurs de la stucture a zero avant de lire le prompt
** fd[0] = sortie de commande
** fd[1] = entrée de commande apres le pipe
*/
typedef struct		s_tools
{
	t_cut_cmd	*head;
	t_cut_cmd	*tail;
	int			pipe[2];
	int			nbpipe;
	int			nbredir;
	int			loop;
	int			fdin;
	int			fdout;
	int			last_fd;
	int			last_op;
	int			status;
	char		*error_msg;
}					t_tools;

/*
** [s_env] contient toutes les variables d'environement
*/
typedef struct	s_env
{
	char			*elem;
	struct s_env	*n;
	struct s_env	*p;
	
}				t_env;

/*
** [s_msh] contient toutes les structures
** explication de la structure tools au dessus
*/
typedef struct s_msh
{
	t_job		*jobs;
	t_cut_cmd	*line;
	t_cut_cmd	*quotes;
	t_tools		*tools;
	t_env		*e_head;
	t_env		*e_tail;
	int			run_status;
	char		**path;
	char		**envp;
}			t_msh;

#endif
