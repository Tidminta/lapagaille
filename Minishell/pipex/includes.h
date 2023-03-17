/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:19:27 by tminta            #+#    #+#             */
/*   Updated: 2023/03/16 19:52:41 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H


# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_pipe
{
	char	**envp;
	char	*file1;
	char	*cmd1;
	char	*file2;
	char	*cmd2;
	char	*path;
	int		pid;
	int		errno;
	int		fd1;
	int		fd2;
	int		pipe[2];
}				t_pipe;

int		processing(t_pipe *box);

t_pipe	*ft_init(char **argv, char **envp);

void	ft_open(t_pipe *box);

#endif