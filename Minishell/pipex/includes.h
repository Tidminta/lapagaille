/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:19:27 by tminta            #+#    #+#             */
/*   Updated: 2023/05/13 23:27:34 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>

# define SUCCESS 1
# define ERROR -1
# define CMD 1
# define FILE 2

typedef struct s_cmd
{
	char			*cmd_n;
	char			*cmd_p;
	char			**args;
	int				pos;
	struct s_cmd	*n;
}				t_cmd;

typedef struct s_pipe
{
	t_cmd			*cmd1;
	t_cmd			*cmd2;
	char			**argv;
	char			**envp;
	int				argc;
	char			**path;
	int				pid;
	int				fd1;
	int				fd2;
	int				*pipe;
	char			*file1;
	char			*file2;
}				t_pipe;

/* ******************************************** */
// INIT

int		ft_create_lstc(t_pipe **box);

void	ft_init(t_pipe **box, char **argv, char **envp);

/* ******************************************** */
//PARSING 

void	ft_parsing_step(t_pipe **box, char **argv, char **envp);

void	ft_free_split2(t_pipe *box);

char	*split_path(char **envp);

void	ft_get_path(t_pipe	*box, int indic, int i);

void	ft_parsing_step(t_pipe **box, char **argv, char **envp);

char	*first_word(char *str);

int		processing(t_pipe *box);

void	ft_clean(t_pipe **box);

void	ft_free_tab(char **tb);

char	*ft_strjoin2(char *s1, char *s2);

#endif