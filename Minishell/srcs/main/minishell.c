/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:54:29 by loamar            #+#    #+#             */
/*   Updated: 2021/06/29 20:59:51 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// Bash tests
// ctrl + C : new prompt (sigint)
// ctrl + D : exit (sigquit)
// ctrl + \ : nothing

static void			signal_handler(int sign)
{
	// printf("[SIGNAL HANDLER][SIGNAL = %d]\n", sign);
	if (sign == SIGINT)
	{
		//nouveau prompt
		ft_putstr_fd("[NEWPROMPT]\n", 1);
		g_loop(SET, 1);
	}
}

static int				shell_prompt(t_msh *msh, char **env)
{
	int		loop;
	int		ret;
	char	*buf;

	loop = 1;
	ret = 0;

	g_loop(SET, 0);
	while (loop && g_loop(GET, 0) == 0)
	{
		write(1, "$my_minishell : ", 16);
		ret = get_next_line(0, &buf);
		if (ret == -1)
			return (ERROR);
		if ((handler_data(&msh, buf) == -1) || (handler_list(msh) == -1))
			return (handler_error(msh));
		handler_cmd(msh, env);
		//history_list(msh, buff);
		// free(buf);
	}
	if (g_loop(GET, 0) == RELOOP)
		return (RELOOP);
	return (SUCCESS);
}

int				main(int argc, char **argv, char **env)
{
	int				end;
	t_msh			*msh;

	(void)argc;
	(void)argv;
	end = 0;
	msh = NULL;
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	msh = init_shell(msh);
	handler_env(msh, env);
	end = shell_prompt(msh, env);
	if (end == SUCCESS)
		exit(EXIT_SUCCESS);
	if (end == ERROR)
		exit(EXIT_FAILURE);
	if (end == RELOOP)
	{
		// printf("[MAIN ASKING FOR A NEW PROMPT ..]\n");
		// sleep(1);
		shell_prompt(msh, env);
	}
	return (0);
}
