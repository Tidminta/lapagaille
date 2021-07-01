/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:42:49 by loamar            #+#    #+#             */
/*   Updated: 2021/05/24 18:18:30 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
**	**	**	**	**	**	**	**	**	**	**	**
**	T_MSH -> ?								**
**											**
**	**	**	**	**	**	**	**	**	**	**	**
*/

typedef struct			s_msh
{
	struct s_utils		*utils;
	struct s_data		*data;
	struct s_list		*list;
	struct s_lair_list	*lair_list;
	struct s_env_list	*env_list;
	struct s_env_lair	*env_lair;
}						t_msh;

/*
**	**	**	**	**	**	**	**	**	**	**	**
**	T_UTILS -> ?							**
**											**
**	**	**	**	**	**	**	**	**	**	**	**
*/

typedef struct			s_utils
{
	pid_t				pid;
	pid_t				wpid;
	int					size_opt_arg;
	int					status;
	int					check_opt;
	int					check_arg;
	int					error_multi_line;
	char				**path;
	char				**sep_tab;
	char				**tab_args;
}						t_utils;

/*
**	**	**	**	**	**	**	**	**	**	**	**
**	T_SPLIT_DATA -> ?						**
**											**
**	**	**	**	**	**	**	**	**	**	**	**
*/

typedef struct			s_split_data
{
	int					nb;
	int					index;
	int					pos;
	int					check;
	int					word;
}						t_split_data;

/*
**	**	**	**	**	**	**	**	**	**	**	**
**	S_DATA -> ?								**
**	**	**	**	**	**	**	**	**	**	**	**
*/

typedef struct			s_data
{
	char				**prompt_data;
	int					size_data;
	int					check;
}						t_data;

/*
**	**	**	**	**	**	**	**	**	**	**	**
**	T_LIST	(DOUBLEMENT CHAINNEE )			**
**											**
**	STRUCT D'1 MAILLON DE LA LIST DES CMD	**
**	**	**	**	**	**	**	**	**	**	**	**
*/

typedef struct			s_list
{
	char				*content;
	int					token;
	struct s_list		*next;
	struct s_list		*previous;
}						t_list;

/*
**	**	**	**	**	**	**	**	**	**	**	**
**	T_LAIR_LIST (DOUBLEMENT CHAINEE)		**
**											**
**	LISTE DES CMD							**
**	**	**	**	**	**	**	**	**	**	**	**
*/

typedef struct			s_lair_list
{
	int					size;
	t_list				*start;
	t_list				*end;
}						t_lair_list;

/*
**	**	**	**	**	**	**	**	**	**	**	**
**	T_ENV_LIST				 				**
**											**
**	STRUCT D'1 MAILLON DE LA LISTE			**
**	DES VARIABLES D'ENV						**
**	**	**	**	**	**	**	**	**	**	**	**
*/

typedef struct			s_env_list
{
	char				*content;
	struct s_env_list	*next;
	struct s_env_list	*previous;
}						t_env_list;

/*
**	**	**	**	**	**	**	**	**	**	**	**
**	T_ENV_LAIR(DOUBLEMENT CHAINNEE)			**
**											**
**	LISTES DES VARIABLES D'ENV				**
**	**	**	**	**	**	**	**	**	**	**	**
*/

typedef struct		s_env_lair
{
	t_env_list			*start;
	t_env_list			*end;
	int					size;
}					t_env_lair;

#endif
