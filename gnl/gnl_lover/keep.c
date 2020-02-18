char		*ft_strdup(char *s1)
{
	char	*alloc;
	int		i;
	int		len;

	i = 0;
	if (!s1 || s1[0] == '\0')
	{
		if (!(alloc = (char *)malloc(sizeof(char))))
			return (NULL);
		alloc[0] = '\0';
		return (alloc);
	}
	len = ft_strlen(s1) + 1;
	if (!(alloc = malloc(sizeof(char) * len)))
		return (NULL);
	ft_bzero(alloc, (size_t)len);
	if (i == 0 && s1[i] == '\n')
		alloc[i] = '\n';
	else
	{
		while (i < (len - 1) && s1[i] != '\n' && s1[i] != '\0')
		{
			alloc[i] = s1[i];
			i++;
		}
	}
	return (alloc);
}
