#include "../includes/libshell.h"

void	init_jobs(t_msh **msh)
{
	(*msh)->jobs = (t_job*)malloc(sizeof(t_job));
	(*msh)->jobs->reading_line = NULL;
	(*msh)->jobs->have_been_read = NULL;
	(*msh)->jobs->prompt_status = 0;
}

void	init_tools(t_msh *msh)
{
	msh->tools = gc_malloc(sizeof(t_tools));
	if (!msh->tools)
		exit (0);
	msh->tools->fdin = 0;
	msh->tools->fdout = 0;
	msh->tools->nbpipe = 0;
	msh->tools->nbredir = 0;
	msh->tools->istmp = 0;
	msh->tools->tmpfd = 0;
	msh->tools->run_status = 1;
	msh->tools->tmp_status = 0;
	msh->tools->error_msg = NULL;
	msh->tools->marker = NULL;
	msh->tools->head = NULL;
	msh->tools->tail = NULL;
	msh->envp = NULL;
	msh->tools->pipe[0] = 0;
	msh->tools->pipe[1] = 0;
	msh->tools->status = 0;
	msh->tools->last_op = 0;
}

void	init_msh(t_msh **msh, char **envp)
{
	t_cut_cmd *ptr;
	*msh = (t_msh*)malloc(sizeof(t_msh));
	init_jobs(msh);
	init_tools(*msh);
	init_env(*msh, envp);
	ptr = get_env_of((*msh)->env->head, "PATH");
	(*msh)->path = ft_split(ft_split(ptr->elem, '=')[1], ':');
	(*msh)->envp = (*msh)->env->head;
}