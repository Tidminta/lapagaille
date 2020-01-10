
int		ft_strlen(char *str)
{
	int i;
​
	i = 0;
	while (str[i])
		i++;
	return (i);
}
​
int		ft_find_char(char c, char *str)
{
	int i;
​
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
​
int		ft_cpt_words(char *str, char *charset)
{
	int charset_len;
	int i;
	int cpt;
​
	i = 0;
	cpt = 0;
	charset_len = ft_strlen(charset);
	while (str[i])
	{
		while ((str[i]) && ft_find_char(str[i], charset) == 1)
			i++;
		if (i < ft_strlen(str))
			cpt++;
		while ((str[i]) && ft_find_char(str[i], charset) == 0)
			i++;
	}
	return (cpt);
}
​
char	*ft_strdup(int *i, char *str, char *charset)
{
	char	*string;
	int		cpt;
	int		j;
​
	cpt = 0;
	j = 0;
	while (str[*i] && ft_find_char(str[*i], charset) == 1)
		*i += 1;
	while (str[*i] && ft_find_char(str[*i], charset) == 0)
	{
		cpt++;
		*i += 1;
	}
	*i -= cpt;
	if (!(string = (char *)malloc(sizeof(char) * cpt + 1)))
		return (NULL);
	while (str[*i] && (j < cpt) && ft_find_char(str[*i], charset) == 0)
	{
		string[j] = str[*i];
		j++;
		*i += 1;
	}
	string[cpt] = '\0';
	return (string);
}
​
char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		word;
	int		i;
	int		j;
​
	word = 0;
	i = 0;
	j = -1;
	if (charset == NULL)
		charset = "";
	if ((str) && (charset))
	{
		word = ft_cpt_words(str, charset);
		if (!(tab = (char **)malloc(sizeof(char *) * word + 1)))
			return (0);
		while (++j < word)
			tab[j] = ft_strdup(&i, str, charset);
		tab[j] = 0;
		return (tab);
	}
	if (!(tab = (char **)malloc(sizeof(char *))))
		return (NULL);
	tab[0] = 0;
	return (tab);
}