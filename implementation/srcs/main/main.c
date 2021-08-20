#include "../../includes/libshell.h"

void	signal_handler(int signal)
{
	(void)signal;
	ft_putendl_fd("SIGNAL OCCURS", 2);
	// exit (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_msh	*msh;

	gc_init();
	(void)argc;
	(void)argv;
	gc("pause");
	init_msh(&msh, envp);
	gc("resume");
	signal(SIGINT, signal_handler);
	while (msh->tools->run_status)
	{
		get_line(msh, NULL);
		if (p_process_line(msh))
			_placeholder_handle_cmd(msh);
		write_error(msh);
		msh->jobs->have_been_read = (msh->jobs->reading_line = NULL);
		msh->tools->head = (msh->tools->tail = NULL);
		gc("collect");
	}
	gc("collect -all");
	return (0);
}
