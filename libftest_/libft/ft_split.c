/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:30:24 by tidminta          #+#    #+#             */
/*   Updated: 2019/12/18 22:32:36 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int            ft_is_present(char const *s, unsigned int *index, char c)
{
    if (s[*index] && s[*index] == c)
        return (1);
    else
        return (0);
}

unsigned int            ft_words(char const *s, char c)
{
    unsigned int i;
    unsigned int words;

    i = 0;
    words = 0;
    while (s[i])
    {
        if (ft_is_present(s, &i, c) == 0)
        {
            words++;
            while ((s[i]) && (ft_is_present(s, &i, c) == 0))
                i++;
        }
        else
            while ((s[i]) && (ft_is_present(s, &i, c) == 1))
                i++;
    }
    printf("words = %i\n", words);
    return (words);
}

unsigned int            ft_strlen2(const char *s, unsigned int *index, char c)
{
    unsigned int    len;

    len = 0;
    while (ft_is_present(s, index, c) == 0)
    {
        *index += 1;
        len++;
    }
    return (len);
}

char                    **ft_split(char const *s, char c)
{
    char            **tab;
    unsigned int    words;
    unsigned int    cpt;
    unsigned int    i;
    size_t   len;

    words = ft_words(s, c);
    i = 0;
    cpt = 0;
    if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
    {
        printf("tab = NULL\n");
        return (NULL);
    }
    return (tab);
}