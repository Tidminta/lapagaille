/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:08:14 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/16 00:54:45 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libshell.h"

typedef struct	s_tmsh
{
	char	**cmd1;
	char	**cmd2;
	char	*grep_path;
	char	*cat_path;
	int		status;
	int		original_stdin;
	int		original_stdout;
	int		p[2];	
}				t_tmsh;

//void		pipe_fork(t_tmsh *msh, char **env)
//{
//	int pid;
//
//	dup2(1,msh->p[0]);
//	pid = fork();
//	if (pid == 0)
//	{
//		close(msh->p[1]);
//		dup2(msh->p[1], 1);
//		printf("pipe fork");
//		execve(msh->grep_path, msh->cmd2, env);
//		printf("grep error\n");
//		sleep(2);
//	}
//	else
//	{
//		close(msh->p[0]);
//		close(msh->p[1]);
//		waitpid(pid, &msh->status, 0);
//	}
//}

static void reg_exec(t_tmsh *msh, char **env)
{
	int		pid;

	pipe(msh->p);
	pid = fork();
	if (pid == 0)
	{
		//pipe_fork(msh, env);
		if (fork() == 0)
		{//LAST CMD
			close(msh->p[1]);
			dup2(msh->p[0], 0);
			execve(msh->grep_path, msh->cmd2, env);
			printf("second cmd error\n");
		}
		else
		{//FIRST CMD
			close(msh->p[0]);
			dup2(msh->p[1], 1);
			execve(msh->cat_path, msh->cmd1, env);
			printf("first cmd error\n");
		}
	}
	else
	{
		close(msh->p[0]);
		close(msh->p[1]);
		waitpid(pid, &msh->status, 0);
	}
}
	
t_tmsh		*init(void)
{
	t_tmsh *msh;

	msh = (t_tmsh*)malloc(sizeof(t_tmsh));

	msh->cmd1 = (char**)malloc(sizeof(char*) * 3);
	msh->cmd2 = (char**)malloc(sizeof(char*) * 3);
	msh->cmd1[0] = strdup("cat");
	msh->cmd1[1] = strdup("test.txt");
	msh->cmd1[2] = NULL;
	msh->cmd2[0] = strdup("grep");
	msh->cmd2[1] = strdup("est");
	msh->cmd2[2] = NULL;
	msh->grep_path = strdup("/usr/bin/grep");
	msh->cat_path = strdup("/bin/cat");
	msh->status = 0;
	msh->original_stdin = 0;
	msh->original_stdout = 1;
	return (msh);
}


int	main(int argc, char **argv, char **env)
{
	t_tmsh *msh;
	int		i;

	i = 0;
	(void)argv;
	(void)argc;
	msh = init();
	reg_exec(msh, env);
	return (0);

}
