/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:42:01 by loamar            #+#    #+#             */
/*   Updated: 2021/06/29 20:36:08 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

void			ft_free_separator_tab(t_msh *msh)
{
	int		i;
	char	**tab;

	i = -1;
	tab = msh->utils->sep_tab;
	while (msh->utils->sep_tab[++i])
		free(msh->utils->sep_tab[i]);
	// free(msh->utils->sep_tab);
}

int					fill_separator_tab(t_msh *msh)
{
	int		pos;

	pos = 0;
	if (!(msh->utils->sep_tab = (char**)malloc(sizeof(char*) * 8)))
		return (ERROR);
	while (pos < 8)
	{
		if (!(msh->utils->sep_tab[pos] = (char*)malloc(sizeof(char) * 3)))
			return (ERROR);
		pos++;
	}
	msh->utils->sep_tab[0] = "|\0\0";
	msh->utils->sep_tab[1] = ";\0\0";
	msh->utils->sep_tab[2] = "<\0\0";
	msh->utils->sep_tab[3] = ">\0\0";
	msh->utils->sep_tab[4] = ">>\0";
	msh->utils->sep_tab[5] = "&&\0";
	msh->utils->sep_tab[6] = "||\0";
	msh->utils->sep_tab[7] = NULL;
	return (SUCCESS);
}

static void			aff_welcome(void)
{
	ft_putstr("\n");
	ft_putstr("   +--------------+\n");
	ft_putstr("   |.------------.|\n");
	ft_putstr("   ||            ||\n");
	ft_putstr("   || WELCOME TO ||\n");
	ft_putstr("   ||  MINISHELL ||\n");
	ft_putstr("   ||            ||\n");
	ft_putstr("   |+------------+|\n");
	ft_putstr("   +-..--------..-+\n");
	ft_putstr("   .--------------.\n");
	ft_putstr("  | .============. | \n");
	ft_putstr(" | .==============. | \n");
	ft_putstr("| ___________________| \n");
	ft_putstr("|____________________| \n");
	ft_putstr("*+*                *+* \n\n");
}

t_msh				*init_shell(t_msh *msh)
{
	aff_welcome();
	return (init_msh(msh));
}
