/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:46:33 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/13 17:09:38 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

char	get_next_char(char *str, int i, char *regex)
{
	int y;

	if (!str[i])
		return (0);
	while (str[i])
	{
		y = -1;
		while (regex[++y])
		{
			if (regex[0] == str[i])
				continue ;
			else
				return (str[i]);
		}
		i++;
	}
	return (0);
}

void	p_putchar_str(char **str, char c)
{
	char *ptr;
	char *tmp;

	ptr = *str;
	tmp = NULL;
	if (!ptr)
	{
		ptr = ft_strdup("c");
		if (!ptr)
			return ;
		ptr[0] = c;
		*str = ptr;
		return ;
	}
	tmp = ft_strjoin(*str, "c");
	tmp[ft_strlen(tmp) - 1] = c;
	*str = tmp;
}

// t_cut_cmd		*fill(char *elem, int header[HEADER_SIZE])
// {
// 	t_cut_cmd *ret;
// 	int i;

// 	i = -1;
// 	if (!(ret = malloc(sizeof(t_cut_cmd))))
// 		return (0);
// 	ret->elem = to_gc(&ret->elem, ft_strdup(elem));
// 	while (++i < HEADER_SIZE)
// 		ret->header[i] = header[i];
// 	ret->n = NULL;
// 	ret->p = NULL;
// 	return (ret);
// }

// int			add(t_msh *msh, char *elem, int header[HEADER_SIZE])
// {
// 	t_cut_cmd *ret;

// 	ret = fill(elem, header);
// 	if (!msh->tools->head)
// 	{
// 		msh->tools->head = ret;
// 		msh->tools->tail = msh->tools->head;
// 		return (1);
// 	}
// 	ret->n = msh->tools->head;
// 	msh->tools->head->p = ret;
// 	msh->tools->head = ret;
// 	return (1);
// }

void	init_jobs(t_job *jobs)
{
	jobs->prompt_status = 0;
	jobs->reading_line = NULL;
	jobs->have_been_read = NULL;
}

void	init_msh(t_msh *msh)
{
	msh->jobs = (t_job*)malloc(sizeof(t_job));
	msh->line = NULL;
	msh->quotes = NULL;
	msh->tools = (t_tools*)malloc(sizeof(t_tools));
	msh->tools->head = NULL;
	msh->tools->tail = NULL;
	ft_memset(msh->tools->pipe, 0, 2);
	msh->tools->loop = 0;
	msh->tools->fdin = dup(0);
	msh->tools->fdout = dup(1);
	msh->tools->last_fd = 0;
	msh->tools->nbpipe = 2;
	msh->tools->nbredir = 0;
	msh->tools->last_op = 0;
	msh->tools->status = 0;
	msh->tools->error_msg = NULL;
	msh->e_head = NULL;
	msh->e_tail = NULL;
	msh->run_status = 1;
	msh->path = NULL;
	msh->envp = NULL;
}

void	ready_for_input(t_msh *msh)
{
	msh->tools->head = NULL;
	msh->tools->tail = NULL;
	msh->line = NULL;
	msh->quotes = NULL;
}

void	initializer(t_msh **mssh,char **envp)
{
	t_msh *msh;

	msh = *mssh;
	init_msh(msh);
	init_jobs(msh->jobs);
	ready_for_input(msh);
	handle_env(msh, envp);
	init_cmd(msh);
	printf("INIT MSH OK ...\n");
}

char	*debug_get_line_name(t_cut_cmd *to_print)
{
	char *ret;

	ret = NULL;
	t_cut_cmd *ptr;

	ptr = to_print;
	while (!(!ptr->p))
		ptr = ptr->p;
	while (ptr)
	{
		if (!ret)
			ret = to_gc(&ret, ft_strdup(ptr->elem));
		else
			ret = to_gc(&ret, ft_strjoin(ft_strjoin(ret, " "), ptr->elem));
		ptr = ptr->n;
	}
	return (ret);
}

void	get_line_info(t_cut_cmd *to_debug)
{
	int i;
	char *str;
	t_cut_cmd *ptr;

	i = -1;
	ptr = to_debug;
	printf("Line:%s\n\telem: %s\n\theader[C S Q]: ", debug_get_line_name(ptr), ptr->elem);
	while (++i < HEADER_SIZE)
		printf("%d ", ptr->header[i]);
	printf("\n");
	while ((str = to_gc(&str, readline("next / prev > "))))
	{
		if ((!ft_strncmp("prev", str, 4) || !ft_strncmp("p", str, 1)) && ptr->n)
			ptr = ptr->n;
		if ((!ft_strncmp("next", str, 4) || !ft_strncmp("n", str, 1)) && ptr->p)
			ptr = ptr->p;
		i = -1;
		if (ptr)
		{
			printf("Line:\n\telem: %s\nheader[C S Q]: ", ptr->elem);
			while (++i < HEADER_SIZE)
				printf("%d ", ptr->header[i]);
			printf("\n");
		}
	}

}

