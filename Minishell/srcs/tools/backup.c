// static int	ft_count_word(t_msh *msh, char *str)
// {
// 	int		cpt;
// 	int		indic;
// 	int		i;

// 	if (!msh || !str)
// 		return (ERROR);
// 	cpt = 0;
// 	indic = 0;
// 	i = 0;
// 	if (ft_isalnum(str[0]) && (str[i] != 36 && str[i] != 32))
// 		cpt = 1;
// 	while (str[i])
// 	{
// 		if ((str[i] == ' ' || str[i] == '$')
// 			&& (str[i + 1] && (str[i + 1] >= 33 && str[i + 1] <= 126)))
// 			cpt++;
// 		i++;
// 	}
// 	while (str[--i] && !indic)
// 		if (str[i] != ' ' || str[i] != '$')
// 			indic++;
// 	if (!indic)
// 		cpt = 1;
// 	return (cpt);
// }
