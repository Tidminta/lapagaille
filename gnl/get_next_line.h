/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:15:28 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/08 19:43:45 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

# include <stdio.h>//

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);

char			*ft_strchr(const char *s, int c);

char			*ft_strjoin(char *s1, char *s2);

char		*ft_strdup(char *s1);

int				ft_strlen(char *str);

void			ft_putstr(char *str);

char		*ft_substr(char *s, int start, int len);

void			ft_putstr(char *str);

int				ft_strlen(char *str);

void			ft_bzero(void *s, size_t n);

char			*ft_strchr(const char *s, int c);

int				ft_where_is_nl(char *str);

#endif