void	msh_debug(t_msh *msh, char *elem)
{
	if (!ft_strncmp(ft_strtrim(elem, " "), "line", 4))
		get_line_info(msh->tools->tail);

}

int	is_symbol(char c)
{
	char **symbols;
	int i;

	i = 0;
	symbols = ft_split(SYMBOL_LIST, ' ');
	while (symbols[i])
	{
		if (symbols[i][0] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_quote(char c, char type)
{
	if (c == type)
		return (1);
	return (0);
}

char	*p_near(char *str)
{
	char *ret;
	char *ret2;

	if (!ft_strncmp(str, "endl", ft_strlen(str)))
		ret2 = ft_strdup("\\n");
	else
		ret2 = ft_strndup(str, 1);
	ret = ft_strjoin("parse error near '", ret2);
	ret = to_gc(&ret, ft_strjoin(ret, "'"));
	return (ret);
}

int	add_symbol(t_msh *msh, char *ret, int i)
{
	char **split;
	char *ptr;
	//(void)msh;

	//msh->error_msg = to_gc(&msh->error_msg, p_near(ret));
	ptr = msh->jobs->have_been_read + i + 1;
	split = ft_split(ptr, ' ');
	if (!split[0])
	{
		msh->tools->error_msg = to_gc(&msh->tools->error_msg, p_near("endl"));
		return (0);
	}
	if (is_symbol(split[0][0]))
	{
		if (((split[0][0] == '>' && msh->jobs->have_been_read[i] == '>') ||
		(split[0][0] == '<' && msh->jobs->have_been_read[i] == '<')) && !is_symbol(split[0][1]))
		{
			if (!split[0][1] && !split[1])
			{
				msh->tools->error_msg = to_gc(&msh->tools->error_msg, p_near("endl"));
				return (0);
			}
			return (1);
		}
		msh->tools->error_msg = to_gc(&msh->tools->error_msg, p_near(ret));
		return (0);
	}
	return (1);
}

int	p_check_symbols(t_msh *msh)
{
	int i;
	char *ret;

	i = 0;
	ret = NULL;
	while (msh->jobs->have_been_read[i])
	{
		if (is_symbol(msh->jobs->have_been_read[i]))
		{
			ret = to_gc(&ret, ft_strndup(msh->jobs->have_been_read + i, 1));
			if (!add_symbol(msh, ret, i))
				return (0);
		}
		i++;
	}
	return (1);
}

int	escape_symbol(t_msh *msh, char **ret, int i)
{
	p_putchar_str(ret, ' ');
	while (is_symbol(msh->jobs->have_been_read[i]))
	{		
		p_putchar_str(ret, msh->jobs->have_been_read[i]);
		i++;
	}
	p_putchar_str(ret, ' ');
	return (i);
}

int	is_builtin(char *str)
{
	char **list;
	int i;

	i = 0;
	list = ft_split(BUILTIN_LIST, ' ');
	while (list[i])
	{
		if (!ft_strncmp(str, list[i], ft_strlen(str)))
			return (1);
		i++;
	}
	return (0);
}

int	p_str_to_struct(t_msh *msh, char *str)
{
	int i;
	int y;
	int header[HEADER_SIZE];
	char **split;

	i = 1;
	y = -1;
	if (!str)
		split = ft_split(msh->jobs->have_been_read, ' ');
	else
		split = ft_split(str, ' ');
	while (++y < HEADER_SIZE)
		header[y] = 0;
	if (!is_builtin(split[0]))
		header[H_CMDTYPE] = 1;
	else
		header[H_CMDTYPE] = 0;
	add(msh, split[0], header);
	while (split[i])
	{
		y = -1;
		while (++y < HEADER_SIZE)
			header[y] = 0;
		if (is_symbol(split[i][0]))
			header[H_SYMBOL] = 1;
		else if (split[i][0] == '-')
			header[H_CMDTYPE] = 2;
		else
			header[H_CMDTYPE] = 3;
		add(msh, split[i], header);
		i++;
	}
	return (1);
}

void	print_list(t_msh *msh)
{
	t_cut_cmd *ptr;

	ptr = msh->tools->head;
	while (ptr)
	{
		printf("%s\n", ptr->elem);
		ptr = ptr->n;
	}
}

int	get_next_quote(char *str, int i)
{
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\"' && str[i] != '\'')
		i++;
	if (!i)
		i = -1;
	return (i);
}

char	*n_dup(char *str, int start, int end)
{
	char *ret;

	ret = NULL;
	if (!start || !end || end - start > ft_strlen(str))
		return (ret);
	while (start < end)
	{
		p_putchar_str(&ret, str[start]);
		start++;
	}
	return (ret);
}

int	split_quotes(t_msh *msh, char *ptr)
{
	(void)msh;
	int start_end[2];
	int i;
	char *str;

	str = NULL;
	i = 0;
	start_end[0] = 0;
	start_end[1] = 0;
	if (!ptr)
	{
		ptr = msh->jobs->have_been_read;
		p_str_to_struct(msh, ft_strndup(ft_strtrim(ptr, " "), get_next_quote(ptr, 0)));
		ptr += get_next_quote(ptr, get_next_quote(ptr, 0)) - 1;
		return (split_quotes(msh, ptr));
	}
	start_end[0] = get_next_quote(ptr, start_end[0]);
	start_end[1] = get_next_quote(ptr, start_end[0] + 1);
	str = n_dup(ptr, 0, start_end[0]);
	while (ptr[start_end[1]] != ptr[start_end[0]])
		start_end[1] = get_next_quote(ptr, start_end[1] + 1);
	while (ptr[start_end[1] + 1] == ptr[start_end[1]])
	{
		start_end[1] += 2;
		while (ptr[start_end[1]] != ptr[start_end[0]])
			start_end[1] = get_next_quote(ptr, start_end[1] + 1);
	}
	p_str_to_struct(msh, n_dup(ptr, start_end[0], start_end[1] + 1));
	printf("%s\n", n_dup(ptr, start_end[0], start_end[1] + 1));
	if (str)
		str = ft_strtrim(str, " ");
	if (str && ft_strncmp(str, "", 1))
		p_str_to_struct(msh, str);
	ptr += start_end[1] + 1;
	if (!ft_strncmp(ptr, "", 1) || !ptr)
		return (1);
	return (split_quotes(msh, ptr));
}

int	p_check_quotes(t_msh *msh)
{
	int i;
	int mark_double;
	int	mark_single;

	i = 0;
	mark_double = 0;
	mark_single = 0;
	while (msh->jobs->have_been_read[i])
	{
		if (msh->jobs->have_been_read[i] == '\"')
			mark_double++;
		else if (msh->jobs->have_been_read[i] == '\'')
			mark_single++;
		i++;
	}
	if (mark_double % 2 != 0 || mark_single % 2 != 0)
	{
		msh->tools->error_msg = to_gc(&msh->tools->error_msg, ft_strdup("dquote not supported"));
		return (0);
	}
	if (mark_double || mark_single)
		return (split_quotes(msh, NULL));
	return (1);
}

void	p_escape_line(t_msh *msh)
{
	int i;
	char *ret;

	i = 0;
	ret = NULL;
	while (msh->jobs->have_been_read[i])
	{
		if (is_symbol(msh->jobs->have_been_read[i]))
			i = escape_symbol(msh, &ret, i);
		p_putchar_str(&ret, msh->jobs->have_been_read[i]);
		i++;
	}
	msh->jobs->have_been_read = to_gc(&msh->jobs->have_been_read, ft_strdup(ret));
}

int	process_line(t_msh *msh)
{
	//copie la ligne lue dans la variabe msh.have_been_read qui va etre utilisee pour le parsing
	msh->jobs->have_been_read = to_gc(&msh->jobs->have_been_read, ft_strdup(msh->jobs->reading_line));
	//check si il y a des erreurs de parsing au niveau des symbols uniquement
	if (!p_check_symbols(msh) || !p_check_quotes(msh))
		return (0);
	//escape les symbols sur msg.have_been_read pour pouvoir split les espaces ultierieurement
	p_escape_line(msh);
	//decoupe la chaine et la stock dans la struct s_cut_cmd *line et remplis les headers  !SI [msh->head] EST VIDE (p_check_quotes rempli la struct si des quotes sont presentes)
	if (!msh->tools->head)
		p_str_to_struct(msh, NULL);
	return (1);
}

//Ecris l'erreur stock dans msh.error_msg
void	write_error(t_msh *msh)
{
	if (msh->tools->error_msg)
	{
		write(2, msh->tools->error_msg, ft_strlen(msh->tools->error_msg));
		write(2, "\n", 1);
	}
	msh->tools->error_msg = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_msh *msh;
	(void)argc;
	(void)argv;
	
	msh = (t_msh*)malloc(sizeof(t_msh));
	initializer(&msh, envp);
	while (msh->run_status)
		handle_cmd(msh);
	return (0);
}
	// while ((msh->run_status))
	// {
	// 	if (!msh->jobs->prompt_status)
	// 		msh->jobs->reading_line = to_gc(&msh->jobs, readline(PROMPT_NAME));
	// 	if (!ft_strncmp(msh->jobs->reading_line, "msh_debug", 9) && msh->tools->head)
	// 		msh_debug(msh, msh->jobs->reading_line + 9);
	// 	if (msh->jobs->have_been_read)
	// 	{
	// 		process_line(msh);
	// 		handle_cmd(msh);
	// 	}
	// 	msh->jobs->prompt_status = 0;
	// 	write_error(msh);
	// }
	// collect();
// }
