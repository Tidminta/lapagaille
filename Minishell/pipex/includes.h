/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:19:27 by tminta            #+#    #+#             */
/*   Updated: 2023/05/11 19:30:33 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H


# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

# define	SUCCESS 1
# define	ERROR -1
# define	CMD 1
# define	FILE 2

typedef struct s_cmd
{
	char			*cmd_n;
	char			*cmd_p;
	char			**args;
	int				pos;
	struct s_cmd	*n;
	struct s_cmd	*p;
}				t_cmd;
// TOKEN : 1 = cmd | 2 = args

typedef	struct s_box
{
	struct s_cmd	*head;
	struct s_cmd	*tail;
	int				size;
}				t_box;

// typedef	struct s_files
// {
// 	char			*name;
// 	int				pos;
// 	struct s_files	*n;
// 	struct s_files	*p;
// }				t_files;

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
	t_box			*cmd_box;
	// t_files			*files;
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
	int				position;
}				t_pipe;

/* ******************************************** */
// INIT

int		ft_create_lstc(t_pipe **box);


/* ******************************************** */
//PARSING 

int		processing(t_pipe *box);

void	ft_init(t_pipe **box, char **argv, char **envp);

void	ft_parsing_step(t_pipe **box, char **argv, char **envp);

char	*ft_only_cmd(t_pipe *box, int indic);

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