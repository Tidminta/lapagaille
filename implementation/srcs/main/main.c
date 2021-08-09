#include "../../includes/libshell.h"

int	main(int argc, char **argv, char **envp)
{
	t_msh	*msh;

	gc_init();
	(void)argc;
	(void)argv;
	gc("pause");
	init_msh(&msh, envp);
	gc("resume");
	signal(SIGINT, handler);
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
