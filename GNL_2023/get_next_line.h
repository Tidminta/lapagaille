/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidiane <tidiane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:05:51 by tidiane           #+#    #+#             */
/*   Updated: 2023/02/09 01:52:47 by tidiane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
# endif

//for test purpose
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

//legit include
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char    *ft_strdup(char *str);
char    *ft_substr(char *s, int start, int len);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char *s1, char *s2);
size_t  ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char    *read_line(char *stat, int fd);
char    *refactor_line(char *stat);
char    *read_line(char *stat, int fd);


#endif