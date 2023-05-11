/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidiane <tidiane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:19:27 by tminta            #+#    #+#             */
/*   Updated: 2023/05/10 01:05:37 by tidiane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H


# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

// typedef	struct	s_path
// {
// 	char	*content;
// 	t_path	*n;
// }				t_path;


// TOKEN : 1 = cmd | 2 = args

typedef struct s_pipe
{
	char			**envp;
	char			*file1;
	char			**cmd;
	char			*cmd1;
	char			**o_cmd1;
	char			**only_cmd;
	char			*file2;
	char			*cmd2;
	char			*o_cmd2;
	char			**path;
	char			**paths;
	char 			**args1;
	char 			**args2;
	char			***f_args;
	int				pid;
	int				err_no;
	int				fd1;
	int				fd2;
	int				pipe[2];
}				t_pipe;


/* ******************************************** */
//PARSING 

int		processing(t_pipe *box);

t_pipe	*ft_init(char **argv, char **envp);

void	ft_parsing_step(t_pipe **box, char **argv, char **envp);

char	*ft_only_cmd(t_pipe *box, int indic);

t_pipe	*ft_init(char **argv, char **envp);

void	ft_free_split2(t_pipe *box);

char	*split_path(char **envp);

int		ft_get_path(t_pipe	*box, int indic);

void	ft_parsing_step(t_pipe **box, char **argv, char **envp);


/* ******************************************** */
//EXEC
void	ft_exec(t_pipe	*box, int indic);

int		processing(t_pipe *box);

// void	ft_open(t_pipe *box);

#endif