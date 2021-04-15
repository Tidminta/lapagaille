/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_built_ins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:59:38 by tidminta          #+#    #+#             */
/*   Updated: 2021/04/14 15:59:21 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void 	print_list(t_env_lair *env_lair)
{
	int 	test;

	test = 1;
	t_env_list *current;

	current = env_lair->start;
	printf("| DEBUT | \n");
	while (current != NULL)
	{
		printf("%d-> %s\n", test, current->content);
		current = current->next;
		test++;
	}
	printf("\n***\nsize env_lair -> %d\n", env_lair->size);
	printf("first env_lair -> %s\n", env_lair->start->content);
	printf("end  env_lair -> %s\n", env_lair->end->content);
	printf("| FIN |\n");
}

static int		ft_built_in_check(char *s)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen(s);
	while (++i < len)
		s[i] = ft_tolower(s[i]);
	if ((ft_strncmp(s, "echo", len) == 0)
	|| (ft_strncmp(s, "cd", len) == 0)
	|| (ft_strncmp(s, "pwd", len) == 0)
	|| (ft_strncmp(s, "export", len) == 0)
	|| (ft_strncmp(s, "unset", len) == 0)
	|| (ft_strncmp(s, "env", len) == 0)
	|| (ft_strncmp(s, "cd", len) == 0)
	|| (ft_strncmp(s, "list", len) == 0)
	|| (ft_strncmp(s, "exit", len) == 0))
		return (SUCCESS);
	else
		return (ERROR);
}

// detect args & options
// exec cmd + args & options
// renvoyer char ** pour les arguments ou options

static int				ft_exec_built_in(t_msh *msh, t_list *element, char **env)
{
	char	*content;
	size_t	len;
	int		i;

	content = element->content;
	len = ft_strlen(content);
	i = -1;
	/*  E X I T && L I S T */
	if (ft_strncmp(content, "exit", len) == 0)
		exit (0);
	else if (ft_strncmp(content, "list", len) == 0)
		print_list(msh->env_lair);
	/*  P W D  */
	else if ((ft_strncmp(content, "pwd", len) == 0))
	{
		if (ft_my_pwd() == ERROR)
			return (ERROR);
	}
	/*  E N V  */
	else if (ft_strncmp(content, "env", len) == 0)
	{
		if (ft_my_env(msh->env_lair) == ERROR)
			return (ERROR);
	}
	/*  E X P O R T  */
	else if (ft_strncmp(content, "export", len) == 0)
	{
		if ((ft_my_export(msh, element->next) == ERROR))
			return (ERROR);
	}
	/* U N S E T */
	else if (ft_strncmp(content, "unset", len) == 0)
	{
		if (ft_my_unset(msh, element->next) == ERROR)
			return (ERROR);
	}
	/* C D */
	else if (ft_strncmp(content, "cd", len) == 0)
	{
		if (ft_my_cd(msh, element->next) == ERROR)
			return (ERROR);
	}
	/* E C H O */
	else if (ft_strncmp(content, "echo", len) == 0)
	{
		if (ft_my_echo(msh, element->next) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int				ft_handler_built_in(t_msh *msh, t_list *element, char **env)
{
	char *content;

	if (!msh || !element || !env)
		return (ERROR);
	// printf("\n[BUILT IN HUNDLER]\n[opt args size][%i]\n", msh->utils->size_opt_arg);
	content = element->content;
	if (ft_built_in_check(content) != SUCCESS)
		return (ERROR);
	//builtin executiuon -> ptr_func_tab ou liste chainnée avec pointeur sur fct??
	ft_exec_built_in(msh, element, env);
	return (SUCCESS);
}
