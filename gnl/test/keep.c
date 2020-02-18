*line = ft_strdup(str);
where = ft_where_is_nl(str);
printf("[avant sub]\nstr = %s\n", str);
str = ft_substr(str, where + 1, ft_strlen(str));
printf("[fin]\nline = %s\nstr = %s\n", *line, str);
// if (!str = ft_strchr(str, 10))
// return (0);









int				get_next_line(int fd, char **line)
{
	static char	*str;
	ssize_t		rd;
	char		buff[BUFF_SIZE + 1];
	int			where;

	if (fd < 0 || !(line) || BUFF_SIZE <= 0)
		return (-1);
	if (!str)
		str = ft_strdup("");
	// printf("[debut]\nstr = %s\n", str);
	// ft_bzero(buff, (size_t)BUFF_SIZE + 1);
	while ((!ft_strchr(str, 10)) && ((rd = read(fd, buff, BUFF_SIZE)) > 0))
	{
		buff[rd] = '\0';
		str = ft_strjoin(str, buff);
		// printf("[boucle]\nstr = %s\n", str);
	}
	if (str)
	{
		// printf("[avant strdup]\nline = %s\n", *line);
		*line = ft_strdup(str);
		// printf("[apres strdup]\nline = %s\n", *line);
		where = ft_where_is_nl(str);
		// printf("[avant substr]\nstr = %s\n", str);
		str = ft_substr(str, where + 1, ft_strlen(str));
		// printf("[apres substr]\nstr = %s\n", str);
		// printf("[fin]\nline = %s\nstr = %s\n", *line, str);
	}
	if (rd == 0)
	{
		// *line = ft_strdup(str);
		// printf("[return(0)]\nline = %s\nstr = %s\nbuff = %s\n", *line, str, buff);
		// printf("\nICI RD == 0\n");
		return (0);
	}
	return (1);
}




int				get_next_line(int fd, char **line)
{
	// printf("[gnl]\n");
	static char	*str;
	ssize_t		rd;
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	(!str) ? str = ft_strdup("") : 0;
	ft_bzero(buff, BUFFER_SIZE + 1);
	// printf("[debut]\nstr = %s\n", str);
	while ((!ft_strchr(str, 10)) && ((rd = read(fd, buff, BUFFER_SIZE))))
	{
		// printf("[CA BOUCLE FORT ICI !!]\n");
		str = ft_strjoin(str, buff);
	}
	// printf("\n[sorie de boucle rd = %zi]\n", rd);
	*line = ft_strdup(str);
	// printf("\n[apres strdup]\n*line = [%s]\n", *line);
	str = ft_where_is_nl(str);
	// printf("\n[apres substr]str = [%s]\n", str);
	// printf("[avant if]rd = %zi\n", rd);
	if (rd == 0)
	{
		free(str);
		str = NULL;
		return (0);
	}
	return (1);
}

