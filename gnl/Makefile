# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 00:09:25 by tidminta          #+#    #+#              #
#    Updated: 2020/01/23 20:17:07 by tidminta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

CC  = gcc

RM	= rm -f

OBJ =	get_next_line.c /
		get_next_line_utils.c 

OBJ_OBJS	=	$(OBJ:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror 

LIB			= libft.h

%.o : %.c
	$(CC) $(CFLAGS) -I. -o $@ -c $< 


$(NAME): $(OBJ_OBJS) $(LIB) Makefile
			ar rc $(NAME) $(OBJ_OBJS)
			ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	clean fclean all re
