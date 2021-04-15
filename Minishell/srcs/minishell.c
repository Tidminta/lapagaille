/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:54:29 by loamar            #+#    #+#             */
/*   Updated: 2021/04/14 17:12:12 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Votre shell doit :
   • Afficher un prompt en l’attente d’une nouvelle commande
   • Chercher et lancer le bon executable (basé sur une variable d’environnement PATH
   ou en utilisant un path absolu), comme dans bash
   • Vous devez implémenter les builtins suivants :
   ◦ echo et l’option ’-n’
   ◦ cd uniquement avec un chemin absolu ou relatif
   ◦ pwd sans aucune option
   ◦ export sans aucune option
   ◦ unset sans aucune option
   ◦ env sans aucune option ni argument
   [DONE ?]◦ exit sans aucune option
	AUTORISED FUNCTIONS
	malloc, free, write, open, read, close, fork, wait,
	waitpid, wait3, wait4, signal, kill, exit, getcwd,
	chdir, stat, lstat, fstat, execve, dup, dup2, pipe,
	opendir, readdir, closedir, strerror, errno
   • ; dans la ligne de commande doit séparer les commandes
   • ’ et " doivent marcher comme dans bash, à l’exception du multiligne.
   • Les redirections <, > et “>>” doivent marcher comme dans bash, à l’exception des
   aggrégations de fd
   • Pipes | doivent marcher comme dans bash
   • Les variables d’environnement ($ suivi de caractères) doivent marcher comme dans
   bash.
   • $? doit marcher comme dans bash
   • ctrl-C, ctrl-D et ctrl-\ doivent afficher le même résultat que dans bash.
	**** dont forget  int redirection in ft_handle
	**** if (redirection) stocker dans char* sinn putchar_fd
		// signal(SIGINT, signal_handler);
		// system("leaks minishell");

   */

#include "../includes/libshell.h"

static int     	shell_prompt(t_msh *msh, char **env, char *test)
{
	int		loop;
	int		ret;
	char	*buf;

	loop = 1;
	ret = 0;
	signal(SIGINT, SIG_IGN);
	while (loop)
	{
		write(1, "minishell$ ", 11);
		ret = get_next_line(0, &buf);
		if (ret == -1)
			return (ERROR);
		if ((handler_data(msh, /*buf*/test) == -1) || (handler_list(msh) == -1))
			return (handler_error(msh));
		handler_cmd(msh, env);
	}
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
	msh = init_shell(msh);
	handler_env(msh, env);
	end = shell_prompt(msh, env, argv[2]);
	if (end == SUCCESS)
		exit(EXIT_SUCCESS);
	if (end == ERROR)
		exit(EXIT_FAILURE);
	return (0);
}
