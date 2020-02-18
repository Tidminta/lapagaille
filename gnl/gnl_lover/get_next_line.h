/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:15:28 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/17 18:11:29 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>//

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);

char			*ft_strchr(char *s, int c);

char			*ft_strjoin(char *s1, char *s2);

char			*ft_strdup(char *s1);

int				ft_strlen(char *str);

void			ft_putstr(char *str);

char			*ft_substr(char *s, int start, int len);

void			ft_putstr(char *str);

int				ft_strlen(char *str);

void			ft_bzero(void *s, size_t n);

char			*ft_where_is_nl(char *s);

void			ft_check_params(int fd, char **line, char **buff, char **str);

#endif