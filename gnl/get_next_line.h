/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:15:28 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/03 21:40:20 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000000

# include <stdio.h>//

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);
void			ft_putstr(char *str);
size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strjoin(char *s1, char *s2);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
