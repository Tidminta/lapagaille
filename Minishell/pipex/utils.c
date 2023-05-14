/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:18:00 by tminta            #+#    #+#             */
/*   Updated: 2023/05/13 23:37:37 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

char	*first_word(char *str)
{
	char				*result;
	size_t				i;

	i = 0;
	while (str[i] && str[i] != ' ')
	{
		i++;
	}
	result = ft_substr(str, 0, i);
	return (result);
}

void	ft_free_tab(char **tb)
{
	int	i;

	i = -1;
	while (tb[++i])
		free(tb[i]);
}

void	ft_clean(t_pipe **box)
{
	free((*box)->pipe);
	free((*box)->cmd1->cmd_n);
	free((*box)->cmd1->cmd_p);
	ft_free_tab((*box)->cmd1->args);
	free((*box)->cmd1->args);
	free((*box)->cmd1);
	free((*box)->cmd2->cmd_n);
	free((*box)->cmd2->cmd_p);
	ft_free_tab((*box)->cmd2->args);
	free((*box)->cmd2->args);
	free((*box)->cmd2);
	free((*box));
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char		*alloc;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
		alloc = (char *)malloc(sizeof(char)
			* ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (alloc == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
	{
		while (s1[++i] != '\0')
			alloc[i] = s1[i];
	}
	while (s2[j] != '\0')
		alloc[i++] = s2[j++];
	alloc[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (alloc);
}
