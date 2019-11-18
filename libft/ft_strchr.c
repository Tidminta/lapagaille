/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:54:08 by tidminta          #+#    #+#             */
/*   Updated: 2019/11/18 20:05:39 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	match;

	i = 0;
	match = (char)c;
	while (s[i])
	{
		while (s[i] != match)
			i++;
		if (s[i] == match)
			return (s + i);
	}
	return (s);
}
